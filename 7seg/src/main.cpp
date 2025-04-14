#include <Arduino.h>
void sftclk(void);
void lchclk(void);

void setup() {
  pinMode(4, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  uint8_t byteLeft = 0x40;
  uint8_t byteRight = 0x00;
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
  delay(100);
}

void sftclk(void){
  digitalWrite(7, LOW);
  digitalWrite(7, HIGH);
}

void lchclk(void){
  digitalWrite(4, LOW);
  digitalWrite(4, HIGH);
}