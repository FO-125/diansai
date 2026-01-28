#include "app_TraceCar.h"
#include "Alg/alg_pid.h"
#include "drv_encoder.h"
#include "drv_grayscale.h"
void XunJIPIDConcrol(uint16_t EncoderNumber)
{
    struct Dev_PID* pid_controller_FL=GetPID("pid_controller_FL");
    struct Dev_PID* pid_controller_FR=GetPID("pid_controller_FR");
    struct Dev_PID* pid_controller_BL=GetPID("pid_controller_BL");
    struct Dev_PID* pid_controller_BR=GetPID("pid_controller_BR");
    struct Dev_PID* pid_controller_Trace=GetPID("pid_controller_Trace");
    struct Dev_Grayscale* grayscale=GetGrayscale("grayscale");
    struct Dev_Encoder* encoder_FL=GetEncoder("encoder_FL");
    struct Dev_Encoder* encoder_FR=GetEncoder("encoder_FR");
    struct Dev_Encoder* encoder_BL=GetEncoder("encoder_BL");
    struct Dev_Encoder* encoder_BR=GetEncoder("encoder_BR");
    volatile int CentrePWM=60;
    volatile int PWMoutLeft = 0, PWMoutRight = 0;
    volatile int PWMout = 0;
    
    pid_controller_FL->init(pid_controller_FL,0.5,1,0.2,PID_INCREMENTAL);
    pid_controller_FR->init(pid_controller_FR,0.5,1,0.2,PID_INCREMENTAL);
    pid_controller_BL->init(pid_controller_BL,0.5,1,0.2,PID_INCREMENTAL);
    pid_controller_BR->init(pid_controller_BR,0.5,1,0.2,PID_INCREMENTAL);
    pid_controller_Trace->init(pid_controller_Trace,4,0,0,PID_POSITIONAL);
    volatile int Average_count = 0;
    
    while(1)
    {
        PWMout = pid_controller_Trace->update(pid_controller_Trace,GetGrayscaleErr(grayscale));

        PWMoutRight = CentrePWM - PWMout;
        PWMoutLeft = CentrePWM + PWMout;

        // Limit PWM range
        if(PWMoutRight >= 95)
            PWMoutRight = 95;
        else if(PWMoutRight <= -95)
            PWMoutRight = -95;
            
        if(PWMoutLeft >= 95)
            PWMoutLeft = 95;
        else if(PWMoutLeft <= -95)
            PWMoutLeft = -95;

        // Set wheel speeds
        pid_controller_FL->set_target(pid_controller_FL, PWMoutLeft);
        pid_controller_FR->set_target(pid_controller_FR, PWMoutRight);
        pid_controller_BL->set_target(pid_controller_BL, PWMoutLeft);
        pid_controller_BR->set_target(pid_controller_BR, PWMoutRight);
        
        pid_controller_FL->update(pid_controller_FL, 0.448*encoder_FL->get_count(encoder_FL)-1.56);
        pid_controller_FR->update(pid_controller_FR, 0.448*encoder_FR->get_count(encoder_FR)-1.56);
        pid_controller_BL->update(pid_controller_BL, 0.448*encoder_BL->get_count(encoder_FR)-1.56);
        pid_controller_BR->update(pid_controller_BR, 0.448*encoder_BR->get_count(encoder_FR)-1.56);

        Average_count = (encoder_FL->get_QEI(encoder_FL) + encoder_FR->get_QEI(encoder_FR)+encoder_BL->get_QEI(encoder_BL)+encoder_BR->get_QEI(encoder_BR)) / 4;

        // Exit condition
        if(Average_count >= EncoderNumber/*Xunji.X7==1&&Xunji.X8==1*/)
        {
            // Reset states
            Average_count = 0;
            encoder_FL->set_QEI(encoder_FL,0);
            encoder_FR->set_QEI(encoder_FR,0);
            encoder_BL->set_QEI(encoder_BL,0);
            encoder_BR->set_QEI(encoder_BR,0);

            pid_controller_FL->set_target(pid_controller_FL, 0);
            pid_controller_FR->set_target(pid_controller_FR, 0);
            pid_controller_BL->set_target(pid_controller_BL, 0);
            pid_controller_BR->set_target(pid_controller_BR, 0);
             
            pid_controller_FL->update(pid_controller_FL, 0);
            pid_controller_FR->update(pid_controller_FR, 0);
            pid_controller_BL->update(pid_controller_BL, 0);
            pid_controller_BR->update(pid_controller_BR, 0);
            
            vtaskDelay(500);
            return;
        }
    }
}