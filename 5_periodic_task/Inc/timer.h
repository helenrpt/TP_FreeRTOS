

#ifndef TIMER_H_
#define TIMER_H_

void TIM2TICK_Init(void);
void TIM2TICK_Delay(uint32_t Delay);
uint32_t TIM2TICK_Get(void);

/*void SYSTICK_Init(void);
void SYSTICK_Delay(uint32_t Delay);
uint32_t SYSTICK_Get(void);*/


void DWT_Init(void);
void DWT_Delay(uint32_t _us);

#endif
