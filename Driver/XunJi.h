#ifndef __XUNJI_H
#define __XUNJI_H
extern int CentrePWM;
extern int YawPWMout;
enum Path{anticlockwise=0,clockwise};
enum Near_End{near_end1=0,near_end2};
enum Middle_End{middle_end1=2,middle_end2};
enum Far_End{far_end_left1=4,far_end_left2,far_end_right1,far_end_right2};
enum Ward_num{Near_End,Middle_End,Far_End};
void getGpioValue();
void ClearXunValue();
void Xunji_Data_Run();
int GetXunJIErr(void);
void XunJIPIDConcrol(uint16_t EncoderNumber);
void ControlSinAngle(float targetAngle,uint16_t EncoderNumber,enum Path path);

#endif
