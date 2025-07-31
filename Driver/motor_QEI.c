#include "Timer.h"
#include "ti_msp_dl_config.h"
#include "pid.h"
#include "motor.h"
#include "UART.h"
#include "wit.h"
#include "IMU660RB/imu660rb.h"
#include "task.h"
#include "LED.h"
volatile int32_t Front_Left_Count = 0;
volatile int32_t Front_Right_Count = 0;
volatile int32_t Back_Left_Count = 0;
volatile int32_t Back_Right_Count = 0;

volatile int32_t QFL = 0;
volatile int32_t QFR = 0;
volatile int32_t QBL = 0;
volatile int32_t QBR = 0;
volatile int32_t Average_count=0;
int Start_Count=0;

// void QEI_INIT(IRQn_Type GPIO_MOTOR_QEI_GPIOA_INT_IRQN)
// {
// NVIC_EnableIRQ(GPIO_MOTOR_QEI_GPIOA_INT_IRQN);
// }

int a=0;
void GROUP1_IRQHandler(void)
{
    uint32_t gpioA = DL_GPIO_getEnabledInterruptStatus(GPIOA, GPIO_MOTOR_QEI_PIN_FL_A_PIN | GPIO_MOTOR_QEI_PIN_BL_A_PIN|GPIO_Button_key1_PIN);
    uint32_t gpioB = DL_GPIO_getEnabledInterruptStatus(GPIOB, GPIO_MOTOR_QEI_PIN_FR_A_PIN | GPIO_MOTOR_QEI_PIN_BR_A_PIN|GPIO_Button_PIN_0_PIN|GPIO_Button_key3_PIN|GPIO_Button_key2_PIN|GPIO_Button_key4_PIN);
    if (gpioA & GPIO_MOTOR_QEI_PIN_FL_A_PIN) 
    {
        if(DL_GPIO_readPins(GPIO_MOTOR_QEI_PIN_FL_B_PORT, GPIO_MOTOR_QEI_PIN_FL_B_PIN))
        {
            Front_Left_Count--;
            QFL--;
        }
        else
        {
            Front_Left_Count++;
            QFL++;
        }
        DL_GPIO_clearInterruptStatus(GPIO_MOTOR_QEI_PIN_FL_A_PORT, GPIO_MOTOR_QEI_PIN_FL_A_PIN);
    }

    if (gpioB & GPIO_MOTOR_QEI_PIN_FR_A_PIN) 
    {
        if(DL_GPIO_readPins(GPIO_MOTOR_QEI_PIN_FR_B_PORT, GPIO_MOTOR_QEI_PIN_FR_B_PIN))
        {
            Front_Right_Count++;
            QFR++;
        }
        else 
        {
            Front_Right_Count--;
            QFR--;
        }
        DL_GPIO_clearInterruptStatus(GPIO_MOTOR_QEI_PIN_FR_A_PORT, GPIO_MOTOR_QEI_PIN_FR_A_PIN);
    }
    
    if (gpioA & GPIO_MOTOR_QEI_PIN_BL_A_PIN) 
    {
        if(DL_GPIO_readPins(GPIO_MOTOR_QEI_PIN_BL_B_PORT, GPIO_MOTOR_QEI_PIN_BL_B_PIN))
        {   
            
            Back_Left_Count--;
            QBL--;
        }
        else if(DL_GPIO_readPins(GPIO_MOTOR_QEI_PIN_BL_B_PORT, GPIO_MOTOR_QEI_PIN_BL_B_PIN)==0)
        {    
            Back_Left_Count++;
            QBL++;
        }
        DL_GPIO_clearInterruptStatus(GPIO_MOTOR_QEI_PIN_BL_A_PORT, GPIO_MOTOR_QEI_PIN_BL_A_PIN);
    }

    if (gpioB & GPIO_MOTOR_QEI_PIN_BR_A_PIN) 
    {
        if(DL_GPIO_readPins(GPIO_MOTOR_QEI_PIN_BR_B_PORT, GPIO_MOTOR_QEI_PIN_BR_B_PIN))
        {    
            Back_Right_Count++;
            QBR++;
        }
        else
        {    
            Back_Right_Count--;
            QBR--;
        }
        DL_GPIO_clearInterruptStatus(GPIO_MOTOR_QEI_PIN_BR_A_PORT, GPIO_MOTOR_QEI_PIN_BR_A_PIN);
    }
    if (gpioB & GPIO_Button_PIN_0_PIN)
    {
        Start_Count++;
        YawInit(wit_data.yaw);
        DL_GPIO_clearInterruptStatus(GPIOB, GPIO_Button_PIN_0_PIN);
    }
    if (gpioA & GPIO_Button_key1_PIN)
    {
        My_Delay_MS(1000);
        if(!DL_GPIO_readPins(GPIO_Button_key1_PORT, GPIO_Button_key1_PIN))
        {
            Flag=1;
            Control_LED(sparkle_LED2);
            DL_GPIO_clearInterruptStatus(GPIOA, GPIO_Button_key1_PIN);
            
        }
        
    } 
        
    if (gpioB & GPIO_Button_key2_PIN) 
    {
        My_Delay_MS(1000);
        if(!DL_GPIO_readPins(GPIO_Button_key2_PORT, GPIO_Button_key2_PIN))
        {
            Flag=2;
            Control_LED(sparkle_LED3);
            DL_GPIO_clearInterruptStatus(GPIOB, GPIO_Button_key2_PIN);
           
        }
    }

    if (gpioB & GPIO_Button_key3_PIN) 
    {
        My_Delay_MS(1000);
        if(!DL_GPIO_readPins(GPIO_Button_key3_PORT, GPIO_Button_key3_PIN))
        {
            Flag=3;
            Control_LED(sparkle_LED4);
            DL_GPIO_clearInterruptStatus(GPIOB, GPIO_Button_key3_PIN);
            
        }
    }

    if (gpioB & GPIO_Button_key4_PIN) 
    {
        My_Delay_MS(1000);
        if(!DL_GPIO_readPins(GPIO_Button_key4_PORT, GPIO_Button_key4_PIN))
        {
            Flag=4;
            Control_LED(sparkle_LED5);
            DL_GPIO_clearInterruptStatus(GPIOB, GPIO_Button_key4_PIN);
            
        }
    }
        
}

int Get_QEI_FL()
{
    int temp=Front_Left_Count;
    Front_Left_Count=0;
    return temp;
}

int Get_QEI_FR()
{
    int temp=Front_Right_Count;
    Front_Right_Count=0;
    return temp;
}

int Get_QEI_BL()
{
    int temp=Back_Left_Count;
    Back_Left_Count=0;
    return temp;
}

int Get_QEI_BR()
{
    int temp=Back_Right_Count;
    Back_Right_Count=0;
    return temp;
}