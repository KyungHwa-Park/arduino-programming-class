int red = 13;
int yellow = 12;
int green = 8;
// 디지털 신호 입력 값을 저장할 변수
int a;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop() {
  // 13번 핀의 디지털 신호 입력 값을 읽습니다.
  a = digitalRead(red);
  // 상수 HIGH와 LOW를 이용해 입력 값을 확인합니다.
  if (a == HIGH) {
    digitalWrite(red, HIGH);
    digitalWrite(yellow, LOW);
    digitalWrite(green, LOW);
  } else {
    // 젂압이 LOW인 경우
  }
}
