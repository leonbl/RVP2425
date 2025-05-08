import processing.serial.*;
Serial myPort; 

void setup(){
  size(600,400);
  printArray(Serial.list());
  myPort = new Serial(this, Serial.list()[1], 9600);
}

void draw(){
  myPort.write('B');
  while (myPort.available() > 0) {
    char inByte = (char)myPort.read();
    print(inByte);
  }
  println();
  delay(1000);
}
