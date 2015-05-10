#ifndef tools_cpp_
#define tools_cpp_

#include <Arduino.h>

extern Print & Console;
// extern char * CRLF;


template<class T> inline Print &operator <<(Print &obj, T arg) { obj.print(arg); return obj; };

int freeRam();

void initConsole();


#endif // tools_cpp_
