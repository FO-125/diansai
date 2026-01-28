#ifndef __GPIO_H
#define __GPIO_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ti_msp_dl_config.h"

#define GPIO(port,pin,x)   do{ x ? \
                                DL_GPIO_setPins(port, pin) : \
                                DL_GPIO_clearPins(port, pin); \
                              }while(0)      


#define GPIO_TOGGLE(port,pin)   do{ DL_GPIO_togglePins(port, pin); }while(0)        
#define GPIO_CLEARInterruptStatus(port,pin)   do{ DL_GPIO_clearInterruptStatus(port, pin); }while(0)    
uint32_t GPIO_read(GPIO_Regs * 	gpio,uint32_t 	pins);  
#ifdef __cplusplus
}
#endif
#endif