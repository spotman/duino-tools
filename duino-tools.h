#ifndef DUINO_TOOLS_H_
#define DUINO_TOOLS_H_

#include <Arduino.h>
#include "Misc.h"
#include "Debug.h"
#include "HardwareAddressDetector.h"

// // Populate global variable for debug
// extern DebugClass Debug;

// Workaround issue: https://github.com/esp8266/Arduino/issues/2078
// https://github.com/felis/USB_Host_Shield_2.0/commit/d7cf78f2fe33a652ac351b8dd82731a0a528f69a
#ifdef ESP8266
#undef PROGMEM
#define PROGMEM
#undef PSTR
#define PSTR(s) (s)
#undef pgm_read_byte
#define pgm_read_byte(addr) (*reinterpret_cast<const uint8_t*>(addr))
#undef pgm_read_word
#define pgm_read_word(addr) (*reinterpret_cast<const uint16_t*>(addr))
#endif

#endif // duino_tools_h_
