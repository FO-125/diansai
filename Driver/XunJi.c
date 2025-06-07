#include "lib.h"
int EncoderNumber=0;
int CentrePWM=0;
int GetXunJIErr(void)
{
    static int lasterr = 0;
    if(Xunji.X1 == 0 && Xunji.X2 ==0 && Xunji.X3 ==0 && Xunji.X4 == 1 && Xunji.X5 == 1 && Xunji.X6 ==0 && Xunji.X7== 0 && Xunji.X8== 0)
    {      
    
        lasterr = 0;
        return 0;
    }     
    else if(Xunji.X1 ==0 && Xunji.X2 ==0 && Xunji.X3 ==0 && Xunji.X4 ==1 && Xunji.X5==0 && Xunji.X6 ==0 && Xunji.X7 ==0 && Xunji.X8 ==0)
    {
        lasterr = -1;
  
        return  -1;      
    }
        
    else if(Xunji.X1 ==0 && Xunji.X2 ==0 && Xunji.X3 == 1 && Xunji.X4 == 1 && Xunji.X5== 0 && Xunji.X6 ==0 && Xunji.X7 ==0 && Xunji.X8== 0)
    {
        lasterr = -2;
     
            return -2;
    }
       
    else if(Xunji.X1 ==0 && Xunji.X2 ==0 && Xunji.X3 == 1 && Xunji.X4== 0 && Xunji.X5 ==0 && Xunji.X6 ==0 && Xunji.X7==0 && Xunji.X8 ==0)
       {
        lasterr = -3;

            return -3;
       } 
     else if(Xunji.X1 ==0 && Xunji.X2 == 1 && Xunji.X3 == 1 && Xunji.X4 ==0 && Xunji.X5 ==0 && Xunji.X6==0 && Xunji.X7 ==0 && Xunji.X8 ==0)
        {
            lasterr = -4;

        return -4;
        }
     else if(Xunji.X1 ==0 && Xunji.X2 == 1 && Xunji.X3 ==0 && Xunji.X4 ==0 && Xunji.X5 ==0 && Xunji.X6 ==0 && Xunji.X7 ==0 && Xunji.X8 ==0)
        {
            lasterr = -5;
      
        return -5;

        }
     else if(Xunji.X1 ==1 && Xunji.X2 == 1 && Xunji.X3== 0 && Xunji.X4 ==0 && Xunji.X5== 0 && Xunji.X6 ==0 && Xunji.X7 ==0 && Xunji.X8== 0)
        {
            lasterr = -6;
      
            return -6;
        }
     else if(Xunji.X1 ==1 && Xunji.X2 ==0 && Xunji.X3== 0 && Xunji.X4 ==0 && Xunji.X5== 0 && Xunji.X6 ==0 && Xunji.X7 ==0 && Xunji.X8 ==0)
        {
            lasterr = -7;
   
        return  -7;

        }
    else if(Xunji.X1 ==0 && Xunji.X2== 0 && Xunji.X3== 0 && Xunji.X4== 0 && Xunji.X5 == 1 && Xunji.X6 ==0 && Xunji.X7 ==0 && Xunji.X8 ==0)
        {
            lasterr = 1;
         
            return 1;

        }
    else if(Xunji.X1 ==0 && Xunji.X2 ==0 && Xunji.X3 ==0 && Xunji.X4 ==0 && Xunji.X5 == 1 && Xunji.X6 == 1 && Xunji.X7 ==0 && Xunji.X8 ==0)
        {
            lasterr = 2;
            
                return  2;

        }     
     else if(Xunji.X1 ==0 && Xunji.X2 ==0 && Xunji.X3 ==0 && Xunji.X4 ==0 && Xunji.X5 ==0 && Xunji.X6 == 1 && Xunji.X7== 0 && Xunji.X8 ==0)
        {
            lasterr = 3;
            
            return 3;

        }
     else if(Xunji.X1 ==0 && Xunji.X2== 0 && Xunji.X3== 0 && Xunji.X4 ==0 && Xunji.X5 ==0 && Xunji.X6 == 1 && Xunji.X7 == 1 && Xunji.X8 ==0)
        {
            lasterr = 4;
          
            return 4;
        }
     else if(Xunji.X1 ==0 && Xunji.X2== 0 && Xunji.X3 ==0 && Xunji.X4== 0 && Xunji.X5== 0 && Xunji.X6== 0 && Xunji.X7 == 1 && Xunji.X8 ==0)
        {
            lasterr = 5;
   
            return 5;
        }
     else if(Xunji.X1 ==0 && Xunji.X2 ==0 && Xunji.X3 ==0 && Xunji.X4 ==0 && Xunji.X5 ==0 && Xunji.X6 ==0 && Xunji.X7 == 1 && Xunji.X8 == 1)
       {
            lasterr = 6;
      
            return 6; 

       }
     else if(Xunji.X1 ==0 && Xunji.X2 ==0 && Xunji.X3 ==0 && Xunji.X4== 0 && Xunji.X5== 0 && Xunji.X6 ==0 && Xunji.X7 ==0 && Xunji.X8 == 1)
        {
            lasterr = 7;
   
            return 7;
        }
        else 
            return  lasterr;
}

void XunJIPIDConcrolTurn(uint16_t EncoderNumber)
{
    int StopFlag = 0;
    volatile int PWMoutLeft = 0,PWMoutRight = 0;
    volatile int PWMout = 0;
    PID_Init(&PID_Turn,0,0,0);
    Average_count = 0;
    Front_Left_Count = 0;
    Front_Right_Count = 0;
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
      Average_count = (Front_Left_Count+Front_Right_Count)/2;//等到一定距离后再进行寻迹是否到达的判定
    if(Average_count >= EncoderNumber)//寻迹路程判定退出pid寻迹//每个弧线的距离大约为1160个脉冲
     {
        StopFlag = Xunji.X1+Xunji.X2+Xunji.X3+Xunji.X4+Xunji.X5+Xunji.X6+Xunji.X7+Xunji.X8;
        if( StopFlag == 0)
        {
            Control_Beep(enable_Beep);
            Average_count = 0;
            Front_Left_Count = 0;
            Front_Right_Count = 0;
            Set_Speed(Wheel_FL, 0);
            Set_Speed(Wheel_BL, 0);
            Set_Speed(Wheel_FR, 0);
            Set_Speed(Wheel_BR, 0);
            //声光提醒  
            My_Delay_MS(100);
            Control_Beep(disable_Beep);
            return ;
        }

     }
    }
}

void ControlSinAngleA_B(float targetAngle,uint16_t EncoderNumber)
{
    int StopFlag = 0;
    volatile int PWMoutLeft = 0,PWMoutRight = 0;
    volatile int PWMout = 0;
    OLED_Clear();
    PID_Init(&PID_Yaw,SinJiaoKP,SinJiaoKI,SinJiaoKD);
    PID_SetTaget(&PID_Yaw, targetAngle);
    Average_count = 0;
    Front_Left_Count = 0;
    Front_Right_Count = 0;
    while(1)
    {
 
      PWMout = PID_Update_Yaw(&PID_Yaw);
                    //根据输出的PWM极性来判断需要左偏还是右偏
                    //偏右为+
                    //偏左为-
        
      PWMoutRight = CentrePWM + PWMout;
      PWMoutLeft = CentrePWM - PWMout;

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
       OLED_ShowNum(0,0,(int)QYaw,4,8);
      Average_count = (Front_Left_Count+Front_Right_Count)/2;//等到一定距离后再进行寻迹是否到达的判定
    if(Average_count >= EncoderNumber)//寻迹路程判定退出pid寻迹//每个弧线的距离大约为1160个脉冲
     {
        StopFlag = Xunji.X1+Xunji.X2+Xunji.X3+Xunji.X4+Xunji.X5+Xunji.X6+Xunji.X7+Xunji.X8;
        if( StopFlag == 0)
        {
            Control_Beep(enable_Beep);
            Average_count = 0;
            Front_Left_Count = 0;
            Front_Right_Count = 0;
            Set_Speed(Wheel_FL, 0);
            Set_Speed(Wheel_BL, 0);
            Set_Speed(Wheel_FR, 0);
            Set_Speed(Wheel_BR, 0);
            //声光提醒  
            My_Delay_MS(100);
            Control_Beep(disable_Beep);
            return ;
        }

     }
    }
}


void ControlSinAngleC_D(float targetAngle,uint16_t EncoderNumber)
{
    int StopFlag = 0;
    volatile int PWMoutLeft = 0,PWMoutRight = 0;
    volatile int PWMout = 0;
    OLED_Clear();
    PID_Init(&PID_Yaw,SinJiaoKPC_D,SinJiaoKIC_D,SinJiaoKDC_D);
    PID_SetTaget(&PID_Yaw, targetAngle);
    Average_count = 0;
    Front_Left_Count = 0;
    Front_Right_Count = 0;
    while(1)
    {
 
      PWMout = PID_Update_Yaw(&PID_Yaw);
                    //根据输出的PWM极性来判断需要左偏还是右偏
                    //偏右为+
                    //偏左为-
        
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
       OLED_ShowNum(0,0,(int)QYaw,4,8);
      Average_count = (Front_Left_Count+Front_Right_Count)/2;//等到一定距离后再进行寻迹是否到达的判定
    if(Average_count >= EncoderNumber)//寻迹路程判定退出pid寻迹//每个弧线的距离大约为1160个脉冲
     {
        StopFlag = Xunji.X1+Xunji.X2+Xunji.X3+Xunji.X4+Xunji.X5+Xunji.X6+Xunji.X7+Xunji.X8;
        if( StopFlag == 0)
        {
            Control_Beep(enable_Beep);
            Average_count = 0;
            Front_Left_Count = 0;
            Front_Right_Count = 0;
            Set_Speed(Wheel_FL, 0);
            Set_Speed(Wheel_BL, 0);
            Set_Speed(Wheel_FR, 0);
            Set_Speed(Wheel_BR, 0);
            //声光提醒  
            My_Delay_MS(100);
            Control_Beep(disable_Beep);
            return ;
        }

     }
    }
}
