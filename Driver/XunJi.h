#ifndef __XUNJI_H
#define __XUNJI_H
extern int CentrePWM;
extern int YawPWMout;
void getGpioValue();
void ClearXunValue();
void Xunji_Data_Run();
int GetXunJIErr(void);
void XunJIPIDConcrolTurn(uint16_t EncoderNumber);
void ControlSinAngleA_B(float targetAngle,uint16_t EncoderNumber);
void ControlSinAngleC_D(float targetAngle,uint16_t EncoderNumber);

#endif
