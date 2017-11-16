/*
  AquaTimer - example for aquarium lights with Software RTC 

  This example demonstrates the use of the AquaTimer libray, with one timer
  defined for the aquarium lights. We use the short definition style here, 
  only to set the PIN, ON and OFF. 
  
  Also, we use the Software RTC from  Adafruits RTClib, which requires 
  no actual RTC hardware. Please only use Software RTC for testing or 
  developement, because it will forget the time with every reset or power
  outage!
  
  
  For a more complex example see DS137 or DS3231!
  
  created 10 Nov 2017
  by Bence Meszaros
*/

// RTClib by Adafruit: https://github.com/adafruit/RTClib
#include <RTClib.h>
#include <AquaTimer.h>

// pin number for the lights/relay
const int LIGHTS_PIN = 6;

// Software RTC based on millis() - only for testing!
RTC_Millis rtc;

// The timer object, pin, ON and OFF
AquaTimer LedTimer(LIGHTS_PIN, "14:00", "22:00");

void setup() {
  // start the clock
  rtc.begin(DateTime(F(__DATE__), F(__TIME__)));
}

void loop() {  
  // Get the current time
  DateTime now = rtc.now();
  // write the computed value to the led pin
  LedTimer.write(now);
}
