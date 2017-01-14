#ifndef DUINO_TOOLS_HARDWARE_ADDRESS_DETECTOR_H_
#define DUINO_TOOLS_HARDWARE_ADDRESS_DETECTOR_H_

#include <Arduino.h>
#include "Misc.h"

class HardwareAddressDetector
{
  public:
    unsigned int get(const unsigned int p1, const unsigned int p2, const unsigned int p3, const unsigned int p4);
};

/**
  * Returns zero-based address defined with 4-channel DIP-switch (or simply 4 jumpers)
  */
inline unsigned int HardwareAddressDetector::get(const unsigned int p1 = 0, const unsigned int p2 = 0, const unsigned int p3 = 0, const unsigned int p4 = 0)
{
  const unsigned int pins[] = {p1, p2, p3, p4};
  const unsigned int pinsCount = sizeof(pins);

  unsigned int value = 0;
  unsigned int mask = 0x01;

  // Serial << "Pins count = " << pinsCount << CRLF;

  for (unsigned int i = 0; i < pinsCount; i++) {
    int pin = pins[i];

    // Exit if no more pins
    if ( !pin )
      break;

    pinMode(pin, INPUT_PULLUP);
    delay(25);

    if (digitalRead(pin) == LOW) {
      value += mask;
    }

    mask = mask << 1;
  }

  return value;
}

#endif
