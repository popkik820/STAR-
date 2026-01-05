#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "Key.h"
#include "LED.h"
#include "PWM.h"

int main(void)
{
	Key_Init();
	LED_Init();
	Timer_Init();
	
	/*RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);*/
	
	while (1)
	{
	}
}

void TIM2_IRQHandler(void) 
{
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)	
	{   
		if(Mode_Get()%3 == 0){
		LED_ON();
		Delay_ms(200);
		LED_OFF();
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);	}

		if(Mode_Get()%3 == 1){
		LED_ON();
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);	}

		if(Mode_Get()%3 == 2){
		LED_OFF();
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);	}
	}
}
