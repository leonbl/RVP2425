#include <Arduino.h>
uint32_t cnt = 0;

ISR(TIMER1_COMPA_vect)
{
  digitalWrite(13, !digitalRead(13));
  if (cnt++ % 4 == 0)
    digitalWrite(10, !digitalRead(10));
}

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(10, OUTPUT);
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;
  OCR1A = 7812;
  TCCR1B |= 1 << WGM12;
  TCCR1B |= 1 << CS12;
  TIMSK1 |= 1 << OCIE1A;
  sei();
}

void loop()
{
}
