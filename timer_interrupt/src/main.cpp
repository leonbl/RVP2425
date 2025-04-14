#include <Arduino.h>

ISR(TIMER1_COMPA_vect){
  digitalWrite(13, !digitalRead(13));
}

void setup() {
  pinMode(13, OUTPUT);
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;
  OCR1A = 31250;
  TCCR1B |= 1 << WGM12;
  TCCR1B |= 1 << CS12;
  TIMSK1 |= 1 << OCIE1A;
  sei();
}

void loop() {

}

