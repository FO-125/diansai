#ifndef __LED_H
#define __LED_H

enum LED_ST{sparkle_LED=0,disable_LED,sparkle_LED2,sparkle_LED3,sparkle_LED4,sparkle_LED5};
void Control_LED(enum LED_ST state);
void LED_init();
#endif
