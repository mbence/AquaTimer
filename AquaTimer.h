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
    int write(DateTime now, bool override = false);
    AquaTimer& setPin(int pin);
    AquaTimer& setOn(long on);
    AquaTimer& setOn(String on);
    AquaTimer& setOff(long off);
    AquaTimer& setOff(String off);
    AquaTimer& setTransition(int transition);
    AquaTimer& setTransition(String transition);
    AquaTimer& setMoonDuration(int dur);
    AquaTimer& setMoonDuration(String dur);
    AquaTimer& setMaxVal(int maxVal);
    AquaTimer& setMaxVal(String maxVal);
    AquaTimer& setMoonVal(int moonVal);
    AquaTimer& setMoonVal(String moonVal);
};

#endif
