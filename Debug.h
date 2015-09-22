#ifndef DUINO_TOOLS_DEBUG_H_
#define DUINO_TOOLS_DEBUG_H_

#include <Arduino.h>
#include "Misc.h"

// Helper for line ending
#ifndef CRLF
#define CRLF "\r\n"
#endif

extern volatile bool debugClassInitialized;

class DebugClass
{
  public:
    DebugClass();
    void init(bool waitFor);
    void printFreeRam();
    void printHex8(uint8_t);
    void printHex16(uint16_t);
    // bool isInitialized();

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
  if (debugClassInitialized)
  {
    Serial.print(arg);
  }

  return *this;
};

inline DebugClass& DebugClass::operator <<(uint8_t arg)
{
  if (debugClassInitialized)
  {
    this->printHex8(arg);
  }

  return *this;
};

inline DebugClass& DebugClass::operator <<(uint16_t arg)
{
  if (debugClassInitialized)
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

// Populate global variable for debug
extern DebugClass Debug;

// Shortcut for Debig::init()
inline void initDebug(bool waitFor = true)
{
  Debug.init(waitFor);
}

#endif // DUINO_TOOLS_DEBUG_H_