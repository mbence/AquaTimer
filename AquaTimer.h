/*
  Timer for Aquarium controllers
    
  created 10 Nov 2017
  by Bence Meszaros
*/

#ifndef AquaTimer_h
#define AquaTimer_h

#include "Arduino.h"
#include <RTClib.h>

class AquaTimer {
  private:
    int pin;
    long on;
    long off;
    int transition;
    int moonDuration;
    int maxVal;
    int moonVal;
    long getSeconds(DateTime now);
    long t2s(int h, int m, int s = 0);
    long toTime(String str);
  public:
    AquaTimer();
    AquaTimer(int pin, String on, String off);
    int getVal(long time);
    void AquaTimer::write(DateTime now, bool override = false);
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
