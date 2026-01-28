#ifndef __TB6612_H
#define __TB6612_H
#ifdef __cplusplus
extern "C" {
#endif
#include "stdint.h"
#include "ti_msp_dl_config.h"
// TB6612电机驱动设备结构体
struct Dev_TB6612 {
    char *name;                              // 设备名称
    int (*pin_init)(struct Dev_TB6612 *tb6612, GPIO_Regs *GPIOx_IN1, uint8_t pin_IN1, GPIO_Regs *GPIOx_IN2, uint8_t pin_IN2, GPTIMER_Regs *GPTIMERx_PWM, DL_TIMER_CC_INDEX TIMER_CC_INDEX, GPIO_Regs *GPIOx_STBY, uint8_t pin_STBY);  // 引脚初始化函数
    int (*set_speed)(struct Dev_TB6612 *tb6612, int16_t speed);         // 设置电机速度函数
    
    int (*off)(struct Dev_TB6612 *tb6612);                             // 停止电机函数
    int (*on)(struct Dev_TB6612 *tb6612);
    void *tb6612_Data;                      // 设备数据指针
};

// 函数声明
struct Dev_TB6612 *GetTB6612(char *name);

#ifdef __cplusplus
}
#endif
#endif
