// 자동차 후방 센서
// 초음파 센서를 통해 장애물과의 거리를 인지, LED 색으로 표현

// 초음파 센서
int trigger = 2;
int echo = 3;

// LED
int red = 8;      // 빨강색 : 위험
int yellow = 12;  // 노란색 : 경고
int green = 13;   // 초록색 : 안전

void setup() {
  Serial.begin(9600);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop() {
  // 초음파 센서로 거리를 감지
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  long duration = pulseIn(echo, HIGH);

  if (duration == 0) {
    return;
  }

  long distance = duration / 58.2;
  Serial.println(distance);

  if (distance >= 30) {   // 거리가 30 이상이면 녹색 LED 점등
    digitalWrite(red, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(green, HIGH);
  } else if (distance >=10 && distance <30) {   // 거리가 10 이상, 30 미만이면 노란색 LED 점등
    digitalWrite(red, LOW);
    digitalWrite(yellow, HIGH);
    digitalWrite(green, LOW);
  } else {    // 거리가 10미만이면 빨강색 LED 점등
    digitalWrite(red, HIGH);
    digitalWrite(yellow, LOW);
    digitalWrite(green, LOW);
  }
}
