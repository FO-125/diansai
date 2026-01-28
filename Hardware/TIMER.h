#ifndef __TIMER_H
#define __TIMER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ti_msp_dl_config.h"
#define TIMER_PWM(gptimer,value,ccIndex)   do{ DL_Timer_setCaptureCompareValue(gptimer, value, ccIndex); }while(0)        

#ifdef __cplusplus
}
#endif
#endif