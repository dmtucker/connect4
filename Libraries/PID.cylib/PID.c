#include <stdbool.h>
#include <PID.h>




int mode = MANUAL;
double Input, Output, Setpoint;
double kp, ki, kd;
double ITerm, lastInput;
double outMin, outMax;




uint8 PID_toggle () {
    set_PID_mode((mode == MANUAL) ? AUTOMATIC : MANUAL);
    return mode;
}




uint8 PID_mode () {
    return mode;
}




void set_PID_mode ( uint8 newMode ) {
    if (newMode == AUTOMATIC && mode != AUTOMATIC) {
        lastInput = Input;
        ITerm     = Output;
        if      (ITerm > outMax) ITerm = outMax;
        else if (ITerm < outMin) ITerm = outMin;
    }
    mode = newMode;
}




void set_PID_input ( double newInput ) {
    Input = newInput;
}




void set_PID_setpoint ( double newSetpoint ) {
    Setpoint = newSetpoint;
    if      (Setpoint > outMax) Setpoint = outMax;
    else if (Setpoint < outMin) Setpoint = outMin;
}




void set_PID_tunings ( double Kp , double Ki , double Kd ) {
    kp = Kp;
    ki = Ki;
    kd = Kd;
}




void set_PID_limits ( double min , double max ) {
   if (min > max) return;
   outMin = min;
   outMax = max;
 
   if      (Output > outMax) Output = outMax;
   else if (Output < outMin) Output = outMin;
 
   if      (ITerm > outMax) ITerm = outMax;
   else if (ITerm < outMin) ITerm = outMin;
}




void PID_controller () {
    if (mode != AUTOMATIC) return;
    
    // Proportional
    double error = Setpoint - Input;
    
    // Integral
    ITerm += ki*error;
    if      (ITerm > outMax) ITerm = outMax;
    else if (ITerm < outMin) ITerm = outMin;
    
    // Derivative
    double dInput = Input-lastInput;
    lastInput = Input;

    // controller
    Output = kp*error + ITerm - kd*dInput;
    if      (Output > outMax) Output = outMax;
    else if (Output < outMin) Output = outMin;
}




double PID_output () {
    return Output;
}
