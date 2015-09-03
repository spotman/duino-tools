#ifndef tools_cpp_
#define tools_cpp_

#include <Arduino.h>

#ifndef CRLF
#define CRLF "\r\n"
#endif

// extern const char * CRLF = "\r\n";
// extern const char * CRLF;
extern Print & Debug;

template<class T>
inline Print &operator <<(Print &obj, T arg)
{
	obj.print(arg);
	return obj;
};

int freeRam();

void initDebug(bool waitFor = false);


#endif // tools_cpp_
