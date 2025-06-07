#ifndef __MOTOR_H
#define __MOTOR_H

#include "UART.h"
// #define DL_TIMER_CC_0_INDEX PWM_FL
// #define DL_TIMER_CC_1_INDEX PWM_BL
// #define DL_TIMER_CC_2_INDEX PWM_FR
// #define DL_TIMER_CC_3_INDEX PWM_BR
void Motor_On(void);
void Motor_Off(void);
void Set_Speed(uint8_t side, int8_t duty);
extern int16_t rxbuf , cx ;
extern int16_t baseSpeed ;
extern int16_t SpeedL , SpeedR ;
extern float Kp ;
enum Wheel 
{
    Wheel_FL=0,
    Wheel_FR,
    Wheel_BL,
    Wheel_BR,
};
void Go_stright(int duty);
void Go_turnLeft(int Centre_duty,int ChaZhi);
void Go_turnRight(int Centre_duty,int ChaZhi);
void Go_PIDYaw_turnRight(int duty);
void Go_PIDYaw_turnLeft(int duty);
void Go_OPENMV(struct OPENMV_Data* openmv,int Centre_duty,int ChaZhi);
void Motor_Ctrl(void);

#endif
