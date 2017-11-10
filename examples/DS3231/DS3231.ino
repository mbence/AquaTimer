/*
  AquaTimer - example for LED lights with DS3231 RTC 

  This example demonstrates the use of the AquaTimer libray, with one timer
  defined for the LED lights. We use the long definition style here with
  method chaining, because there are many parameters to set.
  
  created 10 Nov 2017
  by Bence Meszaros
*/


// RTClib by Adafruit: https://github.com/adafruit/RTClib
#include <RTClib.h>

// Before the include, we need to tell the library that we will use an RTC_DS3231 
#define WITH_DS3231
#include <AquaTimer.h>

// Pin number for the led lights
const int LED_PIN = 6;

// DS3231 RTC connected via I2C and Wire lib
// The timer class uses this object, so the name must be exactly 'rtc'!
RTC_DS3231 rtc;

// The timer object
AquaTimer LedTimer;

void setup() {
  // Start the clock
  rtc.begin();
  if (rtc.lostPower()) {
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  // Set the timer parameters
  LedTimer
  .setPin(LED_PIN)        // pin number
  .setOn("14:00")         // on time hours:minutes (seconds are also usable - "14:00:10")
  .setTransition("30")    // transition time in minutes
  .setOff("22:00")        // off  time
  .setMoonDuration("60")  // moonlight duration in minutes
  .setMaxVal("75%")       // output percent for LED dimming. Set "100%" for max power.
  .setMoonVal(1);         // moonlight value. I used an int here, to set to the lowest possible walue, but a percent eg "1%" is also usable
}

void loop() {  
  // Write the computed value to the led pin
  LedTimer.write();
}
