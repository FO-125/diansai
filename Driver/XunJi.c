#include "UART.h"
#include "lib.h"


int CentrePWM=60;
int YawPWMout=0;

void getGpioValue()
{
     uint32_t gpioA=DL_GPIO_readPins(GPIOA,GPIO_Xunji_PIN_8_PIN);
     uint32_t gpioB=DL_GPIO_readPins(GPIOB,GPIO_Xunji_PIN_1_PIN|GPIO_Xunji_PIN_2_PIN|GPIO_Xunji_PIN_3_PIN|GPIO_Xunji_PIN_4_PIN|GPIO_Xunji_PIN_5_PIN|GPIO_Xunji_PIN_6_PIN|GPIO_Xunji_PIN_7_PIN);
    if ((gpioB & GPIO_Xunji_PIN_1_PIN) != 0) // 高电平
        Xunji.X1 =1;
    else
        Xunji.X1 =0;
    if ((gpioB & GPIO_Xunji_PIN_2_PIN) != 0) // 高电平
        Xunji.X2 =1;
    else
        Xunji.X2 =0;
    if ((gpioB & GPIO_Xunji_PIN_3_PIN) != 0) // 高电平
        Xunji.X3 =1;
    else
        Xunji.X3 =0;
    if ((gpioB & GPIO_Xunji_PIN_4_PIN) != 0) // 高电平
        Xunji.X4 =1;
    else
        Xunji.X4 =0;
    if ((gpioB & GPIO_Xunji_PIN_5_PIN) != 0) // 高电平
        Xunji.X5 =1;
    else
        Xunji.X5 =0;
    if ((gpioB & GPIO_Xunji_PIN_6_PIN) != 0) // 高电平
        Xunji.X6 =1;
    else
        Xunji.X6 =0;
    if ((gpioB & GPIO_Xunji_PIN_7_PIN) != 0) // 高电平
        Xunji.X7 =1;
    else
        Xunji.X7 =0;
    if ((gpioA & GPIO_Xunji_PIN_8_PIN) != 0) // 高电平
        Xunji.X8 =1;
    else
        Xunji.X8 =0;
}


void ClearXunValue()
{
    Xunji.X1 = 0;
    Xunji.X2 = 0;
    Xunji.X3 = 0;
    Xunji.X4 = 0;
    Xunji.X5 = 0;
    Xunji.X6 = 0;
    Xunji.X7 = 0;
    Xunji.X8 = 0;
}

void Xunji_Data_Run()
{
    ClearXunValue();
    getGpioValue();
}

int GetXunJIErr(void)
{
    int data=3*Xunji.X1+2*Xunji.X2+1.5*Xunji.X3+Xunji.X4-Xunji.X5-1.5*Xunji.X6-2*Xunji.X7-3*Xunji.X8;
    return data;
}

void XunJIPIDConcrolTurn(uint16_t EncoderNumber)
{
    int StopFlag = 0;
    volatile int PWMoutLeft = 0,PWMoutRight = 0;
    volatile int PWMout = 0;
    PID_Init(&PID_Turn,XunJi_KP,XunJi_KI,XunJi_KD);
    Average_count = 0;
    QFL = 0;
    QFR = 0;
    while(1)
    {
 
      PWMout = PID_Update_Xunji(&PID_Turn);
                    //根据输出的PWM极性来判断需要左偏还是右偏
                    //偏右为+
                    //偏左为-
        // OLED_ShowNum(1,4,PWMout,5,8);
      PWMoutRight = CentrePWM - PWMout;
      PWMoutLeft = CentrePWM + PWMout;

    if(PWMoutRight>=95)
        PWMoutRight=95;
    else if(PWMoutRight<=-95)
        PWMoutRight=-95;
     if(PWMoutLeft>=95)
        PWMoutLeft=95;
    else if(PWMoutLeft<=-95)
        PWMoutLeft=-95;

       //除了输出pwm还要根据pwm控制转向
       Set_Speed(Wheel_FL, PWMoutLeft);
       Set_Speed(Wheel_BL, PWMoutLeft);
       Set_Speed(Wheel_FR, PWMoutRight);
       Set_Speed(Wheel_BR, PWMoutRight);
       PID_SetTaget(&PID_FL,PWMoutLeft);
        PID_SetTaget(&PID_BL,PWMoutLeft);
        PID_SetTaget(&PID_FR,PWMoutRight);
        PID_SetTaget(&PID_BR,PWMoutRight);
      Average_count = (QFL+QFR)/2;//等到一定距离后再进行寻迹是否到达的判定
    if(Average_count >= EncoderNumber)//寻迹路程判定退出pid寻迹//每个弧线的距离大约为1160个脉冲
     {
        // StopFlag = Xunji.X1+Xunji.X2+Xunji.X3+Xunji.X4+Xunji.X5+Xunji.X6+Xunji.X7+Xunji.X8;
        if( StopFlag == 0)
        {
            // Control_Beep(enable_Beep);
            Average_count = 0;
            QFL = 0;
            QFR = 0;
            Set_Speed(Wheel_FL, 0);
            Set_Speed(Wheel_BL, 0);
            Set_Speed(Wheel_FR, 0);
            Set_Speed(Wheel_BR, 0);
            PID_SetTaget(&PID_FL,0);
            PID_SetTaget(&PID_BL,0);
            PID_SetTaget(&PID_FR,0);
            PID_SetTaget(&PID_BR,0);
            //声光提醒  
            My_Delay_MS(100);
            // Control_Beep(disable_Beep);
            return ;
        }

     }
    }
}

void ControlSinAngleA_B(float targetAngle,uint16_t EncoderNumber)
{
    int PWMoutLeft = 0,PWMoutRight = 0;
    int StopFlag = 0;
   // OLED_Clear();
    PID_Init(&PID_Yaw,SinJiaoKP,SinJiaoKI,SinJiaoKD);
    PID_SetTaget(&PID_Yaw, targetAngle);

    Average_count = 0;
    QFL = 0;
    QFR = 0;
    while(1)
    {
        
      PWMoutRight = CentrePWM + YawPWMout;
      PWMoutLeft = CentrePWM - YawPWMout;

    if(PWMoutRight>=95)
        PWMoutRight=95;
    else if(PWMoutRight<=-95)
        PWMoutRight=-95;
     if(PWMoutLeft>=95)
        PWMoutLeft=95;
    else if(PWMoutLeft<=-95)
        PWMoutLeft=-95;

       //除了输出pwm还要根据pwm控制转向
       Set_Speed(Wheel_FL, PWMoutLeft);
       Set_Speed(Wheel_BL, PWMoutLeft);
       Set_Speed(Wheel_FR, PWMoutRight);
       Set_Speed(Wheel_BR, PWMoutRight);
       PID_SetTaget(&PID_FL,PWMoutLeft);
       PID_SetTaget(&PID_BL,PWMoutLeft);
       PID_SetTaget(&PID_FR,PWMoutRight);
       PID_SetTaget(&PID_BR,PWMoutRight);
    //    OLED_ShowNum(0,0,(int)QYaw,4,8);
      Average_count = (QFL+QFR)/2;//等到一定距离后再进行寻迹是否到达的判定
    if(Average_count >= EncoderNumber)//寻迹路程判定退出pid寻迹//每个弧线的距离大约为1160个脉冲
     {
        // StopFlag = Xunji.X1+Xunji.X2+Xunji.X3+Xunji.X4+Xunji.X5+Xunji.X6+Xunji.X7+Xunji.X8;
        // if( StopFlag == 0)
        // {
            // Control_Beep(enable_Beep);
            Average_count = 0;
            QFL = 0;
            QFR = 0;
            Set_Speed(Wheel_FL, 0);
            Set_Speed(Wheel_BL, 0);
            Set_Speed(Wheel_FR, 0);
            Set_Speed(Wheel_BR, 0);
            PID_SetTaget(&PID_FL,0);
            PID_SetTaget(&PID_BL,0);
            PID_SetTaget(&PID_FR,0);
            PID_SetTaget(&PID_BR,0);
            //声光提醒  
            My_Delay_MS(100);
            // Control_Beep(disable_Beep);
            return ;
        // }

     }
    }
}

    int PWMoutLeft = 0,PWMoutRight = 0;  
void ControlSinAngleC_D(float targetAngle,uint16_t EncoderNumber)
{
    int StopFlag = 0;
  
    volatile int PWMout = 0;
    // OLED_Clear();
    PID_Init(&PID_Yaw,SinJiaoKPC_D,SinJiaoKIC_D,SinJiaoKDC_D);
    PID_SetTaget(&PID_Yaw, targetAngle);
    Average_count = 0;
    QFL = 0;
    QFR = 0;
    while(1)
    {
        PWMoutRight = CentrePWM - YawPWMout;
        PWMoutLeft = CentrePWM + YawPWMout;

    if(PWMoutRight>=95)
        PWMoutRight=95;
    else if(PWMoutRight<=-95)
        PWMoutRight=-95;
     if(PWMoutLeft>=95)
        PWMoutLeft=95;
    else if(PWMoutLeft<=-95)
        PWMoutLeft=-95;

       //除了输出pwm还要根据pwm控制转向
       Set_Speed(Wheel_FL, PWMoutLeft);
       Set_Speed(Wheel_BL, PWMoutLeft);
       Set_Speed(Wheel_FR, PWMoutRight);
       Set_Speed(Wheel_BR, PWMoutRight);
       PID_SetTaget(&PID_FL,PWMoutLeft);
       PID_SetTaget(&PID_BL,PWMoutLeft);
       PID_SetTaget(&PID_FR,PWMoutRight);
       PID_SetTaget(&PID_BR,PWMoutRight);
    //    OLED_ShowNum(0,0,(int)QYaw,4,8);
      Average_count = (QFL+QFR)/2;//等到一定距离后再进行寻迹是否到达的判定
    if(Average_count >= EncoderNumber)//寻迹路程判定退出pid寻迹//每个弧线的距离大约为1160个脉冲
     {
        // StopFlag = Xunji.X1+Xunji.X2+Xunji.X3+Xunji.X4+Xunji.X5+Xunji.X6+Xunji.X7+Xunji.X8;
        // if( StopFlag == 0)
        // {
            // Control_Beep(enable_Beep);
            Average_count = 0;
            Front_Left_Count = 0;
            Front_Right_Count = 0;
            Set_Speed(Wheel_FL, 0);
            Set_Speed(Wheel_BL, 0);
            Set_Speed(Wheel_FR, 0);
            Set_Speed(Wheel_BR, 0);
            PID_SetTaget(&PID_FL,0);
            PID_SetTaget(&PID_BL,0);
            PID_SetTaget(&PID_FR,0);
            PID_SetTaget(&PID_BR,0);
            //声光提醒  
            My_Delay_MS(100);
            // Control_Beep(disable_Beep);
            return ;
        // }

     }
    }
}
