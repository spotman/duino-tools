#ifndef DUINO_TOOLS_HARDWARE_ADDRESS_DETECTOR_H_
#define DUINO_TOOLS_HARDWARE_ADDRESS_DETECTOR_H_

#include <Arduino.h>
#include "Misc.h"

class HardwareAddressDetector
{
  public:
    unsigned char get(const char p1, const char p2, const char p3, const char p4);
};

/**
  * Returns zero-based address defined with 4-channel DIP-switch (or simply 4 jumpers)
  */
unsigned char HardwareAddressDetector::get(const char p1 = 0, const char p2 = 0, const char p3 = 0, const char p4 = 0)
{
  const char pins[] = {p1, p2, p3, p4};
  const char pinsCount = sizeof(pins);

  unsigned char value = 0;
  unsigned char mask = 0x01;

  // Serial << "Pins count = " << pinsCount << CRLF;

  for (char i = 0; i < pinsCount; i++)
  {
    int pin = pins[i];

    // Exit if no more pins
    if ( !pin )
      break;

    pinMode(pin, INPUT_PULLUP);
    delay(25);

    if (digitalRead(pin) == LOW)
      value += mask;

    mask = mask << 1;
  }

  return value;
}

#endif