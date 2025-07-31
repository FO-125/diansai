#include "LED.h"
#include "lib.h"
#include "ti/driverlib/dl_gpio.h"
void Control_LED(enum LED_ST state)
{
  if(state==sparkle_LED)
    {
            DL_GPIO_setPins(GPIO_LED_PORT,GPIO_LED_PIN_LED1_PIN);
        }
        else if(state==disable_LED)
        {            
           DL_GPIO_clearPins(GPIO_LED_PORT,GPIO_LED_PIN_LED1_PIN);
        }
        else if(state==sparkle_LED2)
        {
            for(int i=0;i<4;i++)
            {
                DL_GPIO_togglePins(GPIO_LED_PORT,GPIO_LED_PIN_LED1_PIN );
                My_Delay_MS(500);
            }
        }
        else if(state==sparkle_LED3)
        {
            for(int i=0;i<6;i++)
            {
                DL_GPIO_togglePins(GPIO_LED_PORT,GPIO_LED_PIN_LED1_PIN );
                My_Delay_MS(333);
            }
        }
        else if(state==sparkle_LED4)
        {
            for(int i=0;i<8;i++)
            {
                DL_GPIO_togglePins(GPIO_LED_PORT,GPIO_LED_PIN_LED1_PIN );
                My_Delay_MS(250);
            }
        }
        else if(state==sparkle_LED5)
        {
            for(int i=0;i<10;i++)
            {
                DL_GPIO_togglePins(GPIO_LED_PORT,GPIO_LED_PIN_LED1_PIN );
                My_Delay_MS(200);
            }
    }
}
    
        

void LED_init()
{
    Control_LED(disable_LED);
}