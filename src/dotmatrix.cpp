#include "dotmatrix.hpp"
#include <Arduino.h>
#include <limits.h>

Dotmatrix::Dotmatrix() {
  width = 8;
  height = 8;
  clockPin = 10;
  latchPin = 9;
  xDataPin = 8;
  yDataPin = 7;
}

Dotmatrix::Dotmatrix(uint16_t width, uint16_t height, uint8_t clockPin, uint8_t latchPin,
          uint8_t xDataPin, uint8_t yDataPin) {
  this->width = width;
  this->height = height;
  this->clockPin = clockPin;
  this->latchPin = latchPin;
  this->xDataPin = xDataPin;
  this->yDataPin = yDataPin;
}

void Dotmatrix::begin() {
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(xDataPin, OUTPUT);
  pinMode(yDataPin, OUTPUT);

  digitalWrite(clockPin, LOW);
  digitalWrite(latchPin, LOW);
  digitalWrite(xDataPin, LOW);
  digitalWrite(yDataPin, LOW);
}

void Dotmatrix::writeDot(uint16_t xPosition, uint16_t yPosition) {
  if (xPosition <= width && yPosition <= height) {
    writePattern(1 << xPosition, 1 << yPosition);
  }
}

void Dotmatrix::writePattern(uint16_t xPattern, uint16_t yPattern) {
  digitalWrite(latchPin, LOW);
  shiftOut(xDataPin, clockPin, MSBFIRST, xPattern xor UINT_MAX);
  shiftOut(yDataPin, clockPin, MSBFIRST, yPattern);
  digitalWrite(latchPin, HIGH);
}

uint16_t Dotmatrix::getWidth() {return width;}
uint16_t Dotmatrix::getHeight() {return height;}
void Dotmatrix::setClockPin(uint8_t clockPin) {this->clockPin = clockPin;}
void Dotmatrix::setLatchPin(uint8_t latchPin) {this->latchPin = latchPin;}
void Dotmatrix::setXDataPin(uint8_t xDataPin) {this->xDataPin = xDataPin;}
void Dotmatrix::setYDataPin(uint8_t yDataPin) {this->yDataPin = yDataPin;}
