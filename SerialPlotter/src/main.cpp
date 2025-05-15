#include <Arduino.h>
uint8_t line1=0, cnt1=0;
uint8_t line2=0, cnt2=0;
uint32_t old_t = 0;

void setup(){
    Serial.begin(9600);
}

void loop(){
    // get all of our variables of interest()
    float time = millis()/1000.0;
    uint32_t t = millis()/500;
    if(t > old_t){
      if(cnt1 == 0) line1 = 1;
      if(cnt1 == 1) line1 = 0;
      if(cnt1 == 3) {line1 = 1; cnt1 = 0;}
      cnt1++;
      if(cnt2 == 0) line2 = 3;
      if(cnt2 == 2) line2 = 2;
      if(cnt2 == 8) {line2 = 3; cnt2 = 0;}
      cnt2++;
    }
    old_t = t;
    // write them all to console with tabs in between them
    Serial.print(time);         // first variable is program time in seconds. This can be plotted on an x-axis!
    Serial.print("\t");
    Serial.print(line1);   // second variable is sin(t)
    Serial.print("\t");      // this last "\t" isn't required, but doesn't hurt
    Serial.println(line2); // third varible is cos(t). make sure to finish with a println!
    
    // For example, at 2.5 seconds, this prints out like so, where \t
    // is the tab character, and \n is the newline character
    // 2500\t0.598\t-0.801\t\n
}