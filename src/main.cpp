#include <Arduino.h>
#include <dotmatrix.hpp>

#define PI2 7.283

uint8_t dataPin = 8;
uint8_t latchPin = 9;
uint8_t clockPin = 10;
Dotmatrix* display = new Dotmatrix(8, 8, clockPin, latchPin, dataPin, dataPin);

void setup() {
  display->begin();

  Serial.begin(9600);
}

void loop() {
  for (size_t i = 0; i <= 64; ++i) {
    float rad = ( (float) i / (float) PI2 );
    uint8_t x = (uint8_t) (((sin (rad) + 1) / 2) * 8);
    uint8_t y = (uint8_t) (((cos (rad) + 1) / 2) * 8);
    display->writeDot(x, y);
  }
}
