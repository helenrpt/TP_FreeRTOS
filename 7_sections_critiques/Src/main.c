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
#include "semphr.h"


#define LOW		(1u)
#define MEDIUM	(2u)
#define HIGH	(3u)

TaskHandle_t Task1_Handle;
TaskHandle_t Task2_Handle;
TaskHandle_t Task3_Handle;

SemaphoreHandle_t xSemaphore = NULL;

void Task1_Handler(void *pvParameters){

TickType_t xLastWakeTime1;
xLastWakeTime1 = xTaskGetTickCount();

for (;;){
		//taskENTER_CRITICAL();
		xSemaphoreTake(xSemaphore, portMAX_DELAY );

		printf("%s","Hello from Task1\r\n");

		xSemaphoreGive( xSemaphore );
		//taskEXIT_CRITICAL();
		vTaskDelayUntil(&xLastWakeTime1,50);


	}
}

void Task2_Handler(void *pvParameters){
TickType_t xLastWakeTime2;
xLastWakeTime2 = xTaskGetTickCount();
for (;;){
		//taskENTER_CRITICAL();
		xSemaphoreTake(xSemaphore, portMAX_DELAY);

		printf("%s","Hello from Task2\r\n");
		vTaskDelay(50);
		xSemaphoreGive( xSemaphore );

		vTaskDelayUntil(&xLastWakeTime2,50);

		//taskEXIT_CRITICAL();


	}
}

void Task3_Handler(void *pvParameters){
TickType_t xLastWakeTime3;
xLastWakeTime3 = xTaskGetTickCount();
for (;;){

		xSemaphoreTake(xSemaphore, portMAX_DELAY);

		printf("%s","Hello from Task3\r\n");
		xSemaphoreGive( xSemaphore );

		vTaskDelayUntil(&xLastWakeTime3,50);




	}
}



int growStack(void){
	printf("Appel growStack\r\n");
	vTaskDelay(5);
	return growStack();

}

void vApplicationIdleHook( void ){
	//printf("Entering sleep mode \r\n");
	__WFI();
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
	
	//xSemaphore =xSemaphoreCreateBinary();
	xSemaphore = xSemaphoreCreateMutex();
	xSemaphoreGive( xSemaphore );

	// xTaskCreate(fonction, nom, taille_pile_en_mots, paramètre de la tache, priorité, handle)
	// Taille pile: 256 mots = 1024 octets
	// Priorité: 0 = plus basse, nombre plus élevé = priorité plus haute

	xTaskCreate(Task1_Handler,"Task1", 256,NULL,LOW,&Task1_Handle);
	xTaskCreate(Task2_Handler,"Task2", 256,NULL,MEDIUM,&Task2_Handle);
	xTaskCreate(Task3_Handler,"Task3", 256,NULL,HIGH,&Task3_Handle);
	
	vTaskStartScheduler();  // Démarrer le scheduler FreeRTOS
	

	while(1){
	}
}



