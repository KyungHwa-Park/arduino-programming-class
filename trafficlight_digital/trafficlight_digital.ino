// 디지털 방식으로 신호등 만들기

int red = 13;
int yellow = 12;
int green = 8;

void setup() {
  Serial.begin(9600);
  pinMode(red,OUTPUT);
  pinMode(yellow,OUTPUT);
  pinMode(green,OUTPUT);
}

void loop() {
  // 빨강색 LED 점등
  digitalWrite(red, HIGH);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
  delay(1000);

  // 노랑색 LED 점등
  digitalWrite(red, LOW);
  digitalWrite(yellow, HIGH);
  digitalWrite(8, LOW);
  delay(1000);

  // 초록색 LED 점등
  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(green, HIGH);
  delay(1000);

}
