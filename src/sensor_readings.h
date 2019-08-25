#ifndef SENSOR_READINGS_H
#define SENSOR_READINGS_H

#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <TFT_eSPI.h>
#include "settings.h"

#define SEALEVELPRESSURE_HPA (1015.15)

void refresh_readings(Adafruit_BME280 *bme,
                      TFT_eSPI *tft,
                      AdafruitIO_Feed *temp,
                      AdafruitIO_Feed *hum,
                      AdafruitIO_Feed *bar,
                      AdafruitIO_Feed *alt);

#endif