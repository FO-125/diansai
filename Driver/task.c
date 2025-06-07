#include "lib.h"
void Task2()
{  
    My_Delay_MS(500);
     
   
    ControlSinAngleA_B(0,1400);//小
     XunJIPIDConcrolTurn(1600);//距离滤波
     ControlSinAngleC_D (0,1400);
     XunJIPIDConcrolTurn(1400);//距离滤波
}

void Task3()
{
    My_Delay_MS(1000);
    ControlSinAngleA_B(-55,1400);//小
    XunJIPIDConcrolTurn(1600);//距离滤波
     ControlSinAngleC_D(-57.8f,1400);//-37.42
     XunJIPIDConcrolTurn(1600);
}


void Task4()
{
    My_Delay_MS(1000);

    ControlSinAngleA_B(-56,1400);//小      -- 55
    XunJIPIDConcrolTurn(1600);//距离滤波
     ControlSinAngleC_D(-55.8f,1400);//-37.42     -- 55
     XunJIPIDConcrolTurn(1600);

     ControlSinAngleA_B(-49.5,1400);//小     -- 51
     XunJIPIDConcrolTurn(1600);
     ControlSinAngleC_D(-54.8,1400);//-37.42   -- 56
     XunJIPIDConcrolTurn(1600);

    ControlSinAngleA_B(-48.9,1400);//小    -- 49.5
    XunJIPIDConcrolTurn(1600);
     ControlSinAngleC_D(-52.5,1400);//-53/52    -- 54.5
     XunJIPIDConcrolTurn(1600);

         ControlSinAngleA_B(-54.5,1400);//小    -- 53
    XunJIPIDConcrolTurn(1600);
     ControlSinAngleC_D(-53.5,1400);//-37.42    -- 54
     XunJIPIDConcrolTurn(1600);


}

// ********************************************************************************************************************************************************************************************************************************************************************************************************************************
void TASK_INIT()
{
    SYSCFG_DL_init();
    NVIC_ClearPendingIRQ(UART_OPENMV_INST_INT_IRQN);
    NVIC_ClearPendingIRQ(UART_TuoLuoYi_INST_INT_IRQN);
    //UART NVIC配置
    NVIC_INIT(UART_OPENMV_INST_INT_IRQN);
    NVIC_INIT(UART_TuoLuoYi_INST_INT_IRQN);
    //Timer NVIC配置
    NVIC_INIT(TIMER_MS_UART_INST_INT_IRQN);
    NVIC_INIT(TIMER_MS_SYS_INST_INT_IRQN);
    //GPIO NVIC配置
    NVIC_INIT(GPIO_MOTOR_QEI_GPIOA_INT_IRQN);
    NVIC_INIT(GPIO_MOTOR_QEI_GPIOB_INT_IRQN);
    //Timer开启
    DL_Timer_startCounter(TIMER_MS_SYS_INST);
    //底层PID初始化
    PID_Init(&PID_FL,KP_FL,KI_FL,KD_FL);
    PID_Init(&PID_FR,KP_FR,KI_FR,KD_FR);
    PID_Init(&PID_BL,KP_BL,KI_BL,KD_BL);
    PID_Init(&PID_BR,KP_BR,KI_BR,KD_BR);

    OLED_Init();

    Control_LED(disable_LED);
    Control_Beep(disable_Beep);
    Motor_On();
}

void TASK_LOOP()
{
    if(Start_Count>0)
    {
        Task2();
    }
    printf("%f/n",PID_FL.out);
    printf("%f/n",PID_FL.Target);
    Motor_Ctrl();
}

