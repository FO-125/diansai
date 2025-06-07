#include "lib.h"
#include "string.h"
float QYaw;
float QYaw1;
float QYaw1Init;
uint8_t USART_RXBUF_OPENMV[5];
uint8_t USART_RXBUF_TuoLuoYi[20];
char USART_RXBUF_XunJi[41];
struct OPENMV_Data Openmv=
{
    .head1=0xA5,
    .head2=0xA6,
    .tail=0x5A
};
struct XunJi_Data Xunji=
{
    .head='$',
    
    .tail='#'
};

//printf重定向
int fputc(int c, FILE* stream)
{
	DL_UART_Main_transmitDataBlocking(UART_0_INST, c);
    return c;
}

int fputs(const char* restrict s, FILE* restrict stream)
{
    uint16_t i, len;
    len = strlen(s);
    for(i=0; i<len; i++)
    {
        DL_UART_Main_transmitDataBlocking(UART_0_INST, s[i]);
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

void Uart_Run_OPENMV(void)
{
    static uint8_t i = 0;
    uint8_t Res;
    static uint8_t  flag =1;
    Res = DL_UART_Main_receiveData(UART_OPENMV_INST);
    if(Res == 0xA5&&flag == 1)
        flag = 2;
    else if(Res == 0xA6 && flag == 2)
        flag =3;
    else if (flag ==3)
    {
        if(Res != 0x5A)
        {
            USART_RXBUF_OPENMV[i++] = Res;
        }
        else if(Res == 0xA5)
        {
            Openmv.data1=USART_RXBUF_OPENMV[0];
            Openmv.data2=USART_RXBUF_OPENMV[1];
            Openmv.data3=USART_RXBUF_OPENMV[2];
            Openmv.data4=USART_RXBUF_OPENMV[3];
            Openmv.data5=USART_RXBUF_OPENMV[4];
            i = 0;
            flag=1;
        }
    }
    
    else
    {
        i = 0;
        flag=1;
    }
}


//获取角度
void Uart_Run_TuoLuoYi()
{
    static uint8_t i = 0;
    uint8_t Res;
    float CarAngleYaw;
    short Yawangle;
    static uint8_t  flag =1;
    Res = DL_UART_Main_receiveData(UART_TuoLuoYi_INST);
    if(Res == 0x55&&flag == 1)
        flag = 2;
    else if(Res == 0x53 && flag == 2)
        flag =3;
    else if (flag ==3)//开始接收数据
    {
        if(Res != 0x55)//直到接收到另一组数据结束
        {
            USART_RXBUF_TuoLuoYi[i++] = Res;
        }
        else if(Res == 0x55)
        {
        //开始提取角度数据
            Yawangle =  (short)((uint16_t)USART_RXBUF_TuoLuoYi[5]<<8 | USART_RXBUF_TuoLuoYi[4]);
            CarAngleYaw = ((short)Yawangle)/32768.0f*180.0f;
            QYaw = CarAngleYaw;
            QYaw1 = (sin(CarAngleYaw*3.1416/180))*100;      
            i = 0;
            flag=1;
        }
    }
    else
    {
        i = 0;
        flag=1;

    }
}

void Uart_Run_XunJi()
{
    static uint8_t i = 0;
    char Res;
    static uint8_t  flag =1;
    Res = DL_UART_Main_receiveData(UART_OPENMV_INST);
    if(Res == '$'&&flag == 1)
        flag = 2;
    else if (flag ==2)
    {
        if(Res != '#')
        {
            USART_RXBUF_XunJi[i++] = Res;
        }
        else if(Res == '#')
        {
            Xunji.X1=USART_RXBUF_XunJi[5];
            Xunji.X1=USART_RXBUF_XunJi[10];
            Xunji.X1=USART_RXBUF_XunJi[15];
            Xunji.X1=USART_RXBUF_XunJi[20];
            Xunji.X1=USART_RXBUF_XunJi[25];
            Xunji.X1=USART_RXBUF_XunJi[30];
            Xunji.X1=USART_RXBUF_XunJi[35];
            Xunji.X1=USART_RXBUF_XunJi[40];
            i = 0;
            flag=1;
        }
    }
    
    else
    {
        i = 0;
        flag=1;
    }
}
    


void UART_OPENMV_INST_IRQHandler(void)
{
    DL_Timer_startCounter(TIMER_MS_UART_INST);
}

void UART_TuoLuoYi_INST_IRQHandler()
{
    DL_Timer_startCounter(TIMER_MS_UART_INST);
}