#include <stdint.h>
#include <stm32f446xx.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "gpio.h"
#include "usart.h"
#include "timer.h"
#include "util.h"
#include "FreeRTOS.h"
#include "task.h"

#define LOW		(1u)
#define MEDIUM	(2u)
#define HIGH	(3u)

TaskHandle_t Task1_Handle;
TaskHandle_t Task2_Handle;
TaskHandle_t TzCtrl_Handle;

void Task1_Handler(void *pvParameters){

for (;;){

		printf("\r\n\r\n\r\n\r\n\r\nHello from Task1\r\n");
		vTaskDelay(5);
		growStack();


	}
}

void Task2_Handler(void *pvParameters){

for (;;){

		printf("\r\n\r\n\r\n\r\n\r\nHello from Task2\r\n");
		vTaskDelay(5);

	}
}


int growStack(void){
	printf("Appel growStack\r\n");
	vTaskDelay(5);
	return growStack();

}

void vApplicationIdleHook( void ){
	//printf("Entering sleep mode \r\n");
	//__WFI();
}


void vApplicationStackOverflowHook( TaskHandle_t xTask,
                                       char * pcTaskName ){
	printf("Stack Over Flow from %s \r\n", pcTaskName);
	vTaskDelay(5);
}

int main(void)
{
	FPU_Init();
	GPIO_Init();
	USART2_Init();
	TIM2TICK_Init();

	vTraceEnable(TRC_START);
	
	// xTaskCreate(fonction, nom, taille_pile_en_mots, paramètre de la tache, priorité, handle)
	// Taille pile: 256 mots = 1024 octets
	// Priorité: 0 = plus basse, nombre plus élevé = priorité plus haute

	xTaskCreate(Task1_Handler,"Task1", 256,NULL,2,&Task1_Handle);
	//xTaskCreate(Task2_Handler,"Task2", 256,NULL,2,&Task2_Handle);
	
	vTaskStartScheduler();  // Démarrer le scheduler FreeRTOS
	

	while(1){
	}
}



