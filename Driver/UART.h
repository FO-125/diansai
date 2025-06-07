#ifndef __UART_H
#define __UART_H
#include "stdio.h"
void NVIC_INIT(IRQn_Type UART0_INT_IRQn);

struct OPENMV_Data
{
    uint8_t head1;
    uint8_t head2;
    uint8_t data1;
    uint8_t data2;
    uint8_t data3;
    uint8_t data4;
    uint8_t data5;
    uint8_t tail;
};
struct XunJi_Data
{
    uint8_t head;
    uint8_t  X1 ;
    uint8_t  X2 ;
    uint8_t  X3 ;
    uint8_t  X4 ;
    uint8_t  X5 ;
    uint8_t  X6 ;
    uint8_t  X7 ;
    uint8_t  X8 ;
    uint8_t tail; 
};
extern float QYaw;
extern float QYaw1;
extern float QYaw1Init;
extern struct OPENMV_Data Openmv;
extern struct XunJi_Data Xunji;
void Uart_Run_OPENMV();
void Uart_Run_TuoLuoYi();
void Uart_Run_XunJi();
int fputc(int c, FILE* stream);
int fputs(const char* restrict s, FILE* restrict stream);
int puts(const char *_ptr);
#endif
