#include "drv_encoder.h"
#include <stdint.h>
#include <string.h>
#include "config.h"
#include "GPIO.h"
// 编码器设备结构体
struct Dev_Encoder;

// 编码器GPIO配置结构体
typedef struct {
    GPIO_Regs *GPIOx_A;      // A相GPIO端口
    uint8_t pin_A;           // A相引脚
    GPIO_Regs *GPIOx_B;      // B相GPIO端口  
    uint8_t pin_B;           // B相引脚
} Encoder_GPIO;

// 编码器值结构体
typedef struct {
    int32_t count;           // 编码器计数值
    int32_t QEI;          
} Encoder_value;

// 编码器设备数据结构体
typedef struct {
    Encoder_value value;     // 编码器值
    Encoder_GPIO GPIO;       // GPIO配置
} Dev_Encoder_Data;

// 编码器设备数据实例
Dev_Encoder_Data Encoder_FL = {0};
Dev_Encoder_Data Encoder_FR = {0};
Dev_Encoder_Data Encoder_BL = {0};
Dev_Encoder_Data Encoder_BR = {0};

// 引脚初始化函数
int Encoder_pin_init(struct Dev_Encoder *encoder, GPIO_Regs *GPIOx_A, uint8_t pin_A, GPIO_Regs *GPIOx_B, uint8_t pin_B)
{
    Dev_Encoder_Data *data = (Dev_Encoder_Data *)encoder->encoder_Data;
    data->GPIO.GPIOx_A = GPIOx_A;
    data->GPIO.pin_A = pin_A;
    data->GPIO.GPIOx_B = GPIOx_B;
    data->GPIO.pin_B = pin_B;
    return 1;
}

// 清除编码器值函数
int Encoder_clear_value(struct Dev_Encoder *encoder)
{
    Dev_Encoder_Data *data = (Dev_Encoder_Data *)encoder->encoder_Data;
    // 使用memset清除所有编码器值
    memset(&data->value, 0, sizeof(data->value));
    return 1;
}

int Encoder_read_value(struct Dev_Encoder *encoder)
{
    Dev_Encoder_Data *data = (Dev_Encoder_Data *)encoder->encoder_Data;
    if(GPIO_read(GPIOA, data->GPIO.pin_B))
    {
        data->value.count--;
        data->value.QEI--;
    }
    else
    {
        data->value.count++;
        data->value.QEI++;
    }
    return 1;
}

uint8_t GetEncoderApin(struct Dev_Encoder *encoder)
{
    Dev_Encoder_Data *data = (Dev_Encoder_Data *)encoder->encoder_Data;
    return data->GPIO.pin_A;    
}

int32_t GetEncoderCount(struct Dev_Encoder *encoder)
{
    Dev_Encoder_Data *data = (Dev_Encoder_Data *)encoder->encoder_Data;
    int temp=data->value.count;
    data->value.count=0;
    return temp;    
}

int32_t GetEncoderQEI(struct Dev_Encoder *encoder)
{
    Dev_Encoder_Data *data = (Dev_Encoder_Data *)encoder->encoder_Data;

    return data->value.QEI;    
}

uint8_t SetEncoderQEI(struct Dev_Encoder *encoder,int32_t QEI)
{
    Dev_Encoder_Data *data = (Dev_Encoder_Data *)encoder->encoder_Data;

    data->value.QEI = QEI;    
    return 1;
}

static struct Dev_Encoder encoder_instances[] =
{
    {
        "encoder_FL",
        Encoder_pin_init,
        Encoder_clear_value,
        Encoder_read_value,
        GetEncoderApin,
        GetEncoderCount,
        GetEncoderQEI,
        SetEncoderQEI,
        &Encoder_FL
    },
    {
        "encoder_FR",
        Encoder_pin_init,
        Encoder_clear_value,
        Encoder_read_value,
        GetEncoderApin,
        GetEncoderCount,
        GetEncoderQEI,
        SetEncoderQEI,
        &Encoder_FR
    },
    {
        "encoder_BL",
        Encoder_pin_init,
        Encoder_clear_value,
        Encoder_read_value,
        GetEncoderApin,
        GetEncoderCount,
        GetEncoderQEI,
        SetEncoderQEI,
        &Encoder_BL
    },
    {
        "encoder_BR",
        Encoder_pin_init,
        Encoder_clear_value,
        Encoder_read_value,
        GetEncoderApin,
        GetEncoderCount,
        GetEncoderQEI,
        SetEncoderQEI,
        &Encoder_BR
    }
};

struct Dev_Encoder *g_encoder_devs[] = {
    &encoder_instances[0],
    &encoder_instances[1], 
    &encoder_instances[2],
    &encoder_instances[3]
};

// 获取编码器设备函数
struct Dev_Encoder *GetEncoder(char *name)
{
    int i = 0;
    for (i = 0; i < sizeof(g_encoder_devs) / sizeof(g_encoder_devs[0]); i++)
    {
        if (0 == strcmp(name, g_encoder_devs[i]->name))
            return g_encoder_devs[i];
    }
    return NULL;
}



// uint8_t GetEncoderBpin(struct Dev_Encoder *encoder)
// {
//     Dev_Encoder_Data *data = (Dev_Encoder_Data *)encoder->encoder_Data;
//     return data->GPIO.pin_B;    
// }



// int32_t GetEncoderQEI(struct Dev_Encoder *encoder)
// {
//     Dev_Encoder_Data *data = (Dev_Encoder_Data *)encoder->encoder_Data;
//     return data->value.QEI;    
// }

// void SetEncoderCount(struct Dev_Encoder *encoder, int32_t count)
// {
//     Dev_Encoder_Data *data = (Dev_Encoder_Data *)encoder->encoder_Data;
//     data->value.count = count;    
// }

// void SetEncoderQEI(struct Dev_Encoder *encoder, int32_t QEI)
// {
//     Dev_Encoder_Data *data = (Dev_Encoder_Data *)encoder->encoder_Data;
//     data->value.QEI = QEI;    
// }