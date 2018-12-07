#include <Servo.h>

Servo myservo;
int btn = 13;
int val;

void setup() {
  myservo.attach(9);
  pinMode(btn, INPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println(digitalRead(btn));
  if(digitalRead(btn==HIGH)) {
    val = analogRead(A0);
  }  
  int rad = map(val, 0, 1023, 0, 180);
  myservo.write(rad);
  delay(15);

}
