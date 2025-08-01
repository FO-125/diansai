#include "lib.h"
#include "pid.h"
// #define OPENMV
#define Xunji
#define TuoLuoYi 
int delay_count=0;
int Speed_FL=0;
int Speed_FR=0;
int Speed_BL=0;
int Speed_BR=0;

void TIMER_MS_UART_INST_IRQHandler()
{
    #ifdef OPENMV
    Translate_OPENMV();
    Go_OPENMV(&Openmv,30,3,2);
    #endif
      
    // Uart_Run_TuoLuoYi(JY61P_Data.RxData);
}


void TIMER_MS_SYS_INST_IRQHandler()
{
    static int Count;
    Count++;
    if(Count>=100)
    {
        Count=0;
        PID_Update_FL(&PID_FL);
        PID_Update_FR(&PID_FR);
        PID_Update_BL(&PID_BL);
        PID_Update_BR(&PID_BR);
    }
    Xunji_Data_Run();
    if(delay_count>0)
    {
        delay_count--;
    }   
}

void My_Delay_MS(int ms)
{
    delay_count=ms;
    while (delay_count > 0){}
}

