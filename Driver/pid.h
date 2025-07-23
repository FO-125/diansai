#ifndef __PID_H
#define __PID_H

// float outer_pid_controller(float setpoint, float input, float kp, float ki, float kd, float dt) ;
// float inner_pid_controller(float setpoint, float input, float kp, float ki, float kd, float dt);
// float double_pid_controller(float setpoint, float input, float outer_kp, float outer_ki, float outer_kd, float inner_kp, float inner_ki, float inner_kd, float dt) ;
typedef struct ControlServosPIDValue{
	float Target;
	float Actual;
	float Last_Actual;
	float Last_LastActual;
	float KP;
	float KI;	
	float KD;
	float ErrorInt;
    float Error;
	float LastError;
    float Last_LastError;
	float Difout;
    float out;
}S_PID;
extern S_PID PID_FL;
extern S_PID PID_FR;
extern S_PID PID_BL;
extern S_PID PID_BR;
extern S_PID PID_Yaw;
extern S_PID PID_Turn;
void PID_Init(S_PID* PID,float Kp,float Ki,float Kd);
void PID_Init_Wheel(float kp,float ki,float kd);
void PID_SetTaget(S_PID* PID,float taget);
void PID_Update_FL(S_PID* PID);
void PID_Update_FR(S_PID* PID);
void PID_Update_BL(S_PID* PID);
void PID_Update_BR(S_PID* PID);
int PID_Update_Yaw(S_PID* PID);
int PID_Update_Xunji(S_PID* PID);
#define KP_FL 0.2
#define KP_FR 0.2
#define KP_BL 0.2
#define KP_BR 0.2
#define KI_FL 1
#define KI_FR 1
#define KI_BL 1
#define KI_BR 1
#define KD_FL 0.2
#define KD_FR 0.2
#define KD_BL 0.2 
#define KD_BR 0.2
#define SinJiaoKP 100
#define SinJiaoKI 0
#define SinJiaoKD 0 
#define XunJi_KP 25
#define XunJi_KI 0
#define XunJi_KD 0
#define SinJiaoKPC_D 100
#define SinJiaoKIC_D 0
#define SinJiaoKDC_D 0
#endif
