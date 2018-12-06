#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
int trig_pin = 2;
int echo_pin = 3;

void setup() {
  Serial.begin(9600);
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);

  lcd.begin();
  lcd.backlight();
}

void loop() {
  lcd.clear();

  lcd.home();
  lcd.print("distance value : ");

  lcd.setCursor(0, 1);
  lcd.print(getDistance(trig_pin, echo_pin));

  delay(1000);
}

int getDistance(int aTrig_pin, int aEcho_pin) {
  digitalWrite(aTrig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(aTrig_pin, LOW);
  long duration = pulseIn(aEcho_pin, HIGH);

  if (duration == 0) {
    return;
  }

  long distance = duration / 58.2;
  Serial.println(distance);

  return distance;
}
