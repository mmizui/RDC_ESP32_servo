#include "ServoPWM.h"

ServoPWM::ServoPWM(int pin, int channel, int freq, int resolution) {
  _pin = pin;
  _channel = channel;
  _freq = freq;
  _resolution = resolution;
  _maxDuty = (1 << _resolution) - 1;
}

void ServoPWM::begin() {
  ledcSetup(_channel, _freq, _resolution);
  ledcAttachPin(_pin, _channel);
}

void ServoPWM::moveServo(int angle) {
  int duty_us = map(angle, 0, 180, 500, 2400);
  int duty = (duty_us * _freq * _maxDuty) / 1000000;
  ledcWrite(_channel, duty);
}