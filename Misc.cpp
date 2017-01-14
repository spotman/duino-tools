#include "Misc.h"


/**
  * Get free memory on AVRs and ARMs
  * @link https://github.com/mpflaga/Arduino-MemoryFree/blob/master/MemoryFree.cpp
  */
int getFreeRam()
{
  char top;

  #ifdef ESP8266
    return ESP.getFreeHeap();
  #elif __ARM__
    return &top - reinterpret_cast<char*>(sbrk(0));
  #elif defined(CORE_TEENSY) || (ARDUINO > 103 && ARDUINO != 151)
    return &top - __brkval;
  #else  // __ARM__
    return __brkval ? &top - __brkval : &top - __malloc_heap_start;
  #endif  // __ARM__

  // freeRam AVR implementation
  // #ifdef __AVR__
  // extern int __heap_start, *__brkval;
  // int v;
  // return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
  // #endif // __AVR__
}
