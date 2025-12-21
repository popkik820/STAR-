#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "Key.h"
#include "Servo.h"
#include "PWM.h"

int main(void)
{
	Key_Init();
	PWM_Init();
	Servo_Init();
	
	GPIO_SetBits(GPIOC,GPIO_Pin_13);
	//TIM_SetCompare1(TIM2,2300);
	
	while (1)
	{  
		Angle_Set(Angle_Get());
	}
}
