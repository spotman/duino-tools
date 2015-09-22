#include <Arduino.h>
#include "Misc.h"
#include "Debug.h"


volatile bool debugClassInitialized = false;

DebugClass::DebugClass() {}

void DebugClass::init(bool waitFor)
{
  if (debugClassInitialized) // this->initialized
    return;

  // Start serial for serial
  Serial.begin(9600);

  if (waitFor)
  {
    // Wait for serial init
    while(!Serial) {}

    // Wait for user to start the serial monitor on Teensy
    #ifdef CORE_TEENSY
    while (!Serial.dtr());
    #endif
  }

  // this->initialized = true;
  debugClassInitialized = true;
}

// inline bool DebugClass::isInitialized()
// {
//   return this->initialized;
// }

void DebugClass::printFreeRam()
{
  *this << F("Free RAM is: ") <<  getFreeRam() << CRLF;
}

DebugClass Debug;
