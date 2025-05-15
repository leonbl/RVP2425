#include <Arduino.h>

#include <PID_v1.h>

#define PIN_INPUT A1
#define PIN_OUTPUT 3

//Define Variables we'll be connecting to
double Setpoint, Input, Output;

//Specify the links and initial tuning parameters
double Kp=1, Ki=0, Kd=0;
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);
uint8_t moj_pwm = 0;

void setup()
{ 
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(9, OUTPUT);
  //initialize the variables we're linked to
  Input = analogRead(PIN_INPUT);
  Setpoint = 800;

  //turn the PID on
  myPID.SetMode(AUTOMATIC);
}

void setLeds(uint8_t pwm){
  analogWrite(9,pwm);
  analogWrite(10,pwm);
  analogWrite(11,pwm);
}

void loop()
{
  Input = analogRead(PIN_INPUT);
  Serial.println(Input);
  myPID.Compute();
  setLeds(Output);
}


