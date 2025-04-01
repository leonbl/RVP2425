#include <Arduino.h>
#define VKLOP 0 // definiramo novo oznako
#define IZKLOP 1 // prvajalnik bo pred začetkom prevajanja povsod
                 // v programu IZKLOP zamenjal z 1

// funkcija, ki se izvede samo enkrat
void setup() {
  pinMode(13,OUTPUT); // nastavimo smer prenosa podatkov na pinu 13
}

// funkcija, ki svojo kodo izvaja neprestano
void loop() {
  digitalWrite(13,VKLOP); // na pin 13 damo logično stanje 0
  delay(1000);
  digitalWrite(13,IZKLOP);
  delay(1000);
}
