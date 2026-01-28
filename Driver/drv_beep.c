#include "drv_beep.h"
#include <string.h>
#include "config.h"
#include "GPIO.h"
My_GPIO Beep1;
//引脚注册
int Beep_pin_init(GPIO_Regs * GPIOX,uint32_t pin)
{
    Beep1.GPIOx=GPIOX;
    Beep1.pin=pin;
    return 1;
}


int Beep_config(struct Dev_Beep* beep,Beep_ST state)
{
    My_GPIO* data = beep->GPIO_beep;
    switch(state) {
        case Beep_on:
            GPIO(data->GPIOx,data->pin,1);
            return 1;
            break;
        case Beep_off:
            GPIO(data->GPIOx,data->pin,0);
            return 1;
            break;
        default:
            return 0;
            break;
    }
}

struct Dev_Beep g_dev_Beep1 =
{
    "beep1",
    Beep_pin_init,
    Beep_config,
    &Beep1,  
};

struct Dev_Beep *g_beep_devs[] = {&g_dev_Beep1};

struct Dev_Beep *GetBEEP(char *name)
{
    int i = 0;
    for (i = 0; i < sizeof(g_beep_devs) / sizeof(g_beep_devs[0]); i++)
    {
        if (0 == strcmp(name, g_beep_devs[i]->name))
            return g_beep_devs[i];
    }
    return NULL;
}
