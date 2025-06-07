#include "lib.h"
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

    #ifdef Xunji
    Uart_Run_XunJi();
    #endif

    #ifdef TuoLuoYi
    Uart_Run_TuoLuoYi();
    #endif
}


void TIMER_MS_SYS_INST_IRQHandler()
{
    // static int Count;
    // Count++;
    // if(Count>=10)
    // {
    //     Count=0;

    // }

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