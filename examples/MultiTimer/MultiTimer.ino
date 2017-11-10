/*
  AquaTimer - Multiple timers example

  This example demonstrates the use of the AquaTimer libray, with 3 timers
  defined e.g. for the fertilizers' dosing pumps. We use the short definition
  style here, because only 3 parameters are required: PIN, ON and OFF.
  
  created 10 Nov 2017
  by Bence Meszaros
*/


// RTClib by Adafruit: https://github.com/adafruit/RTClib
#include <RTClib.h>

// Before the include, we need to tell the library that we will use an RTC_DS3231 
#define WITH_DS3231
#include <AquaTimer.h>

// DS3231 RTC connected via I2C and Wire lib
// The timer class uses this object, so the name must be exactly 'rtc'!
RTC_DS3231 rtc;

// The timer objects with the pin number, ON and OFF times
AquaTimer Micro(6, "13:40:00", "13:40:04");
AquaTimer Macro(7, "13:40:20", "13:40:24");
AquaTimer Carbo(8, "13:40:40", "13:40:44");


void setup() {
  // Start the clock
  rtc.begin(DateTime(F(__DATE__), F(__TIME__)));
}

void loop() {  
  // Write the computed values to the output pins
  Micro.write();
  Macro.write();
  Carbo.write();
}
