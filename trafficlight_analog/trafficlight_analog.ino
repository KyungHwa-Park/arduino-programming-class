void setup() {
  
}

void loop() {
  for(int i=0; i<256; i+=5) {
    analogWrite(9, i);
    delay(50);
  }
  for(int i=255; i>=0; i-=5) {
    analogWrite(9, i);
    delay(50);
  }

  for(int i=0; i<256; i+=5) {
    analogWrite(6, i);
    delay(50);
  }

  for(int i=255; i>=0; i-=5) {
    analogWrite(6, i);
    delay(50);
  }

  for(int i=0; i<256; i+=5) {
    analogWrite(3, i);
    delay(50);
  }

  for(int i=255; i>=0; i-=5) {
    analogWrite(3, i);
    delay(50);
  }

  
}
