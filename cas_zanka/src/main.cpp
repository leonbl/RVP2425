#include <Arduino.h>

#define USE_TIMER_1 true
#include "TimerInterrupt.h"

#define TIMER1_INTERVAL_MS 250

uint32_t trent_cas;

unsigned int outputPin = 12;

void TimerHandler1(unsigned int outputPin = LED_BUILTIN)
{
  trent_cas = millis();
  Serial.println(trent_cas);
  // digitalWrite(13, !digitalRead(13));
  // digitalWrite(12, !digitalRead(12));
  // digitalWrite(11, !digitalRead(11));
}

void setup()
{
  Serial.begin(9600);
  ITimer1.init();

 if(ITimer1.attachInterruptInterval(TIMER1_INTERVAL_MS, TimerHandler1, outputPin))
 {
   Serial.print(F("Starting  ITimer1 OK, millis() = "));
   Serial.println(millis());
 }
 else Serial.println(F("Can't set ITimer1. Select another freq. or timer"));
}

void loop()
{
}
