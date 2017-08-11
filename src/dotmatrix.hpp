#ifndef _dotmatrix_hpp_
#define _dotmatrix_hpp_

#include <inttypes.h>

/// Contains information about a dotmatrix display
class Dotmatrix {
public:
  Dotmatrix();
  Dotmatrix(int width, int height, uint8_t clockPin, uint8_t latchPin,
            uint8_t xDataPin, uint8_t yDataPin);
  void begin();
  void writeDot(int xPosition, int yPosition);
  void writePattern(int xPattern, int yPattern);

  int getWidth();
  int getHeight();
  void setClockPin(uint8_t clockPin);
  void setLatchPin(uint8_t latchPin);
  void setXDataPin(uint8_t xDataPin);
  void setYDataPin(uint8_t yDataPin);

private:
  uint8_t clockPin;
  uint8_t latchPin;
  uint8_t xDataPin;
  uint8_t yDataPin;
  int width;
  int height;
};

#endif
