#include <dht11.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
 
int DHT11PIN = A0;            //Signal 이 연결된 아두이노의 핀번호
LiquidCrystal_I2C lcd(0x27, 16, 2);
 
dht11 DHT11;
  
void setup() {
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
}
  
void loop() {
  int chk = DHT11.read(DHT11PIN);

  float tem = DHT11.temperature;
  float hum = DHT11.humidity;
  float emotion = 9/5*tem - 0.55*(100-hum)/100 *(9/5*tem-26) * 32;

  String state;
  if (emotion>=80) {
    state = "very high";
  } else if (emotion>=75 && emotion<80) {
    state = "high";
  } else if (emotion>=68 && emotion<75) {
    state = "median";
  } else if (emotion<68) {
    state = "low";
  }
  lcd.clear();
  lcd.home(); 
  lcd.print(tem);
  lcd.print("C/ ");
  lcd.print(hum);
  lcd.print("%");
  lcd.setCursor(0,1);
  lcd.print("level : ");
  lcd.print(state);
  delay(2000);
  
  Serial.print("Temp: ");
  Serial.print((float)DHT11.temperature);
  Serial.print(" C ");
   
  Serial.print("/ RelF: ");
  Serial.print((float)DHT11.humidity);
  Serial.print(" %");

   Serial.print("불쾌지수 : ");
  Serial.print(emotion);
 
  Serial.println();
   
}
