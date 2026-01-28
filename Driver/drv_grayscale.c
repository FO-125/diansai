#include "drv_grayscale.h"
#include <string.h>
#include "GPIO.h"
typedef struct{
    GPIO_Regs *GPIOx;
    uint8_t pin1;
    uint8_t pin2;
    uint8_t pin3;
    uint8_t pin4;
    uint8_t pin5;
    uint8_t pin6;
    uint8_t pin7;
    uint8_t pin8;
} Grayscale_GPIO;

typedef struct{
    uint8_t  X1 ;
    uint8_t  X2 ;
    uint8_t  X3 ;
    uint8_t  X4 ;
    uint8_t  X5 ;
    uint8_t  X6 ;
    uint8_t  X7 ;
    uint8_t  X8 ;
}Grayscale_value;

typedef struct{
    Grayscale_value value;
    Grayscale_GPIO GPIO;
}Dev_Grayscale_Data;

Dev_Grayscale_Data Grayscale1;

// 引脚初始化函数
int Grayscale_pin_init(struct Dev_Grayscale* gray,GPIO_Regs *GPIOX,uint8_t pin1,uint8_t pin2,uint8_t pin3,uint8_t pin4,uint8_t pin5,uint8_t pin6,uint8_t pin7,uint8_t pin8)
{
    Dev_Grayscale_Data *data = (Dev_Grayscale_Data *)gray->grayscale_Data;
    data->GPIO.GPIOx = GPIOX;
    data->GPIO.pin1 = pin1;
    data->GPIO.pin2 = pin2;
    data->GPIO.pin3 = pin3;
    data->GPIO.pin4 = pin4;
    data->GPIO.pin5 = pin5;
    data->GPIO.pin6 = pin6;
    data->GPIO.pin7 = pin7;
    data->GPIO.pin8 = pin8;
    return 1;
}

int Grayscale_clear_value(struct Dev_Grayscale *grayscale)
{
    Dev_Grayscale_Data *data = (Dev_Grayscale_Data *)grayscale->grayscale_Data;
    memset(&data->value, 0, sizeof(data->value));
    return 1;
}

int Grayscale_read_value(struct Dev_Grayscale *grayscale)
{
    Grayscale_clear_value(grayscale);
    Dev_Grayscale_Data *data = (Dev_Grayscale_Data *)grayscale->grayscale_Data;
    Grayscale_GPIO *gray = &data->GPIO;
     uint32_t GPIO_port=DL_GPIO_readPins(gray->GPIOx,gray->pin1|gray->pin2|gray->pin3|gray->pin4|gray->pin5|gray->pin6|gray->pin7|gray->pin8);
    if ((GPIO_port & gray->pin1) != 0) // 高电平
        data->value.X1 =1;
    else
        data->value.X1 =0;
    if ((GPIO_port & gray->pin2) != 0) // 高电平
        data->value.X2 =1;
    else
        data->value.X2 =0;
    if ((GPIO_port & gray->pin3) != 0) // 高电平
        data->value.X3 =1;
    else
        data->value.X3 =0;
    if ((GPIO_port & gray->pin4) != 0) // 高电平
        data->value.X4 =1;
    else
        data->value.X4 =0;
    if ((GPIO_port & gray->pin5) != 0) // 高电平
        data->value.X5 =1;
    else
        data->value.X5 =0;
    if ((GPIO_port & gray->pin6) != 0) // 高电平
        data->value.X6 =1;
    else
        data->value.X6 =0;
    if ((GPIO_port & gray->pin7) != 0) // 高电平
        data->value.X7 =1;
    else
        data->value.X7 =0;
    if ((GPIO_port & gray->pin8) != 0) // 高电平
        data->value.X8 =1;
    else
        data->value.X8 =0;

        
    return 1;
}

// 灰度传感器设备实例
struct Dev_Grayscale g_dev_Grayscale1 =
{
    "grayscale",
    Grayscale_pin_init,
    Grayscale_read_value,
    Grayscale_clear_value,
    &Grayscale1
};

// 灰度传感器设备数组
struct Dev_Grayscale *g_grayscale_devs[] = {&g_dev_Grayscale1};

// 获取灰度传感器设备函数
struct Dev_Grayscale *GetGrayscale(char *name)
{
    int i = 0;
    for (i = 0; i < sizeof(g_grayscale_devs) / sizeof(g_grayscale_devs[0]); i++)
    {
        if (0 == strcmp(name, g_grayscale_devs[i]->name))
            return g_grayscale_devs[i];
    }
    return NULL;
}

int GetGrayscaleErr(struct Dev_Grayscale *grayscale)
{
    Dev_Grayscale_Data *data = (Dev_Grayscale_Data *)grayscale->grayscale_Data;
    Grayscale_value* value=&data->value;
    int err=5*value->X1+3*value->X2+2*value->X3+value->X4-value->X5-2*value->X6-3*value->X7-5*value->X8;
    return err;
}