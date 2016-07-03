/*
 * \brief Show distance between Ultrasonic proximity sensor and any element every second
 *
 * \author Quentin Comte-Gaz <quentin@comte-gaz.com>
 * \date 3 July 2016
 * \license MIT License (contact me if too restrictive)
 * \copyright Copyright (c) 2016 Quentin Comte-Gaz
 * \version 1.0
 */

#include <UltrasonicProximitySensor.h>

// Create an ultrasonic proximity sensor instance
// with D2 as trigger pin and D3 as echo pin
UltrasonicProximitySensor proximity_sensor(2, 3);

void setup(void)
{
  Serial.begin(9600);

  // Set the maximum distance to check (optionnal)
  // This should be used if you have false positive distances from sensor
  // proximity_sensor.setMaximumDistanceToCheckInCm(500);
}

void loop()
{
  unsigned long distance_in_cm = proximity_sensor.getDistanceInCm();

  if (distance_in_cm <= 0) {
    Serial.print("Sensor not connected or distance higher than ");
    Serial.print(proximity_sensor.getMaximumDistanceToCheckInCm());
    Serial.print("cm\n");
  } else {
    Serial.print("Distance: ");
    Serial.print(distance_in_cm);
    Serial.print("cm\n");
  }

  delay(1000);
}
