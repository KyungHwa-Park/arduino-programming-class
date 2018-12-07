#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
int sound_pin = A0;

void setup() {
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
  lcd.clear();
  lcd.print("(^^)");
}

void loop() {
  int sound_value=analogRead(sound_pin);
  
  Serial.print("sound value : ");
  Serial.println(sound_value);
  
  if(sound_value>500){
    lcd.scrollDisplayRight();
  }
  delay(100);
}
