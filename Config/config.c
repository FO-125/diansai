#include "config.h"
#include "../Driver/drv_encoder.h"
#include "GPIO.h"
int g_Start_Count=0;

void GROUP1_IRQHandler(void)
{
    // 获取编码器设备
    struct Dev_Encoder *encoder_fl = GetEncoder("encoder_FL");  // 前左编码器
    struct Dev_Encoder *encoder_fr = GetEncoder("encoder_FR");  // 前右编码器
    struct Dev_Encoder *encoder_bl = GetEncoder("encoder_BL");  // 后左编码器
    struct Dev_Encoder *encoder_br = GetEncoder("encoder_BR");  // 后右编码器
    uint32_t gpioB = DL_GPIO_getEnabledInterruptStatus(GPIOB, encoder_fl->get_Apin(encoder_fl)| encoder_fr->get_Apin(encoder_fr)|GPIO_Button_PIN_0_PIN|encoder_bl->get_Apin(encoder_bl) | encoder_br->get_Apin(encoder_br));
    if (gpioB & encoder_fl->get_Apin(encoder_fl)) 
    {
        if (encoder_fl) {
            encoder_fl->read_value(encoder_fl);
        }
        GPIO_CLEARInterruptStatus(GPIO_MOTOR_QEI_PIN_FL_A_PORT, GPIO_MOTOR_QEI_PIN_FL_A_PIN);
    }

    if (gpioB & encoder_fr->get_Apin(encoder_fr)) 
    {
        if (encoder_fr) {
            encoder_fr->read_value(encoder_fr);
        }
        GPIO_CLEARInterruptStatus(GPIO_MOTOR_QEI_PIN_FR_A_PORT, GPIO_MOTOR_QEI_PIN_FR_A_PIN);
    }
    
    if (gpioB & encoder_bl->get_Apin(encoder_bl)) 
    {
        if (encoder_bl) {
            encoder_bl->read_value(encoder_bl);
        }
        GPIO_CLEARInterruptStatus(GPIO_MOTOR_QEI_PIN_BL_A_PORT, GPIO_MOTOR_QEI_PIN_BL_A_PIN);
    }

    if (gpioB & encoder_br->get_Apin(encoder_br)) 
    {
        if (encoder_br) {
            encoder_br->read_value(encoder_br);
        }
        GPIO_CLEARInterruptStatus(GPIO_MOTOR_QEI_PIN_BR_A_PORT, GPIO_MOTOR_QEI_PIN_BR_A_PIN);
    }
    
    if (gpioB & GPIO_Button_PIN_0_PIN)
    {
        g_Start_Count++;
        //YawInit(wit_data.yaw);
        GPIO_CLEARInterruptStatus(GPIOB, GPIO_Button_PIN_0_PIN);
    }
    
    switch (DL_Interrupt_getPendingGroup(DL_INTERRUPT_GROUP_1)) 
    {
        case GPIO_IMU660RB_PIN_IMU660RB_INT1_IIDX:
                //Read_IMU660RB();
                break;    
    }
}




