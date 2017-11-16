/*
  Timer for Aquarium controllers
    
  created 10 Nov 2017
  by Bence Meszaros
*/

#include "Arduino.h"
#include "AquaTimer.h"

AquaTimer::AquaTimer()
{
  this->on = 10;
  this->off = 20;
  this->transition = 0;
  this->moonDuration = 0;
  this->maxVal = 255;
  this->moonVal = 1;
}

AquaTimer::AquaTimer(int pin, String on, String off)
  : AquaTimer()
{
  this->setPin(pin);
  this->setOn(on);
  this->setOff(off);
}

AquaTimer& AquaTimer::setPin(int pin)
{
  this->pin = pin;
  pinMode(this->pin, OUTPUT);
  return *this;
}

AquaTimer& AquaTimer::setOn(long on)
{
  this->on = on;
  return *this;
}

AquaTimer& AquaTimer::setOn(String on)
{
  this->setOn(this->toTime(on));
  return *this;
}


AquaTimer& AquaTimer::setOff(long off)
{
  this->off = off;
  return *this;
}

AquaTimer& AquaTimer::setOff(String off)
{
  this->setOff(this->toTime(off));
  return *this;
}

AquaTimer& AquaTimer::setTransition(int transition)
{
  this->transition = transition;
  return *this;
}

AquaTimer& AquaTimer::setTransition(String transition)
{
  this->setTransition(transition.toInt() * 60);
  return *this;
}

AquaTimer& AquaTimer::setMoonDuration(int dur)
{
  this->moonDuration = dur;
  return *this;
}

AquaTimer& AquaTimer::setMoonDuration(String dur)
{
  this->setMoonDuration(dur.toInt() * 60);
  return *this;
}

AquaTimer& AquaTimer::setMaxVal(int maxVal)
{
  if (maxVal > 255) {
    maxVal = 255;
  }
  if (maxVal < 0) {
    maxVal = 0;
  }
  this->maxVal = maxVal;
  return *this;
}

AquaTimer& AquaTimer::setMaxVal(String maxVal)
{
  if (maxVal.endsWith("%")) {
    maxVal.remove(-1);
  }
  this->setMaxVal(round(maxVal.toInt() * 255 / 100));
  return *this;
}

AquaTimer& AquaTimer::setMoonVal(int moonVal)
{
  if (moonVal > 255) {
    moonVal = 255;
  }
  if (moonVal < 0) {
    moonVal = 0;
  }
  this->moonVal = moonVal;
  return *this;
}

AquaTimer& AquaTimer::setMoonVal(String moonVal)
{
  if (moonVal.endsWith("%")) {
    moonVal.remove(-1);
  }

  this->setMoonVal(round(moonVal.toFloat() * 255 / 100));
  return *this;
}

void AquaTimer::write(DateTime now, bool override)
{  
  long time = this->getSeconds(now); 
  int val = this->getVal(time);

  if (override) {
    val = 255;
  }

  analogWrite(this->pin, val);
}

int AquaTimer::getVal(long time)
{
  int val = 0;

  // warm up
  if (time >= this->on && time < this->on + this->transition) {
    val = this->maxVal * (time - this->on) / this->transition;
  }
  // lights on
  if (time >= this->on + this->transition && time < this->off - this->transition) {
    val = this->maxVal;
  }
  // fade off
  if (time >= this->off - this->transition && time < this->off) {
    val = this->maxVal * (this->off - time) / this->transition + this->moonVal;
  }
  // moonLight
  if (time >= this->off && time < this->off + this->moonDuration) {
    val = this->moonVal;
  }
  // off
  if (time >= this->off + this->moonDuration) {
    val = 0;
  }

  return val;
}

long AquaTimer::t2s(int h, int m, int s)
{
  return (h * 60L + m) * 60 + s;
}

long AquaTimer::getSeconds(DateTime now)
{
  return t2s(now.hour(), now.minute(), now.second());
}

long AquaTimer::toTime(String str)
{
  int hours = 0;
  int minutes = 0;
  int seconds = 0;

  if (str.length() >= 5) {
    hours = str.substring(0, 2).toInt();
    minutes = str.substring(3, 5).toInt();
  }
  if (str.length() >= 8) {
    seconds = str.substring(6, 8).toInt();
  }

  return this->t2s(hours, minutes, seconds);
}
