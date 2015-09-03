#include <Arduino.h>
#include <duino-tools.h>

//const char * CRLF = "\r\n";

Print & Debug = Serial;

void initDebug(bool waitFor)
{
	// Start serial for output
 	Serial.begin(9600);

 	if (waitFor)
 	{
 	// Wait for seril init
	while(!Serial) {}

	// Wait for user to start the serial monitor on Teensy
	#if defined(CORE_TEENSY)
	while (!Serial.dtr());
	#endif
 	}
}

int freeRam () 
{
  extern int __heap_start, *__brkval; 
  int v; 
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval); 
}
