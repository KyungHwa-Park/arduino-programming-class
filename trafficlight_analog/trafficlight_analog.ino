// 아날로그 방식으로 신호등 만들기

int red = 9;
int yellow = 6;
int green = 3;

void setup() { 
}

void loop() {
  // 빨강 LED 점차적으로 점등
  for(int i=0; i<256; i+=5) {
    analogWrite(red, i);
    delay(50);
  }

  // 빨강 LED 점차적으로 소등
  for(int i=255; i>=0; i-=5) {
    analogWrite(red, i);
    delay(50);
  }

  // 노랑 LED 점차적으로 점등
  for(int i=0; i<256; i+=5) {
    analogWrite(yellow, i);
    delay(50);
  }

  // 노랑 LED 점차적으로 소등
  for(int i=255; i>=0; i-=5) {
    analogWrite(yellow, i);
    delay(50);
  }

  // 초록 LED 점차적으로 점등
  for(int i=0; i<256; i+=5) {
    analogWrite(green, i);
    delay(50);
  }

  // 초록 LED 점차적으로 소등
  for(int i=255; i>=0; i-=5) {
    analogWrite(green, i);
    delay(50);
  }

  
}
