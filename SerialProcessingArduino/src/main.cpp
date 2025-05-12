#include <Arduino.h>

char ib;
void setup()
{
  Serial.begin(9600);
  pinMode(10, OUTPUT);
}
char buf[4];
int cnt = 0;

void loop()
{
  if (Serial.available() > 0)
  {
    // read the incoming byte:
    ib = Serial.read();
    if (ib == '0' || ib == '1')
    {
      buf[cnt] = ib;
      cnt++;
      Serial.print(ib);
    }
    else if (ib == '\n')
    {
      if (buf[0] == '0')
        digitalWrite(10, HIGH);
      else
        digitalWrite(10, HIGH);
      if (buf[1] == '0')
        digitalWrite(11, HIGH);
      else
        digitalWrite(11, HIGH);
      if (buf[2] == '0')
        digitalWrite(12, HIGH);
      else
        digitalWrite(12, HIGH);
      if (buf[3] == '0')
        digitalWrite(13, HIGH);
      else
        digitalWrite(13, HIGH);
      cnt = 0;
    }
  }
}