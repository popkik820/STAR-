#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "Key.h"
#include "Servo.h"
#include "PWM.h"
#include "Serial.h"

uint8_t Angle;

int main(void)
{
	//Key_Init();
	PWM_Init();
	Servo_Init();
	Serial_Init();
	
	//GPIO_SetBits(GPIOC,GPIO_Pin_13);
	//TIM_SetCompare1(TIM2,2300);
	
	while (1)
	{  
		if (Serial_GetRxFlag() == 1)
		{
			Angle = Serial_GetRxData();
			Serial_SendByte(Angle);
		}
		Angle_Set(Angle);
	}
}
