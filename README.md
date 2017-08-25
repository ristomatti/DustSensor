# DustSensor

Arduino library for interfacing with Sharp GP2Y1010AU0F dust sensor.

## Example

```cpp
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
```

## Credits

Library is based on
example code found from Instructable article [How to Interface With Optical Dust Sensor](http://www.instructables.com/id/How-to-Interface-With-Optical-Dust-Sensor/) by [mybotic](http://www.instructables.com/member/mybotic/).
