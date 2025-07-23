#include "lib.h"

int16_t rxbuf = 0, cx = 160;
int16_t baseSpeed = 15;
int16_t SpeedL = 0, SpeedR = 0;
float Kp = 0.5;
uint32_t compareValue = 0;

void Motor_On(void)
{
    DL_GPIO_setPins(GPIO_MOTOR_PIN_FSTBY_PORT, GPIO_MOTOR_PIN_FSTBY_PIN);
    DL_GPIO_setPins(GPIO_MOTOR_PIN_BSTBY_PORT, GPIO_MOTOR_PIN_BSTBY_PIN);
}

void Motor_Off(void)
{
    DL_GPIO_clearPins(GPIO_MOTOR_PIN_FSTBY_PORT, GPIO_MOTOR_PIN_FSTBY_PIN);
    DL_GPIO_clearPins(GPIO_MOTOR_PIN_BSTBY_PORT, GPIO_MOTOR_PIN_BSTBY_PIN);

    DL_GPIO_clearPins(GPIO_MOTOR_PIN_FL1_PORT, GPIO_MOTOR_PIN_FL1_PIN);
    DL_GPIO_clearPins(GPIO_MOTOR_PIN_FL2_PORT, GPIO_MOTOR_PIN_FL2_PIN);
    DL_GPIO_clearPins(GPIO_MOTOR_PIN_FR1_PORT, GPIO_MOTOR_PIN_FR1_PIN);
    DL_GPIO_clearPins(GPIO_MOTOR_PIN_FR2_PORT, GPIO_MOTOR_PIN_FR2_PIN);

    DL_GPIO_clearPins(GPIO_MOTOR_PIN_BL1_PORT, GPIO_MOTOR_PIN_BL1_PIN);
    DL_GPIO_clearPins(GPIO_MOTOR_PIN_BL2_PORT, GPIO_MOTOR_PIN_BL2_PIN);
    DL_GPIO_clearPins(GPIO_MOTOR_PIN_BR1_PORT, GPIO_MOTOR_PIN_BR1_PIN);
    DL_GPIO_clearPins(GPIO_MOTOR_PIN_BR2_PORT, GPIO_MOTOR_PIN_BR2_PIN);
}

void Set_Speed(enum Wheel wheel, int8_t duty)
{
    
    if(wheel == Wheel_FL)
    {
        if(duty < 0)
        {
            compareValue = 3199 - 3199 * (-duty/100.0);
            DL_TimerA_setCaptureCompareValue(PWM_MOTOR_INST, compareValue, DL_TIMER_CC_0_INDEX);
            DL_GPIO_clearPins(GPIO_MOTOR_PIN_FL1_PORT, GPIO_MOTOR_PIN_FL1_PIN);
            DL_GPIO_setPins(GPIO_MOTOR_PIN_FL2_PORT, GPIO_MOTOR_PIN_FL2_PIN);
            // PID_FL.Target=duty;
        }
        else if(duty > 0)
        {
            compareValue = 3199 - 3199 * (duty/100.0);
            DL_TimerA_setCaptureCompareValue(PWM_MOTOR_INST, compareValue, DL_TIMER_CC_0_INDEX);
            DL_GPIO_setPins(GPIO_MOTOR_PIN_FL1_PORT, GPIO_MOTOR_PIN_FL1_PIN);
            DL_GPIO_clearPins(GPIO_MOTOR_PIN_FL2_PORT, GPIO_MOTOR_PIN_FL2_PIN);
            // PID_FL.Target=duty;
        }
        else 
        {
            DL_GPIO_clearPins(GPIO_MOTOR_PIN_FL1_PORT, GPIO_MOTOR_PIN_FL1_PIN);
            DL_GPIO_clearPins(GPIO_MOTOR_PIN_FL2_PORT, GPIO_MOTOR_PIN_FL2_PIN);
        }
        // PID_Update_FL(&PID_FL);
    }

    if(wheel == Wheel_BL)
    {
        if(duty < 0)
        {
            compareValue = 3199 - 3199 * (-duty/100.0);
            DL_TimerA_setCaptureCompareValue(PWM_MOTOR_INST, compareValue, DL_TIMER_CC_1_INDEX);
            DL_GPIO_clearPins(GPIO_MOTOR_PIN_BL1_PORT, GPIO_MOTOR_PIN_BL1_PIN);
            DL_GPIO_setPins(GPIO_MOTOR_PIN_BL2_PORT, GPIO_MOTOR_PIN_BL2_PIN);
            // PID_FR.Target=duty; 
        }
        else if(duty > 0)
        {
            compareValue = 3199 - 3199 * (duty/100.0);
            DL_TimerA_setCaptureCompareValue(PWM_MOTOR_INST, compareValue, DL_TIMER_CC_1_INDEX);
            DL_GPIO_setPins(GPIO_MOTOR_PIN_BL1_PORT, GPIO_MOTOR_PIN_BL1_PIN);
            DL_GPIO_clearPins(GPIO_MOTOR_PIN_BL2_PORT, GPIO_MOTOR_PIN_BL2_PIN);
            // PID_FR.Target=duty;
        }
        else 
        {
            DL_GPIO_clearPins(GPIO_MOTOR_PIN_BL1_PORT, GPIO_MOTOR_PIN_BL1_PIN);
            DL_GPIO_clearPins(GPIO_MOTOR_PIN_BL2_PORT, GPIO_MOTOR_PIN_BL2_PIN);
        }
        // PID_Update_BL(&PID_BL);

    }
    
    if(wheel==Wheel_FR)
    {
        if(duty < 0)
        {
            compareValue = 3199 - 3199 * (-duty/100.0);
            DL_TimerA_setCaptureCompareValue(PWM_MOTOR_INST, compareValue, DL_TIMER_CC_2_INDEX);
            DL_GPIO_setPins(GPIO_MOTOR_PIN_FR1_PORT, GPIO_MOTOR_PIN_FR1_PIN);
            DL_GPIO_clearPins(GPIO_MOTOR_PIN_FR2_PORT, GPIO_MOTOR_PIN_FR2_PIN);
            // PID_BL.Target=duty;
        }
        else if(duty > 0)
        {
            compareValue = 3199 - 3199 * (duty/100.0);
            DL_TimerA_setCaptureCompareValue(PWM_MOTOR_INST, compareValue, DL_TIMER_CC_2_INDEX);
            DL_GPIO_clearPins(GPIO_MOTOR_PIN_FR1_PORT, GPIO_MOTOR_PIN_FR1_PIN);
            DL_GPIO_setPins(GPIO_MOTOR_PIN_FR2_PORT, GPIO_MOTOR_PIN_FR2_PIN);
            // PID_BL.Target=duty;
            
           
        }
        else 
        {
            DL_GPIO_clearPins(GPIO_MOTOR_PIN_FR1_PORT, GPIO_MOTOR_PIN_FR1_PIN);
            DL_GPIO_clearPins(GPIO_MOTOR_PIN_FR2_PORT, GPIO_MOTOR_PIN_FR2_PIN);
        }
        // PID_Update_FR(&PID_FR);
    }

    if(wheel==Wheel_BR)
    {
        if(duty < 0)
        {
            compareValue = 3199 - 3199 * (-duty/100.0);
            DL_TimerA_setCaptureCompareValue(PWM_MOTOR_INST, compareValue, DL_TIMER_CC_3_INDEX);
            DL_GPIO_setPins(GPIO_MOTOR_PIN_BR1_PORT, GPIO_MOTOR_PIN_BR1_PIN);
            DL_GPIO_clearPins(GPIO_MOTOR_PIN_BR2_PORT, GPIO_MOTOR_PIN_BR2_PIN);
            // PID_BR.Target=duty;
        }
        else if(duty > 0)
        {
            compareValue = 3199 - 3199 * (duty/100.0);
            DL_TimerA_setCaptureCompareValue(PWM_MOTOR_INST, compareValue, DL_TIMER_CC_3_INDEX);
            DL_GPIO_clearPins(GPIO_MOTOR_PIN_BR1_PORT, GPIO_MOTOR_PIN_BR1_PIN);
            DL_GPIO_setPins(GPIO_MOTOR_PIN_BR2_PORT, GPIO_MOTOR_PIN_BR2_PIN);
            // PID_BR.Target=duty;
        }
        else 
        {
            DL_GPIO_clearPins(GPIO_MOTOR_PIN_BR1_PORT, GPIO_MOTOR_PIN_BR1_PIN);
            DL_GPIO_clearPins(GPIO_MOTOR_PIN_BR2_PORT, GPIO_MOTOR_PIN_BR2_PIN);
        }
        // PID_Update_BR(&PID_BR);
    }
}

void Go_stright(int duty)
{
    Set_Speed(Wheel_FL,duty);
    PID_SetTaget(&PID_FL,duty);
    Set_Speed(Wheel_FR,duty);
    PID_SetTaget(&PID_FR,duty);
    Set_Speed(Wheel_BL,duty);
    PID_SetTaget(&PID_BL,duty);
    Set_Speed(Wheel_BR,duty);
    PID_SetTaget(&PID_BR,duty);
}

void Go_turnLeft(int Centre_duty,int ChaZhi)
{
    Set_Speed(Wheel_FL,Centre_duty-ChaZhi);
    Set_Speed(Wheel_FR,Centre_duty+ChaZhi);
    Set_Speed(Wheel_BL,Centre_duty-ChaZhi);
    Set_Speed(Wheel_BR,Centre_duty+ChaZhi);
    PID_SetTaget(&PID_FL,Centre_duty-ChaZhi);
    PID_SetTaget(&PID_FR,Centre_duty+ChaZhi);
    PID_SetTaget(&PID_BL,Centre_duty-ChaZhi);
    PID_SetTaget(&PID_BR,Centre_duty+ChaZhi);
}

void Go_turnRight(int Centre_duty,int ChaZhi)
{
    Set_Speed(Wheel_FL,Centre_duty+ChaZhi);
    Set_Speed(Wheel_FR,Centre_duty-ChaZhi);
    Set_Speed(Wheel_BL,Centre_duty+ChaZhi);
    Set_Speed(Wheel_BR,Centre_duty-ChaZhi);
    PID_SetTaget(&PID_FL,Centre_duty+ChaZhi);
    PID_SetTaget(&PID_FR,Centre_duty-ChaZhi);
    PID_SetTaget(&PID_BL,Centre_duty+ChaZhi);
    PID_SetTaget(&PID_BR,Centre_duty-ChaZhi);
}

// void Go_PIDYaw_turnRight(int duty)
// {
//     Set_Speed(Wheel_FL,duty);
//     Set_Speed(Wheel_BL,duty);
//     Set_Speed(Wheel_FR,-duty);
//     Set_Speed(Wheel_BR,-duty);
// }

// void Go_PIDYaw_turnLeft(int duty)
// {
//     Set_Speed(Wheel_FL,-duty);
//     Set_Speed(Wheel_BL,-duty);
//     Set_Speed(Wheel_FR,duty);
//     Set_Speed(Wheel_BR,duty);
// }

// void Go_OPENMV(struct OPENMV_Data* openmv,int Centre_duty,int ChaZhi)
// {
//     int DuiChen_data=openmv->data1+openmv->data2-openmv->data4-openmv->data5;
//     if(openmv->data3==1&&DuiChen_data==0)
//     {
//         Go_stright(Centre_duty);
//     }
//     else if(DuiChen_data>0)
//     {
//         Go_turnLeft(Centre_duty,ChaZhi);
//     }
//     else if(DuiChen_data<0)
//     {
//         Go_turnRight(Centre_duty,ChaZhi);
//     }
//     else
//     {
//         Motor_Off();
//     }
// }

void Motor_Ctrl(void)
{

}