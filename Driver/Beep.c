#include "lib.h"
void Control_Beep(enum Beep_ST state)
{
    if(state==enable_Beep)
    {
         DL_GPIO_clearPins(GPIO_BEEP_PORT,GPIO_BEEP_beep1_PIN);
    }
    else 
    {
         DL_GPIO_setPins(GPIO_BEEP_PORT,GPIO_BEEP_beep1_PIN);
       
        
    }
}