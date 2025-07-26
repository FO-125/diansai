#ifndef __UART_H
#define __UART_H
#include "stdio.h"
#include "stdint.h"
#include "ti_msp_dl_config.h"
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
    uint8_t  X1 ;
    uint8_t  X2 ;
    uint8_t  X3 ;
    uint8_t  X4 ;
    uint8_t  X5 ;
    uint8_t  X6 ;
    uint8_t  X7 ;
    uint8_t  X8 ;
};
// struct JY61P_Data
// {
//     uint8_t RxBuffer[11];/*接收数据数组*/
//     uint8_t RxData;
//     uint8_t RxState;/*接收状态标志位*/
//     uint8_t RxIndex;/*接受数组索引*/

//     int16_t Roll;
//     int16_t Pitch;
//     int16_t Yaw;
    
//     int16_t Roll_last;
//     int16_t Pitch_last;

//     int16_t Yaw_true;


//     float QYaw1;
//     float QYaw1Init;
// };
extern float QYaw;
extern float QYaw1;
extern float QYaw1Init;
extern struct JY61P_Data JY61P_Data;
extern struct OPENMV_Data Openmv;
extern struct XunJi_Data Xunji;
// void jy61p_Init(void);
void Uart_Run_OPENMV();
// void Uart_Run_TuoLuoYi();

int fputc(int c, FILE* stream);
int fputs(const char* restrict s, FILE* restrict stream);
int puts(const char *_ptr);
#endif
