#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "Key.h"
#include "LED.h"
#include "PWM.h"

uint8_t i; 

int main(void)
{
	Key_Init();
	//LED_Init();
	PWM_Init();
	
	/*RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);*/
	GPIO_SetBits(GPIOC,GPIO_Pin_13);
	while (1)
	{  
	
		for (i = 0; i <= 100; i+=Speed_Get())
		{
			PWM_SetCompare1(i);
			Delay_ms(15);
		}
		for (i = 0; i <= 100; i+=Speed_Get())
		{
			PWM_SetCompare1(100 - i);
			Delay_ms(15);
		}
	}
}
