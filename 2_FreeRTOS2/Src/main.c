#include <stdint.h>
#include <stm32f446xx.h>
#include <stdio.h>
#include "main.h"
#include "gpio.h"
#include "usart.h"
#include "timer.h"
#include "util.h"
#include "FreeRTOSConfig.h"


int main(void)
{
	FPU_Init();
	GPIO_Init();
	USART2_Init();
	TIM2TICK_Init();


	while(1){
		//SYSTICK_Delay(1000);

		TIM2TICK_Delay(1000);
		GPIOA->ODR ^= 1<<5;
		printf("Hello\r\n");
	}
}
