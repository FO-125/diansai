#include "lib.h"
void Control_LED(enum LED_ST state)
{
    if(state==enable_LED)
    {
        DL_GPIO_setPins(GPIO_LED_PORT,GPIO_LED_PIN_LED1_PIN);
    }
    else 
    {
        DL_GPIO_clearPins(GPIO_LED_PORT,GPIO_LED_PIN_LED1_PIN);
    }
}

void LED_init()
{
    
}