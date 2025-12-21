#ifndef __TIMER_H
#define __TIMER_H

void PWM_Init(void);
void PWM_SetCompare1(uint16_t Compare);
void PWM_SetIC1Prescaler(uint16_t TIM_ICPSC);

#endif
