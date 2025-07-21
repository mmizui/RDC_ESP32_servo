#ifndef ServoPWM_h
#define ServoPWM_h

#include <Arduino.h>

class ServoPWM {
  public:
    ServoPWM(int pin, int channel = 0, int freq = 50, int resolution = 16);
    void begin();
    void moveServo(int angle);

  private:
    int _pin;
    int _channel;
    int _freq;
    int _resolution;
    int _maxDuty;
};

#endif