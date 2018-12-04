void setup() {
}

void loop() {
//  analogWrite(9, 0);
//  delay(500);
//  analogWrite(9, 63);
//  delay(500);
//  analogWrite(9, 127);
//  delay(500);
//  analogWrite(9, 255);
//  delay(500);
//  analogWrite(9, 127);
//  delay(500);
//  analogWrite(9, 63);
//  delay(500);

  for(int i=0; i<256; i++) {
    analogWrite(9, i);
    delay(50);
  }
  
  for(int i=255; i>=0; i--){
    analogWrite(9, i);
    delay(50);
  }
}
