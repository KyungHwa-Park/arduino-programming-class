void setup() {
  Serial.begin(9600);
  
}

void loop() {
  int light =  analogRead(A0);
  // 센서 범위와 아날로드 출력값 범위 사이에 존재하는 격차를 수정하기 위한 코드 (mapping)
  // (값을 원래 있던 범위에서 다른 범위 기준으로 바꿔줄 때 사용하는 함수)
//  int ledLight = map(light, 0, 516, 0, 255);
//  analogWrite(9, ledLight);

  int hertz = map(light, 0, 1023, 31, 4978);
  tone(8, hertz, 100);
  Serial.println(light);
  delay(100);
  noTone(8);
  delay(200);
}
