#include "drv_led.h"
#include <string.h>
#include "config.h"
#include "GPIO.h"
My_GPIO LED1;

// LED配置函数
int LED_config(struct Dev_LED* led, LED_ST state)
{
    My_GPIO* data = led->GPIO_led;
    switch(state) {
        case LED_ON:
            GPIO(data->GPIOx, data->pin,1);
            return 1;
            break;
        case LED_OFF:
            GPIO(data->GPIOx, data->pin,0);
            return 1;
            break;
        case LED_BLINK_2:
            for(int i = 0; i < 4; i++)
            {
                GPIO_TOGGLE(data->GPIOx, data->pin);
                vtaskDelay(500);
            }
            return 1;
            break;
        case LED_BLINK_3:
            for(int i = 0; i < 6; i++)
            {
                GPIO_TOGGLE(data->GPIOx, data->pin);
                vtaskDelay(333);
            }
            return 1;
            break;
        case LED_BLINK_4:
            for(int i = 0; i < 8; i++)
            {
                GPIO_TOGGLE(data->GPIOx, data->pin);
                vtaskDelay(250);
            }
            return 1;
            break;
        case LED_BLINK_5:
            for(int i = 0; i < 10; i++)
            {
                GPIO_TOGGLE(data->GPIOx, data->pin);
                vtaskDelay(200);
            }
            return 1;
            break;
        default:
            // 处理未知状态
            return 0;
            break;
    }
}

// 引脚初始化函数
int LED_pin_init(GPIO_Regs *GPIOX, uint32_t pin)
{
    LED1.GPIOx = GPIOX;
    LED1.pin = pin;
    return 1;
}

// LED设备实例
struct Dev_LED g_dev_LED1 =
{
    "led1",
    LED_pin_init,
    LED_config,
    &LED1,  
};

// LED设备数组
struct Dev_LED *g_led_devs[] = {&g_dev_LED1};

// 获取LED设备函数
struct Dev_LED *GetLED(char *name)
{
    int i = 0;
    for (i = 0; i < sizeof(g_led_devs) / sizeof(g_led_devs[0]); i++)
    {
        if (0 == strcmp(name, g_led_devs[i]->name))
            return g_led_devs[i];
    }
    return NULL;
}
