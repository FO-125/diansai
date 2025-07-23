#ifndef __LED_H
#define __LED_H

enum LED_ST{enable_LED=0,disable_LED};
void Control_LED(enum LED_ST state);
void LED_init();
#endif
