#include <Arduino.h>

void setup(){
  Serial.begin(9600);
}

void loop()
{
  uint32_t nap = analogRead(12);
  float resist = 10000 *(((float)4096/(float)nap)-1.0);
  float steinhart;
  steinhart = resist / 10000;
  steinhart = log(steinhart);
  steinhart /= 3435;
  steinhart += 1.0 / 298.15;
  steinhart = 1.0 / steinhart;
  float tempK = steinhart;
  float tempC = tempK - 273.15;

  Serial.println(tempC);
  delay(500);

}