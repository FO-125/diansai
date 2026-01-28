#include "GPIO.h"
uint32_t GPIO_read(GPIO_Regs * 	gpio,uint32_t 	pins )
{
   return DL_GPIO_readPins(gpio, pins);
}
