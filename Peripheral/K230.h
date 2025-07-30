#ifndef __K230_H
#define __K230_H

#include "ti_msp_dl_config.h"

typedef struct {
    float pitch;
    float roll;
    float yaw;
    float temperature;
    int16_t ax;
    int16_t ay;
    int16_t az;
    int16_t gx;
    int16_t gy;
    int16_t gz;
    int16_t version;
    float yawInit;
} K230_Data_t;

extern K230_Data_t k230_data;

void K230_Init(void);

#endif /* #ifndef __K230_H */