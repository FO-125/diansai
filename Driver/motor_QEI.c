#include "ti_msp_dl_config.h"
#include "pid.h"
#include "motor.h"
#include "UART.h"
#include "wit.h"
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
    uint32_t gpioA = DL_GPIO_getEnabledInterruptStatus(GPIOA, GPIO_MOTOR_QEI_PIN_FR_A_PIN | GPIO_MOTOR_QEI_PIN_BR_A_PIN);
    uint32_t gpioB = DL_GPIO_getEnabledInterruptStatus(GPIOB, GPIO_MOTOR_QEI_PIN_FL_A_PIN | GPIO_MOTOR_QEI_PIN_BL_A_PIN|GPIO_Button_PIN_0_PIN);
    if (gpioB & GPIO_MOTOR_QEI_PIN_FL_A_PIN) 
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

    if (gpioA & GPIO_MOTOR_QEI_PIN_FR_A_PIN) 
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
    
    if (gpioB & GPIO_MOTOR_QEI_PIN_BL_A_PIN) 
    {
        if(DL_GPIO_readPins(GPIO_MOTOR_QEI_PIN_BL_B_PORT, GPIO_MOTOR_QEI_PIN_BL_B_PIN))
        {   
            Back_Left_Count++;
            QBL++;
        }
        else if(DL_GPIO_readPins(GPIO_MOTOR_QEI_PIN_BL_B_PORT, GPIO_MOTOR_QEI_PIN_BL_B_PIN)==0)
        {    
            Back_Left_Count--;
            QBL--;
        }
        DL_GPIO_clearInterruptStatus(GPIO_MOTOR_QEI_PIN_BL_A_PORT, GPIO_MOTOR_QEI_PIN_BL_A_PIN);
    }

    if (gpioA & GPIO_MOTOR_QEI_PIN_BR_A_PIN) 
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