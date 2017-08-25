#ifndef DustSensor_h
#define DustSensor_h

#include <Arduino.h>

extern const unsigned int samplingTime;
extern const unsigned int deltaTime;
extern const unsigned int sleepTime;

struct SensorData
{
  float voMeasured;
  float calcVoltage;
  float dustDensity;
};

class DustSensor
{
private:
  int measurePin;
  int ledPower;

  float voMeasured;
  float calcVoltage;
  float dustDensity;

  SensorData data;

public:
  DustSensor(const int measurePin, const int ledPower);
  SensorData read();
};

#endif
