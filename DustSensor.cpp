#include <Arduino.h>
#include "DustSensor.h"

const unsigned int samplingTime = 280;
const unsigned int deltaTime = 40;
const unsigned int sleepTime = 9680;

DustSensor::DustSensor(const int measurePin, const int ledPower)
{
  this->measurePin = measurePin;
  this->ledPower = ledPower;

  this->voMeasured = 0;
  this->calcVoltage = 0;
  this->dustDensity = 0;

  pinMode(ledPower, OUTPUT);
}

SensorData DustSensor::read()
{
  digitalWrite(ledPower, LOW);
  delayMicroseconds(samplingTime);

  this->voMeasured = analogRead(measurePin);

  delayMicroseconds(deltaTime);
  digitalWrite(ledPower, HIGH);
  delayMicroseconds(sleepTime);

  this->calcVoltage = voMeasured * (5.0 / 1024);
  this->dustDensity = 0.17 * calcVoltage - 0.1;

  if (dustDensity < 0)
  {
    this->dustDensity = 0.00;
  }

  this->data = {this->voMeasured, this->calcVoltage, this->dustDensity};
  return data;
}
