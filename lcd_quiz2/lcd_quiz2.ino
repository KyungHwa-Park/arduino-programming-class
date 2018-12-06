#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int btn_distance = 13;  //노란btn
int btn_light = 12;     //파랑 btn

int trig_pin = 2;
int echo_pin = 3;

void setup() {
  Serial.begin(9600);
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  pinMode(btn_light, INPUT);
  pinMode(btn_distance, INPUT);
  
  lcd.begin();
  lcd.backlight();
}

void loop() {
  lcd.clear();
  lcd.home();
  
  if(digitalRead(btn_light)==HIGH) { 
    lcd.print("light value : ");
    lcd.setCursor(0, 1);
    int light = analogRead(A0);
    Serial.println(light);
    lcd.print(light);
    
  } else if (digitalRead(btn_distance)==HIGH) {
    lcd.print("ditance value : ");
    lcd.setCursor(0, 1);
    Serial.println(getDistance(trig_pin, echo_pin));
    lcd.print(getDistance(trig_pin, echo_pin));
  } else {
    lcd.print("select btn");   
  }
   delay(1000);
}

int getDistance(int aTrig_pin, int aEcho_pin) {
  digitalWrite(aTrig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(aTrig_pin, LOW);
  long duration = pulseIn(aEcho_pin, HIGH);

  if(duration == 0) {
    return;
  }

  long distance = duration / 58.2;
  Serial.println(distance);

  return distance;
}
