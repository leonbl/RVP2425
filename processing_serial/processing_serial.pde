import processing.serial.*;
import java.nio.ByteBuffer;
Serial myPort; 

void setup(){
  size(600,400);
  printArray(Serial.list());
  myPort = new Serial(this, Serial.list()[1], 115200);
  size(400, 400);
  textSize(24);
  fill(#AA9A3E);
  text("setp.:", 10, 20); 
  fill(#811B1B);
  text("    y:", 10, 50);
  fill(#1B8143);
  text("    u:", 10, 80);
}


void draw(){
  float s=0.0,y=0.0,u=0.0;
  byte[] inFloat = new byte[5];
  while (myPort.available() > 0) {
    byte[] inBuffer = new byte[15];
    myPort.readBytesUntil('\n', inBuffer);
    println(inBuffer);
    switch (inBuffer[0]){
      case 's':
      for(int n = 0; n<4; n++){
        inFloat[n] = inBuffer[n+1];
      }
      s = ByteBuffer.wrap(inFloat).getFloat();
      println(s); 
      break;
            case 'y':
      for(int n = 0; n<4; n++){
        inFloat[n] = inBuffer[n+1];
      }
      y = ByteBuffer.wrap(inFloat).getFloat();
      println(y); 
      break;
            case 'u':
      for(int n = 0; n<4; n++){
        inFloat[n] = inBuffer[n+1];
      }
      u = ByteBuffer.wrap(inFloat).getFloat();
      println(u); 
      break;
      default: break;
    }
    setText(s,y,u);
  }
}

void setText(float a, float b, float c){
  fill(#AA9A3E);
  text(a, 80, 20); 
  fill(#811B1B);
  text(b, 80, 50);
  fill(#1B8143);
  text(c, 80, 80);
}
