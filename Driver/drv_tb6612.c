#include "drv_tb6612.h"
#include <string.h>
#include "config.h"
#include "GPIO.h"
#include "TIMER.h"
// TB6612设备结构体
struct Dev_TB6612;

// TB6612 GPIO配置结构体
typedef struct {
    GPIO_Regs *GPIOx_IN1;      // IN1 GPIO端口
    uint8_t pin_IN1;           // IN1引脚
    GPIO_Regs *GPIOx_IN2;      // IN2 GPIO端口  
    uint8_t pin_IN2;           // IN2引脚
    GPIO_Regs *GPIOx_STBY;      // IN1 GPIO端口
    uint8_t pin_STBY;  
    GPTIMER_Regs *GPTIMERx_PWM;     
    DL_TIMER_CC_INDEX TIMER_CC_INDEX;           
    
} TB6612_GPIO;

// TB6612电机状态结构体
typedef struct {
    int16_t speed;             // 当前速度
    uint8_t direction;         // 当前方向
    uint8_t is_running;        // 是否运行中
} TB6612_State;

// TB6612设备数据结构体
typedef struct {
    TB6612_State state;        // 电机状态
    TB6612_GPIO GPIO;          // GPIO配置
} Dev_TB6612_Data;

// TB6612设备数据实例
Dev_TB6612_Data TB6612_MotorFL = {0};
Dev_TB6612_Data TB6612_MotorFR = {0};
Dev_TB6612_Data TB6612_MotorBL = {0};
Dev_TB6612_Data TB6612_MotorBR = {0};

// 引脚初始化函数
int TB6612_pin_init(struct Dev_TB6612 *tb6612, GPIO_Regs *GPIOx_IN1, uint8_t pin_IN1, GPIO_Regs *GPIOx_IN2, uint8_t pin_IN2, GPTIMER_Regs *GPTIMERx_PWM, DL_TIMER_CC_INDEX TIMER_CC_INDEX, GPIO_Regs *GPIOx_STBY, uint8_t pin_STBY)
{
    Dev_TB6612_Data *data = (Dev_TB6612_Data *)tb6612->tb6612_Data;
    data->GPIO.GPIOx_IN1 = GPIOx_IN1;
    data->GPIO.pin_IN1 = pin_IN1;
    data->GPIO.GPIOx_IN2 = GPIOx_IN2;
    data->GPIO.pin_IN2 = pin_IN2;
    data->GPIO.GPTIMERx_PWM = GPTIMERx_PWM;
    data->GPIO.TIMER_CC_INDEX = TIMER_CC_INDEX;
    data->GPIO.GPIOx_STBY = GPIOx_STBY;
    data->GPIO.pin_STBY = pin_STBY;
    
    return 1;
}

// 设置电机速度函数
int TB6612_set_speed(struct Dev_TB6612 *tb6612, int16_t duty)
{
    Dev_TB6612_Data *data = (Dev_TB6612_Data *)tb6612->tb6612_Data;
    float compareValue =0;
    // 限制速度范围
    if (duty > 95) duty =95 ;
    if (duty < -95) duty = -95;
    if(duty > 0)
        {
            compareValue = 3199 - 3199 * (duty/100.0);
            GPIO(data->GPIO.GPIOx_IN1, data->GPIO.pin_IN1, 1);
            GPIO(data->GPIO.GPIOx_IN2, data->GPIO.pin_IN2, 0);
        }
        else if(duty < 0)
        {
            float compareValue = 3199 + 3199 * (duty/100.0);
            GPIO(data->GPIO.GPIOx_IN1, data->GPIO.pin_IN1, 0);
            GPIO(data->GPIO.GPIOx_IN2, data->GPIO.pin_IN2, 1);
        }
        else 
        {
            GPIO(data->GPIO.GPIOx_STBY, data->GPIO.pin_STBY,0);
        }
    TIMER_PWM(data->GPIO.GPTIMERx_PWM, compareValue, data->GPIO.TIMER_CC_INDEX);

    
    return 1;
}

// 停止电机函数
int TB6612_off(struct Dev_TB6612 *tb6612)
{
    Dev_TB6612_Data *data = (Dev_TB6612_Data *)tb6612->tb6612_Data;
    
    GPIO(data->GPIO.GPIOx_IN1, data->GPIO.pin_IN1, 0);
    
    return 1;
}

int TB6612_on(struct Dev_TB6612 *tb6612)
{
    Dev_TB6612_Data *data = (Dev_TB6612_Data *)tb6612->tb6612_Data;
    
    GPIO(data->GPIO.GPIOx_STBY, data->GPIO.pin_STBY, 0);
    
    return 1;
}


static struct Dev_TB6612 tb6612_instances[] =
{
    {
        "tb6612_motor1",
        TB6612_pin_init,
        TB6612_set_speed,
        TB6612_off,
        TB6612_on,
        &TB6612_MotorFL
    },
    {
        "tb6612_motor2",
        TB6612_pin_init,
        TB6612_set_speed,
        TB6612_off,
        TB6612_on,
        &TB6612_MotorFR

    },
    {
        "tb6612_motor3",
        TB6612_pin_init,
        TB6612_set_speed,
        TB6612_off,
        TB6612_on,
        &TB6612_MotorBL
    },
    {
        "tb6612_motor4",
        TB6612_pin_init,
        TB6612_set_speed,
        TB6612_off,
        TB6612_on,
        &TB6612_MotorBR
    }
};


struct Dev_TB6612 *g_tb6612_devs[] = {
    &tb6612_instances[0],
    &tb6612_instances[1], 
    &tb6612_instances[2],
    &tb6612_instances[3]
};

// 获取TB6612设备函数
struct Dev_TB6612 *GetTB6612(char *name)
{
    int i = 0;
    for (i = 0; i < sizeof(g_tb6612_devs) / sizeof(g_tb6612_devs[0]); i++)
    {
        if (0 == strcmp(name, g_tb6612_devs[i]->name))
            return g_tb6612_devs[i];
    }
    return NULL;
}
