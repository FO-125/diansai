#ifndef __MOTOR_H
#define __MOTOR_H


#endif

void Motor_On(void);
void Motor_Off(void);
void Set_Speed(uint8_t side, int8_t duty);
void Motor_Ctrl(void);
extern int16_t rxbuf , cx ;
extern int16_t baseSpeed ;
extern int16_t SpeedL , SpeedR ;
extern float Kp ;