#ifndef DUINO_TOOLS_DEBUG_H_
#define DUINO_TOOLS_DEBUG_H_

#include <Arduino.h>
#include "Misc.h"

// Helper for line ending
#ifndef CRLF
#define CRLF "\r\n"
#endif

extern volatile bool debugClassEnabled;
extern volatile int debugBenchmarkStart;

class DebugClass
{
  public:
    int startMemoryUsage;
    int lastMemoryUsage;

    DebugClass();
    void init(const long int speed = 9600, const bool waitFor = true);

    template<class T>
    void printFreeRam(T label);

    void printHex8(uint8_t);
    void printHex16(uint16_t);
    // bool isInitialized();

    DebugClass& benchmarkStart(/*const __FlashStringHelper* label*/);
    DebugClass& benchmarkStop();

    template<class T>
    DebugClass& operator <<(T arg);

    DebugClass& operator <<(uint8_t value);
    DebugClass& operator <<(uint16_t value);

    // bool initialized = false;

  // protected:
    // static bool initialized = false;
};

template<class T>
inline DebugClass& DebugClass::operator <<(T arg)
{
  if (debugClassEnabled)
  {
    Serial.print(arg);
  }

  return *this;
};

inline DebugClass& DebugClass::operator <<(uint8_t arg)
{
  if (debugClassEnabled)
  {
    this->printHex8(arg);
  }

  return *this;
};

inline DebugClass& DebugClass::operator <<(uint16_t arg)
{
  if (debugClassEnabled)
  {
    this->printHex16(arg);
  }

  return *this;
};

inline void DebugClass::printHex8(uint8_t value) {
  char tmp[16];
  sprintf(tmp, "0x%.2X", value);
  Serial.print(tmp);
}

inline void DebugClass::printHex16(uint16_t value) {
  char tmp[16];
  sprintf(tmp, "0x%.4X", value);
  Serial.print(tmp);
}

template<class T>
inline void DebugClass::printFreeRam(T label)
{
  int currentUsage = getFreeRam();

  *this << F("Free RAM is ") <<  currentUsage << F(" (") << (currentUsage - this->lastMemoryUsage) << F(" from last call, ") << (currentUsage - this->startMemoryUsage) << F(" from start)") << F(" [") << label << F("]") << CRLF;

  this->lastMemoryUsage = currentUsage;
}

// Populate global variable for debug
extern DebugClass Debug;

// Shortcut for Debig::init()
inline void initDebug(const long int speed = 9600, const bool waitFor = true)
{
  Debug.init(speed, waitFor);
}

#endif // DUINO_TOOLS_DEBUG_H_
