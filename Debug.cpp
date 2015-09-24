#include <Arduino.h>
#include "Misc.h"
#include "Debug.h"


volatile bool debugClassEnabled = false;
volatile int debugBenchmarkStart = 0;
// char debugBenchmarkStartLabel[16];

DebugClass::DebugClass() {}

void DebugClass::init(const long int speed, const bool waitFor)
{
  static volatile bool debugClassInitialized; // = false;

  if (debugClassInitialized) // this->initialized
    return;

  // Start serial for serial
  Serial.begin(speed);

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

  // Enable logging
  debugClassEnabled = true;
}

DebugClass& DebugClass::benchmarkStart(/*const __FlashStringHelper* label*/)
{
  if ( !debugBenchmarkStart )
  {
    // *this << F("[") << debugBenchmarkStartLabel << F("] benchmark started");
    *this << F("Benchmark started") << CRLF;

    // Stop debugging coz it`s wasting CPU power
    debugClassEnabled = false;

    debugBenchmarkStart = micros();
  }
  else
  {
    // *this << F("Benchmark [") << debugBenchmarkStartLabel << F("] is already started") << CRLF;
    *this << F("Benchmark is already started") << CRLF;
  }

  return *this;
}

DebugClass& DebugClass::benchmarkStop()
{
  if ( debugBenchmarkStart )
  {
    int stop = micros();

    // Start debugging
    debugClassEnabled = true;

    // calculate difference and print it
    // *this << F("[") << debugBenchmarkStartLabel << F("] benchmark stoped, ") << (stop - debugBenchmarkStart) << F("us left") << CRLF;
    *this << F("Benchmark stopped, ") << (stop - debugBenchmarkStart) << F("us left") << CRLF;

    // Reset start point
    debugBenchmarkStart = 0;
  }
  else
  {
    *this << F("No benchmark started") << CRLF;
  }

  return *this;
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
