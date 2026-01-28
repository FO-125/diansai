#ifndef __CONFIG_H
#define __CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif
#include "stdint.h"
#include "ti_msp_dl_config.h"
typedef struct{
    GPIO_Regs *GPIOx;
    uint32_t pin;
}My_GPIO;
extern int g_Start_Count;
#ifdef __cplusplus
}
#endif
#endif