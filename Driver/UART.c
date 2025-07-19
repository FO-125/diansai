#include "lib.h"
#include "string.h"
#include <stdlib.h>

uint8_t USART_RXBUF_OPENMV[5];


struct OPENMV_Data Openmv=
{
    .head1=0xA5,
    .head2=0xA6,
    .tail=0x5A
};
struct XunJi_Data Xunji=
{

};
struct JY61P_Data JY61P_Data=
{
    .RxIndex=0,
    .RxState=0,
    .QYaw1Init=0
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

void jy61p_Init(void)

{

    NVIC_ClearPendingIRQ(UART_TuoLuoYi_INST_INT_IRQN);

    NVIC_EnableIRQ(UART_TuoLuoYi_INST_INT_IRQN);

    DL_UART_clearInterruptStatus(UART_TuoLuoYi_INST,GPIO_UART_TuoLuoYi_IOMUX_RX_FUNC);//清除中断标志位

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
    JY61P_Data.Roll_last=JY61P_Data.Roll;
    JY61P_Data.Pitch_last=JY61P_Data.Pitch;
    JY61P_Data.RxData = DL_UART_receiveData(UART_TuoLuoYi_INST);
    uint8_t i,sum=0;
    if (JY61P_Data.RxState == 0)   //等待包头
    {
        if (JY61P_Data.RxData == 0x55) //收到包头
        {
            JY61P_Data.RxBuffer[JY61P_Data.RxIndex] = JY61P_Data.RxData;
            JY61P_Data.RxState = 1;
            JY61P_Data.RxIndex = 1; //进入下一状态
        }
    }
    
    else if (JY61P_Data.RxState == 1)
    {
        if (JY61P_Data.RxData == 0x53) /*判断数据内容，0x53为角度输出*/
        {
            JY61P_Data.RxBuffer[JY61P_Data.RxIndex] = JY61P_Data.RxData;
            JY61P_Data.RxState = 2;
            JY61P_Data.RxIndex = 2; //进入下一状态
        }
    }
    else if (JY61P_Data.RxState == 2)  //接收数据
    {
        JY61P_Data.RxBuffer[JY61P_Data.RxIndex++] = JY61P_Data.RxData;
        if(JY61P_Data.RxIndex == 11)   //接收完成
        {
            // for(i=0;i<10;i++)
            // {
            //     sum = sum + JY61P_Data.RxBuffer[i]; //计算校验和
            // }
            // if(sum ==JY61P_Data.RxBuffer[10])     //校验成功
            // {
            JY61P_Data.Roll = ((int16_t) ((int16_t) JY61P_Data.RxBuffer[3] << 8 | (int16_t) JY61P_Data.RxBuffer[2])) / 32768.0f * 180.0f;
            JY61P_Data.Pitch = ((int16_t) ((int16_t) JY61P_Data.RxBuffer[5] << 8 | (int16_t) JY61P_Data.RxBuffer[4])) / 32768.0f * 180.0f;
            JY61P_Data.Yaw = ((int16_t) ((int16_t) JY61P_Data.RxBuffer[7] << 8 | (int16_t) JY61P_Data.RxBuffer[6])) / 32768.0f * 180.0f;
                
            // }
            JY61P_Data.RxState = 0;

            JY61P_Data.RxIndex = 0; //读取完成，回到最初状态，等待包头
            if(abs(JY61P_Data.Yaw-JY61P_Data.Pitch_last)>2&&abs(JY61P_Data.Yaw-JY61P_Data.Roll_last)>2)
                JY61P_Data.Yaw_true=JY61P_Data.Yaw;
            JY61P_Data.QYaw1 = (sin(JY61P_Data.Yaw_true*3.1416/180))*100;      
        }

    }

}

    // uint16_t Point = 0;
    // for(int i=0;i<101;i++)
    // {
    //     USART_RXBUF_TuoLuoYi[i] = DL_UART_Main_receiveData(UART_TuoLuoYi_INST);
    // }
    // while (Point < 100)
    // {
    //   if (USART_RXBUF_TuoLuoYi[Point] == 0x55)
    //   {
    //     if (USART_RXBUF_TuoLuoYi[Point + 1] == 0x51)
    //     {
    //     }
    //     else if (USART_RXBUF_TuoLuoYi[Point + 1] == 0x52)
    //     {
    //       JY61P_Data.GYRO_X = (int16_t)((USART_RXBUF_TuoLuoYi[Point + 3] << 8) | USART_RXBUF_TuoLuoYi[Point + 2]) / 32768.0f * 180.0f;
    //       JY61P_Data.GYRO_Y = (int16_t)((USART_RXBUF_TuoLuoYi[Point + 5] << 8) | USART_RXBUF_TuoLuoYi[Point + 4]) / 32768.0f * 180.0f;
    //       JY61P_Data.GYRO_Z = (int16_t)((USART_RXBUF_TuoLuoYi[Point + 7] << 8) | USART_RXBUF_TuoLuoYi[Point + 6]) / 32768.0f * 180.0f;
    //       Point += 7;
    //     }
    //     else if (USART_RXBUF_TuoLuoYi[Point + 1] == 0x53)
    //     {
    //       JY61P_Data.Roll = (int16_t)((USART_RXBUF_TuoLuoYi[Point + 3] << 8) | USART_RXBUF_TuoLuoYi[Point + 2]) / 32768.0f * 180.0f;
    //       JY61P_Data.Pitch = (int16_t)((USART_RXBUF_TuoLuoYi[Point + 5] << 8) | USART_RXBUF_TuoLuoYi[Point + 4]) / 32768.0f * 180.0f;
    //       JY61P_Data.Yaw = (int16_t)((USART_RXBUF_TuoLuoYi[Point + 7] << 8) | USART_RXBUF_TuoLuoYi[Point + 6]) / 32768.0f * 180.0f;

    //       Point += 7;
    //     }
    //   }
    //   Point++;
    // }


    // static uint8_t i = 0;
    // uint8_t Res;
    // float CarAngleYaw;
    // static uint8_t  flag =1;
    // Res = DL_UART_Main_receiveData(UART_TuoLuoYi_INST);
    // if(Res == 0x55&&flag == 1)
    //     flag = 2;
    // else if(Res == 0x53 && flag == 2)
    //     flag =3;
    // else if (flag ==3)//开始接收数据
    // {
    //     if(Res != 0x55)//直到接收到另一组数据结束
    //     {
    //         USART_RXBUF_TuoLuoYi[i++] = Res;
    //     }
    //     else if(Res == 0x55)
    //     {
    //     //开始提取角度数据
    //         Yawangle =  (short)((uint16_t)USART_RXBUF_TuoLuoYi[5]<<8 | USART_RXBUF_TuoLuoYi[4]);
    //         CarAngleYaw = ((short)Yawangle)/32768.0f*180.0f;
    //         QYaw = CarAngleYaw;
    //         
    //         i = 0;
    //         flag=1;
    //     }
    // }
    // else
    // {
    //     i = 0;
    //     flag=1;

    // }


void UART_OPENMV_INST_IRQHandler(void)
{
    

}

void UART_TuoLuoYi_INST_IRQHandler()
{
    Uart_Run_TuoLuoYi();
}