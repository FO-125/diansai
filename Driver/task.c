#include "UART.h"
#include "lib.h"
#include "motor.h"

void Task2()
{  
    My_Delay_MS(1000);
    ControlSinAngle(0,1000,AB);//小
    XunJIPIDConcrolTurn(1200);//距离滤波
    ControlSinAngle (0,1000,CD);
    XunJIPIDConcrolTurn(1200);//距离滤波
}

void Task3()
{
    My_Delay_MS(1200);
    ControlSinAngle(44,570,AC);//小
    // XunJIPIDConcrolTurn(750);//距离滤波
    // ControlSinAngle(140,420,BD);
    //  XunJIPIDConcrolTurn(700);
}


// void Task4()
// {
//     My_Delay_MS(1000);

//     ControlSinAngleA_B(-56,1400);//小      -- 55
//     XunJIPIDConcrolTurn(1600);//距离滤波
//      ControlSinAngleC_D(-55.8f,1400);//-37.42     -- 55
//      XunJIPIDConcrolTurn(1600);

//      ControlSinAngleA_B(-49.5,1400);//小     -- 51
//      XunJIPIDConcrolTurn(1600);
//      ControlSinAngleC_D(-54.8,1400);//-37.42   -- 56
//      XunJIPIDConcrolTurn(1600);

//     ControlSinAngleA_B(-48.9,1400);//小    -- 49.5
//     XunJIPIDConcrolTurn(1600);
//      ControlSinAngleC_D(-52.5,1400);//-53/52    -- 54.5
//      XunJIPIDConcrolTurn(1600);

//          ControlSinAngleA_B(-54.5,1400);//小    -- 53
//     XunJIPIDConcrolTurn(1600);
//      ControlSinAngleC_D(-53.5,1400);//-37.42    -- 54
//      XunJIPIDConcrolTurn(1600);


// }

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
    NVIC_INIT(GPIOA_INT_IRQn);
    NVIC_INIT(GPIOB_INT_IRQn);
    //Timer开启
    DL_Timer_startCounter(TIMER_MS_SYS_INST);
    //底层PID初始化
    PID_Init(&PID_FL,KP_FL,KI_FL,KD_FL);
    PID_Init(&PID_FR,KP_FR,KI_FR,KD_FR);
    PID_Init(&PID_BL,KP_BL,KI_BL,KD_BL);
    PID_Init(&PID_BR,KP_BR,KI_BR,KD_BR);
    
    Control_LED(disable_LED);
    // Control_Beep(disable_Beep);
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
        Task3();
    }
    // PWMout = PID_Update_Yaw(&PID_Yaw);//范围为20左右
    //                 //根据输出的PWM极性来判断需要左偏还是右偏
    //                 //偏右为+
    //                 //偏左为-
        
    //   PWMoutRight = CentrePWM + PWMout;
    //   PWMoutLeft = CentrePWM - PWMout;

    // if(PWMoutRight>=95)
    //     PWMoutRight=95;
    // else if(PWMoutRight<=-95)
    //     PWMoutRight=-95;
    //  if(PWMoutLeft>=95)
    //     PWMoutLeft=95;
    // else if(PWMoutLeft<=-95)
    //     PWMoutLeft=-95;

    //    //除了输出pwm还要根据pwm控制转向
    //    Set_Speed(Wheel_FL, PWMoutLeft);
    //    Set_Speed(Wheel_BL, PWMoutLeft);
    //    Set_Speed(Wheel_FR, PWMoutRight);
    //    Set_Speed(Wheel_BR, PWMoutRight);
    //    PID_SetTaget(&PID_FL,PWMoutLeft);
    //    PID_SetTaget(&PID_BL,PWMoutLeft);
    //    PID_SetTaget(&PID_FR,PWMoutRight);
    //    PID_SetTaget(&PID_BR,PWMoutRight);
    // printf("%f,%f,%f\n", wit_data.pitch, wit_data.roll, wit_data.yaw);
 
}

