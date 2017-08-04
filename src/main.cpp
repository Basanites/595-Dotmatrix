#include "Arduino.h"

uint8_t dataPin = 8;
uint8_t clockPin = 10;
uint8_t latchPin = 9;

void setup() {
  // set shift register pins as OUTPUT
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);

  // pull all pins LOW to avoid weird behaviour
  digitalWrite(dataPin, LOW);
  digitalWrite(clockPin, LOW);
  digitalWrite(latchPin, LOW);

  // turn off all dotmatrix leds
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 0);
  shiftOut(dataPin, clockPin, MSBFIRST, 0);
  digitalWrite(latchPin, HIGH);

  Serial.begin(9600);
}

void loop() {
  for (int j = 1; j <= 128; j = j * 2) {
    for (int i = 1; i <= 128; i = i * 2) {
      Serial.println(i);
      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, MSBFIRST, j xor 255);
      shiftOut(dataPin, clockPin, MSBFIRST, i);
      digitalWrite(latchPin, HIGH);
      delay(25);
    }
  }
}
