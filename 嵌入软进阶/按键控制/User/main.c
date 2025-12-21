#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "Key.h"
#include "LED.h"

int16_t Num;

int main(void)
{
	Key_Init();
	LED_Init();
	
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
