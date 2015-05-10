#include <Arduino.h>
#include <tools.h>

// char * CRLF = "\r\n";

Print & Console = Serial;

void initConsole()
{
	// Start serial for output
	Serial.begin(9600);

	// Wait for seril init
	while(!Serial) {}
}

// template<class T> inline Print &operator <<(Print &obj, T arg) { obj.print(arg); return obj; };

int freeRam () 
{
  extern int __heap_start, *__brkval; 
  int v; 
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval); 
}
