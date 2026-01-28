#ifndef __DRV_ENCODER_H
#define __DRV_ENCODER_H
#ifdef __cplusplus
extern "C" {
#endif
#include "stdint.h"
#include "ti_msp_dl_config.h"
// 编码器设备驱动结构体
struct Dev_Encoder {
    char *name;                              // 设备名称
    int (*pin_init)(struct Dev_Encoder *encoder, GPIO_Regs *GPIOx_A, uint8_t pin_A, GPIO_Regs *GPIOx_B, uint8_t pin_B);  // 引脚初始化函数
    int (*clear_value)(struct Dev_Encoder *encoder);         // 清除编码器值函数
    int (*read_value)(struct Dev_Encoder *encoder);
    uint8_t (*get_Apin)(struct Dev_Encoder *encoder);
    int32_t (*get_count)(struct Dev_Encoder *encoder);        // 读取编码器值函数
    int32_t (*get_QEI)(struct Dev_Encoder *encoder); 
    uint8_t (*set_QEI)(struct Dev_Encoder *encoder, int32_t QEI_value);
    void *encoder_Data;                      // 设备数据指针
};

// 函数声明
struct Dev_Encoder *GetEncoder(char *name);
#ifdef __cplusplus
}
#endif
#endif
