#include<Wire.h>
#include<LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
int pin_alcohol = A0;
int btn = 13;
int total=0;
int avg=0;

void setup() {
  Serial.begin(9600);
  lcd.begin();
  lcd.clear();
  pinMode(btn, INPUT);

  lcd.backlight();
  lcd.print("Start");
}

void loop() {
  int value = digitalRead(btn);

  if (value == HIGH) {
    test();
  }
}

void test() {
    for(int i=0; i<10; i++) {
      int alcohol = analogRead(pin_alcohol);
      total = total + alcohol;
      delay(1000);
      Serial.println(total);
    }
    avg = total/10;
    Serial.println(avg);
  
    if (avg >= 800) {
      lcd.clear();
      lcd.print("License Canceled");
    } else if(avg >=500 && avg <800) {
      lcd.clear();
      lcd.print("License Stop");
    } else {
      lcd.clear();
      lcd.print("Warning");
    }
}
