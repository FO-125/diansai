#include "UART.h"
#include "XunJi.h"
#include "lib.h"
#include "motor.h"
#include "pid.h"

void Task1()
{
    for(int j=0;j<5;j++)
    {
        for (int i = 0; i < 4; i++)
        {
            // 1. 沿直线行驶（使用八路灰度传感器PID控制）
            XunJIPIDConcrol(1000);
            
            // 2. 转弯90度（使用Yaw角PID控制）
            ControlSinAngle(90, 150, anticlockwise);
        }
    }
   
}






// ********************************************************************************************************************************************************************************************************************************************************************************************************************************
void TASK_INIT()
{
    SYSCFG_DL_init();
    //UART NVIC配置
    NVIC_ClearPendingIRQ(UART_OPENMV_INST_INT_IRQN);
    NVIC_INIT(UART_OPENMV_INST_INT_IRQN);
    // jy61p_Init();
    WIT_Init();
    //Timer NVIC配置
    NVIC_INIT(TIMER_MS_SYS_INST_INT_IRQN);
    //GPIO NVIC配置
    NVIC_EnableIRQ(1);
    //Timer开启
    DL_Timer_startCounter(TIMER_MS_SYS_INST);
    //底层PID初始化
    PID_Init_Wheel();
    
    Control_LED(disable_LED);
    Control_Beep(disable_Beep);
    Motor_On();
    Go_stright(0);

    // PID_Init(&PID_Yaw,SinJiaoKP,SinJiaoKI,SinJiaoKD);
    // PID_SetTaget(&PID_Yaw, 0);
    
}
// volatile int PWMoutLeft = 0,PWMoutRight = 0;
//     volatile int PWMout = 0;
void TASK_LOOP()
{
    
    if(Start_Count>0)
    {
        // XunJIPIDConcrol(1000);
        Set_Speed(Wheel_FR, 20);
        PID_SetTaget(&PID_FR,20);
    }
    
    // printf("%f,%f,%f\n", wit_data.pitch, wit_data.roll, wit_data.yaw);
 
}

