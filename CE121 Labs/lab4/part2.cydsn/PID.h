#ifndef PID_H
#define PID_H
#define MANUAL 0
#define AUTOMATIC 1
int    PID_toggle        ();
int    PID_mode          ();
void   set_PID_mode      (int mode);
void   set_PID_input     (double newInput);
void   set_PID_setpoint  (double newSetpoint);
void   set_PID_tunings   (double Kp, double Ki, double Kd);
void   set_PID_limits    (double Min, double Max);
void   PID_controller    ();
double PID_output        ();
#endif