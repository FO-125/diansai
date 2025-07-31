#include "UART.h"
#include "XunJi.h"
#include "lib.h"
#include "motor.h"
#include "pid.h"
int Flag=0,i=0;
void Task1()
{
   
    XunJIPIDConcrol(6450);
    while(i++<Flag)
        XunJIPIDConcrol(6470);
           
   
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
    LED_init();
    Control_Beep(disable_Beep);
    Motor_On();
    // Set_Speed(Wheel_FL,20);
    // PID_SetTaget(&PID_FL,20);

    // PID_Init(&PID_Yaw,SinJiaoKP,SinJiaoKI,SinJiaoKD);
    // PID_SetTaget(&PID_Yaw, 0);
    
}
// volatile int PWMoutLeft = 0,PWMoutRight = 0;
//     volatile int PWMout = 0;
void TASK_LOOP()
{
    
    if(Start_Count > 0)
{
    Task1();       // 执行任务
    Start_Count = 0; // 执行后立即重置标志位，避免再次执行
}

    
    // printf("%f,%f,%f,%f\n", PID_FL.Target, PID_FL.Actual, PID_FL.Error,PID_FL.out);
 
}

