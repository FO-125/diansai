#ifndef __DRV_GRAYSCALE_H
#define __DRV_GRAYSCALE_H
#ifdef __cplusplus
extern "C" {
#endif
#include "ti_msp_dl_config.h"
struct Dev_Grayscale{
    char* name;
    int (*init)(struct Dev_Grayscale* gray,GPIO_Regs *GPIOX,uint8_t pin1,uint8_t pin2,uint8_t pin3,uint8_t pin4,uint8_t pin5,uint8_t pin6,uint8_t pin7,uint8_t pin8);
    int (*read_value)(struct Dev_Grayscale* grayscale);
    int (*clear_value)(struct Dev_Grayscale* grayscale);
    void* grayscale_Data;
    
};

struct Dev_Grayscale* GetGrayscale(char *name);
int GetGrayscaleErr(struct Dev_Grayscale *grayscale);
#ifdef __cplusplus
}
#endif
#endif
