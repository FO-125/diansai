#ifndef __XUNJI_H
#define __XUNJI_H
extern int CentrePWM;
extern int YawPWMout;
enum Path{AB=0,CD,AC,BD};
void getGpioValue();
void ClearXunValue();
void Xunji_Data_Run();
int GetXunJIErr(void);
void XunJIPIDConcrolTurn(uint16_t EncoderNumber);
void ControlSinAngle(float targetAngle,uint16_t EncoderNumber,enum Path);


#endif
