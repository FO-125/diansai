#ifndef __MOTOR_QEI_H
#define __MOTOR_QEI_H

// void QEI_INIT(IRQn_Type GPIO_MOTOR_QEI_GPIOA_INT_IRQN);
extern int32_t Front_Left_Count ;
extern int32_t Front_Right_Count ;
extern int32_t Back_Left_Count ;
extern int32_t Back_Right_Count ;
extern volatile int32_t QFL;
extern volatile int32_t QFR;
extern int32_t Average_count;
extern int Start_Count;
int Get_QEI_FL();
int Get_QEI_FR();
int Get_QEI_BL();
int Get_QEI_BR();
#endif

