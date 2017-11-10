/*
  Timer for Aquarium controllers
    
  created 10 Nov 2017
  by Bence Meszaros
*/

#ifndef AquaTimer_h
#define AquaTimer_h

#include "Arduino.h"
#include <Wire.h>
#include <RTClib.h>

#ifdef WITH_DS1307
extern RTC_DS1307 rtc;
#elif defined(WITH_DS3231)
extern RTC_DS3231 rtc;
#else
extern RTC_Millis rtc;
#endif

class AquaTimer {
  private:
    int pin;
    long on;
    long off;
    int transition;
    int moonDuration;
    int maxVal;
    int moonVal;
    float getSeconds();
    long t2s(int h, int m, int s = 0);
    long toTime(String str);
  public:
    AquaTimer();
    AquaTimer(int pin, String on, String off);
    int getVal();
    void AquaTimer::write(bool override = false);
    AquaTimer& AquaTimer::setPin(int pin);
    AquaTimer& AquaTimer::setOn(long on);
    AquaTimer& AquaTimer::setOn(String on);
    AquaTimer& AquaTimer::setOff(long off);
    AquaTimer& AquaTimer::setOff(String off);
    AquaTimer& AquaTimer::setTransition(int transition);
    AquaTimer& AquaTimer::setTransition(String transition);
    AquaTimer& AquaTimer::setMoonDuration(int dur);
    AquaTimer& AquaTimer::setMoonDuration(String dur);
    AquaTimer& AquaTimer::setMaxVal(int maxVal);
    AquaTimer& AquaTimer::setMaxVal(String maxVal);
    AquaTimer& AquaTimer::setMoonVal(int moonVal);
    AquaTimer& AquaTimer::setMoonVal(String moonVal);
};

#endif
