#ifndef __DRV_LED_H
#define __DRV_LED_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ti_msp_dl_config.h"
typedef enum {
    LED_ON = 0,
    LED_OFF,
    LED_BLINK_2,
    LED_BLINK_3, 
    LED_BLINK_4,
    LED_BLINK_5
} LED_ST;

struct Dev_LED{
    char* name;
    int (*init)(GPIO_Regs *GPIOX, uint32_t pin);
    int (*config)(struct Dev_LED* led, LED_ST state);
    void* GPIO_led;
};

struct Dev_LED *GetLED(char *name);

#ifdef __cplusplus
}
#endif
#endif
