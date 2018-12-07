int sound_pin = A0;
int red = 8;
int yellow = 12;
int green = 13;

int count_max = 0;

void setup() {
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop() {
  int sound_value=analogRead(sound_pin);
//  int light_value=map(sound_value, 0, 1023, 0, 255);
  Serial.print("sound value : ");
  Serial.println(sound_value);

  if(sound_value >= 700) {
    ++count_max;
    Serial.println(count_max);
  }
  
  if(count_max>=0 && count_max<5) {
    digitalWrite(green, HIGH);
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
    
  } else if (count_max>=5 && count_max<10) {
    digitalWrite(green, LOW);
    digitalWrite(yellow, HIGH);
    digitalWrite(red, LOW);
  } else if (count_max>=10 && count_max<20) {
    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);
  }else{
    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
    
  }
  delay(100);
}
