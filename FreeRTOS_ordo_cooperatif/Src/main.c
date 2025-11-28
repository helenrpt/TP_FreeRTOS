#include <stdint.h>
#include <stm32f446xx.h>
#include <stdio.h>
#include "main.h"
#include "gpio.h"
#include "usart.h"
#include "timer.h"
#include "util.h"
#include "FreeRTOS.h"
#include "task.h"

TaskHandle_t Task1_Handle;
TaskHandle_t Task2_Handle;

void Task1_Handler(void *pvParameters){
	//Déclaration d'un canal pour écrire
	traceString uart2Event;

	//Initialisation d'un canal
	uart2Event = xTraceRegisterString("UART2");
	for (;;){
		vTracePrint(uart2Event, "Task 1 : Start UART Transmit");
		printf("Hello from Task111111111111111111111111111111\r\n");
		vTracePrintF(uart2Event,"Task 1 : END UART Transmit");
		vTaskDelay(10);
	}
}

void Task2_Handler(void *pvParameters){
	//Déclaration d'un canal pour écrire
	traceString uart2Event;

	//Initialisation d'un canal
	uart2Event = xTraceRegisterString("UART2");
	for (;;){
		vTracePrint(uart2Event, "Task 2 : Start UART Transmit");
		printf("Hello from Task2222222222222222222222222222222\r\n");
		vTracePrintF(uart2Event,"Task 2 : END UART Transmit");
		vTaskDelay(10);
	}
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
	xTaskCreate(Task2_Handler,"Task2", 256,NULL,2,&Task2_Handle);

	
	vTaskStartScheduler();  // Démarrer le scheduler FreeRTOS
	

	while(1){
	}
}



