#include <Arduino.h>

#include "sensor_readings.h"

void refresh_readings(Adafruit_BME280 *bme,
                      TFT_eSPI *tft,
                      AdafruitIO_Feed *temp,
                      AdafruitIO_Feed *hum,
                      AdafruitIO_Feed *bar,
                      AdafruitIO_Feed *alt)
{
    float f_temperature;
    float f_humidity;
    float f_pressure;
    float f_altitude;

    uint16_t bg = TFT_BLACK;
    uint16_t fg = TFT_WHITE;

    digitalWrite(LED_PIN, HIGH);

    f_temperature = bme->readTemperature() * 1.8 + 32;
    f_humidity = bme->readHumidity();
    f_pressure = bme->readPressure() / 100.0F * .02953;
    f_altitude = bme->readAltitude(SEALEVELPRESSURE_HPA) * 3.28084;

    tft->setTextColor(TFT_YELLOW, bg);
    tft->loadFont("SansSerif-24");

    // Temperature
    Serial.print(f_temperature);
    Serial.println(" °F");
    tft->fillRect(5, 30, 140, 30, bg);
    tft->setCursor(5, 30);
    tft->print(f_temperature);
    tft->println(" °F");

    // Humidity
    Serial.print(f_humidity);
    Serial.println(" %");
    tft->fillRect(5, 60, 130, 30, bg);
    tft->setCursor(5, 60);
    tft->print(f_humidity);
    tft->println(" %");

    // Pressure
    Serial.print(f_pressure);
    Serial.println(" inhg");
    tft->fillRect(5, 90, 200, 30, bg);
    tft->setCursor(5, 90);
    tft->print(f_pressure);
    tft->println(" inhg");

 // Level Sensor
    Serial.print("500");
    Serial.println(" ma");
    tft->fillRect(5, 120, 200, 30, bg);
    tft->setCursor(5, 120);
    tft->print("500");
    tft->println(" ma");

     // Condition
    Serial.print("Open");
    Serial.println(" Condition");
    tft->fillRect(5, 150, 200, 30, bg);
    tft->setCursor(5, 150);
    tft->print("Open");
    tft->println(" Condition");

    // Appx altitude
    // Serial.print(f_altitude);
    // Serial.println(" ft");
    // tft->fillRect(5, 170, 200, 30, bg);
    // tft->setCursor(5, 170);
    // tft->print(f_altitude);
    // tft->println(" ft");

    //Send data to Adafruit.IO
    temp->save(f_temperature);
    hum->save(f_humidity);
    bar->save(f_pressure);
    // alt->save(f_altitude);

    // Update the postsCounter value in the EEPROM and the TFT
    postsCounter(tft);

    digitalWrite(LED_PIN, LOW);
    Serial.println("-----v2----");
}