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
	while(1){
		vTaskDelay(50);
		GPIOA->ODR ^= 1<<5;
		//printf("Hello\r\n");
	}
}

void Task2_Handler(void *pvParameters){
	while(1){
		vTaskDelay(10);

		//Déclaration d'un canal pour écrire
		//traceString uart2Event;

		//Initialisation d'un canal
		//uart2Event = xTraceRegisterString("UART2");

		vTracePrint(uart2Event, "Start UART Transmit");

		printf("Hello\r\n");

		vTracePrintF(uart2Event,"END");

	}
}


int main(void)
{
	FPU_Init();
	GPIO_Init();
	USART2_Init();
	TIM2TICK_Init();



	//vTracePrint(uart2Event, "Start UART Transmit");
	//vTracePrintF(uart2Event,"i=%d", nombre);

	//Déclaration d'un canal pour écrire
	traceString uart2Event;

	//Initialisation d'un canal
	uart2Event = xTraceRegisterString("UART2");

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



