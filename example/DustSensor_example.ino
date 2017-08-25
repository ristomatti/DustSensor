#include <Arduino.h>
#include "DustSensor.h"

DustSensor sensor = DustSensor(A0, 13);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  SensorData data = sensor.read();

  Serial.print("Raw Signal Value (0-1023): ");
  Serial.println(data.voMeasured);

  Serial.print("Voltage: ");
  Serial.println(data.calcVoltage);

  Serial.print("Dust Density: ");
  Serial.println(data.dustDensity);

  Serial.println();

  delay(1000);
}
