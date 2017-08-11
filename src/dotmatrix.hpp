#ifndef _dotmatrix_hpp_
#define _dotmatrix_hpp_

#include <inttypes.h>

/// Contains information about a dotmatrix display
class Dotmatrix {
public:
  Dotmatrix();
  Dotmatrix(uint16_t width, uint16_t height, uint8_t clockPin, uint8_t latchPin,
            uint8_t xDataPin, uint8_t yDataPin);
  void begin();
  void writeDot(uint16_t xPosition, uint16_t yPosition);
  void writePattern(uint16_t xPattern, uint16_t yPattern);

  uint16_t getWidth();
  uint16_t getHeight();
  void setClockPin(uint8_t clockPin);
  void setLatchPin(uint8_t latchPin);
  void setXDataPin(uint8_t xDataPin);
  void setYDataPin(uint8_t yDataPin);

private:
  uint8_t clockPin;
  uint8_t latchPin;
  uint8_t xDataPin;
  uint8_t yDataPin;
  uint16_t width;
  uint16_t height;
};

#endif
