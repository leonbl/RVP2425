#include <Arduino.h>

void setup()
{
  Serial.begin(9600);
}

float measureTemp()
{
  uint32_t nap = analogRead(12);
  float resist = 10000 * (((float)4096 / (float)nap) - 1.0);
  float steinhart;
  steinhart = resist / 10000;
  steinhart = log(steinhart);
  steinhart /= 3435;
  steinhart += 1.0 / 298.15;
  steinhart = 1.0 / steinhart;
  float tempK = steinhart;
  float tempC = tempK - 273.15;
  return tempC;
}

void loop()
{
  float tempSum = 0;
  for (int n = 0; n < 10; n++)
  {
    tempSum += measureTemp();
  }
  tempSum /= 10;
  Serial.println(tempSum);
  delay(500);
}