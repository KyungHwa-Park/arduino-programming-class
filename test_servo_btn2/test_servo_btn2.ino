#include <Servo.h>

Servo myservo;
int btn = 13;

void setup() {
  myservo.attach(9);
  pinMode(btn, INPUT);
}

void loop() {
  if(digitalRead(btn==HIGH)) {
    int val = analogRead(A0);
    int rad = map(val, 0, 1023, 0, 180);
    myservo.write(rad);
    delay(15);
  }  

}
