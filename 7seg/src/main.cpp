#include <Arduino.h>
void sftclk(void);
void lchclk(void);
void display(uint8_t byteLeft, uint8_t byteRight);

uint8_t num = 0;

void setup() {
  pinMode(4, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;
  OCR1A = 625;
  TCCR1B |= 1 << WGM12;
  TCCR1B |= 1 << CS12;
  TIMSK1 |= 1 << OCIE1A;
  sei();
}

ISR(TIMER1_COMPA_vect)
{
  num++;
  display(0xf0, num);
}

void loop() {

}

void display(uint8_t byteLeft, uint8_t byteRight){
  for(int n=0; n<8; n++){
    digitalWrite(8, (byteRight & 0x01));
    byteRight = byteRight >> 1;
    sftclk();
  }
  for(int n=0; n<8; n++){
    digitalWrite(8, (byteLeft & 0x01));
    byteLeft = byteLeft >> 1;
    sftclk();
  }
  lchclk();
}

void sftclk(void){
  digitalWrite(7, LOW);
  digitalWrite(7, HIGH);
}

void lchclk(void){
  digitalWrite(4, LOW);
  digitalWrite(4, HIGH);
}