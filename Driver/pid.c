#include "lib.h"

float outer_pid_controller(float setpoint, float input, float kp, float ki, float kd, float dt) {
    static float integral = 0;
    static float prev_error = 0;
    float error = setpoint - input;

    // 计算积分项
    integral += error * dt;

    // 计算微分项
    float derivative = (error - prev_error) / dt;

    // 计算输出
    float output = kp * error + ki * integral + kd * derivative;

    // 更新上一个误差
    prev_error = error;

    return output;
}

float inner_pid_controller(float setpoint, float input, float kp, float ki, float kd, float dt) {
    static float integral = 0;
    static float prev_error = 0;
    float error = setpoint - input;

    // 计算积分项
    integral += error * dt;

    // 计算微分项
    float derivative = (error - prev_error) / dt;

    // 计算输出
    float output = kp * error + ki * integral + kd * derivative;

    // 更新上一个误差
    prev_error = error;

    return output;
}

float double_pid_controller(float setpoint, float input, float outer_kp, float outer_ki, float outer_kd, float inner_kp, float inner_ki, float inner_kd, float dt) {
    // 计算外环控制器输出
    float outer_output = outer_pid_controller(setpoint, input, outer_kp, outer_ki, outer_kd, dt);

    // 计算内环控制器输出
    float inner_output = inner_pid_controller(outer_output, input, inner_kp, inner_ki, inner_kd, dt);

    return inner_output;
}

