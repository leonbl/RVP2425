#include <Arduino.h>
#define VKLOP 0  // definiramo novo oznako
#define IZKLOP 1 // prvajalnik bo pred začetkom prevajanja povsod
                 // v programu IZKLOP zamenjal z 1

// funkcija, ki se izvede samo enkrat
void setup()
{
  pinMode(10, OUTPUT); // nastavimo smer prenosa podatkov na pinu 13
}

// funkcija, ki svojo kodo izvaja neprestano
void loop()
{
  for (int n = 0; n < 256; n++)
  {
    analogWrite(10, n); // PWM nstavim na 0 (maksimalno 255)
    delay(4);
  }
}
