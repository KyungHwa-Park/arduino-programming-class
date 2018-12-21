#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
  keypad.addEventListener(listener);
}

void loop() {
  char key = keypad.getKey();

  if(key != NO_KEY) {
    Serial.println(key);
  }
}

void listener(KeypadEvent key) {
  switch(keypad.getState()) {
    case PRESSED:
      if(key == '#') {
        Serial.println("PRESSED");
      }
      break;
     case RELEASED:
      if(key == '*') {
        Serial.println("RELEASED");
      }
      break;
     case HOLD:
      if(key == '*') {
        Serial.println("HOLDING");
      }
  }
  }
