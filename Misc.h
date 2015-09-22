#ifndef DUINO_TOOLS_MISC_H_
#define DUINO_TOOLS_MISC_H_

#include <Arduino.h>

// Misc << operator for chaining output to "printable" objects 
template<class T>
inline Print &operator <<(Print &obj, T arg)
{
  obj.print(arg);
  return obj;
};

/**
  * Get free memory on AVRs and ARMs 
  * @link https://github.com/mpflaga/Arduino-MemoryFree/blob/master/MemoryFree.cpp
  */
int getFreeRam();

#endif // DUINO_TOOLS_MISC_H_
