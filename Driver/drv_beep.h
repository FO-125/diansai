#ifndef __DRV_BEEP_H
#define __DRV_BEEP_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ti_msp_dl_config.h"
typedef enum {
    Beep_on = 0,
    Beep_off
} Beep_ST;

struct Dev_Beep{
    char* name;
    int (*init)(GPIO_Regs * GPIOX,uint32_t pin);
    int (*config)(struct Dev_Beep* beep,Beep_ST state);
    void* GPIO_beep;
};

struct Dev_Beep *GetBEEP(char *name);

#ifdef __cplusplus
}
#endif
#endif

