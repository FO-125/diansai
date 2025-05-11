#ifndef __PID_H
#define __PID_H


#endif
float outer_pid_controller(float setpoint, float input, float kp, float ki, float kd, float dt) ;
float inner_pid_controller(float setpoint, float input, float kp, float ki, float kd, float dt);
float double_pid_controller(float setpoint, float input, float outer_kp, float outer_ki, float outer_kd, float inner_kp, float inner_ki, float inner_kd, float dt) ;
