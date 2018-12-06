// LCD로 Wink 애니메이션 표현하기

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.begin();
  lcd.backlight();
}

void loop() {
  lcd.home();
  lcd.print("(^o^) @ (^_-)");
  delay(1000);
  lcd.clear();
  
  lcd.home();
  lcd.print("(-_^) @ (^o^)");
  delay(1000);
  lcd.clear();

}
