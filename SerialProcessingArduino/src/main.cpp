#include <Arduino.h>

char ib;
void setup()
{
  Serial.begin(115200);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}


void loop()
{
  Serial.print('s');
  Serial.println(random(1000)/100.0);
  Serial.print('y');
  Serial.println(random(1000)/100.0);
  Serial.print('u');
  Serial.println(random(1000)/100.0);    
//   if (Serial.available() > 0)
//   {
//     // read the incoming byte:
//     ib = Serial.read();
//     cmdbuff[indx]=ib;
//     if(ib=='@'){
//       indx = 0;
//       parse_cmd();
//     }
//   }
 }