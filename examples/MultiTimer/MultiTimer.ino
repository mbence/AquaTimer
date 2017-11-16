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
#include <AquaTimer.h>

// DS3231 RTC connected via I2C and Wire lib
RTC_DS3231 rtc;

// The timer objects with the pin number, ON and OFF times
AquaTimer Micro(6, "13:40:00", "13:40:04");
AquaTimer Macro(7, "13:40:20", "13:40:24");
AquaTimer Carbo(8, "13:40:40", "13:40:44");


void setup() {
  // Start the clock
  rtc.begin();
  if (rtc.lostPower()) {
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

}

void loop() {  
  // Get the current time
  DateTime now = rtc.now();
  // Write the computed values to the output pins
  Micro.write(now);
  Macro.write(now);
  Carbo.write(now);
}
