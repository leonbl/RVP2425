#include <Arduino.h>
#define VKLOPI 0 
#define IZKLOPI 1

int staro_stanje = 1;
int stanje_led = 1;
int st_led = 10;

void zbrisi(void);

void setup() {
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(A1, INPUT);
  // Inicializacija in nastavitev hitrosti serijskega vmesnika  
  Serial.begin(9600);  
}


void loop() {
  int stanje = digitalRead(A1);
  if(staro_stanje == 1 && stanje == 0){
    Serial.println(st_led);
    st_led = st_led + 1;
    if(st_led > 13) st_led =10;
    delay(150);
  }
  
  zbrisi();
  digitalWrite(st_led, VKLOPI);
  staro_stanje = stanje;
}

void zbrisi(void){
  digitalWrite(10, IZKLOPI);
  digitalWrite(11, IZKLOPI);
  digitalWrite(12, IZKLOPI);
  digitalWrite(13, IZKLOPI);
}