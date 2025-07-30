#include "UART.h"
#include "lib.h"
#include "string.h"
#include <stdlib.h>

uint8_t USART_RXBUF_OPENMV[5];


// struct OPENMV_Data Openmv=
// {
//     .head1=0xA5,
//     .head2=0xA6,
//     .tail=0x5A
// };
struct XunJi_Data Xunji=
{

};


//printf重定向
int fputc(int c, FILE* stream)
{
	DL_UART_Main_transmitDataBlocking(UART_OPENMV_INST, c);
    return c;
}

int fputs(const char* restrict s, FILE* restrict stream)
{
    uint16_t i, len;
    len = strlen(s);
    for(i=0; i<len; i++)
    {
        DL_UART_Main_transmitDataBlocking(UART_OPENMV_INST, s[i]);
    }
    return len;
}

int puts(const char *_ptr)
{
int count = fputs(_ptr, stdout);
count += fputs("\n", stdout);
return count;
}

void NVIC_INIT(IRQn_Type UART0_INT_IRQn)
{
    // NVIC_ClearPendingIRQ(UART0_INT_IRQn);
    NVIC_EnableIRQ(UART0_INT_IRQn);
}

// void Uart_Run_OPENMV(void)
// {
//     static uint8_t i = 0;
//     uint8_t Res;
//     static uint8_t  flag =1;
//     Res = DL_UART_Main_receiveData(UART_OPENMV_INST);
//     if(Res == 0xA5&&flag == 1)
//         flag = 2;
//     else if(Res == 0xA6 && flag == 2)
//         flag =3;
//     else if (flag ==3)
//     {
//         if(Res != 0x5A)
//         {
//             USART_RXBUF_OPENMV[i++] = Res;
//         }
//         else if(Res == 0xA5)
//         {
//             Openmv.data1=USART_RXBUF_OPENMV[0];
//             Openmv.data2=USART_RXBUF_OPENMV[1];
//             Openmv.data3=USART_RXBUF_OPENMV[2];
//             Openmv.data4=USART_RXBUF_OPENMV[3];
//             Openmv.data5=USART_RXBUF_OPENMV[4];
//             i = 0;
//             flag=1;
//         }
//     }
    
//     else
//     {
//         i = 0;
//         flag=1;
//     }
// }
