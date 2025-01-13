#include <stdarg.h>
#include <Wire.h>
#include "Quest_CLI.h"
#include "SparkFun_SCD4x_Arduino_Library.h"

#define SPEED_FACTOR 4

#define ONE_SECOND  1000
#define ONE_MIN     60 * ONE_SECOND
#define ONE_HOUR    60 * ONE_MIN

#define PHOTO_INTERVAL ONE_MIN / SPEED_FACTOR

unsigned long photoTimer = millis();

SCD4x co2Sensor;

constexpr bool DEBUG = false;

void flight_setup() {
  pinMode(IO0, INPUT);  // Voltage
  pinMode(IO1, OUTPUT); // Pump

  if (DEBUG) return;

  Serial.println(PHOTO_INTERVAL);

  co2Sensor.begin();
  co2Sensor.stopPeriodicMeasurement();
  co2Sensor.startLowPowerPeriodicMeasurement();

  // Activate the pump
  digitalWrite(IO1, HIGH);
  delay(5000);
  digitalWrite(IO1, LOW);
  delay(5000);
  digitalWrite(IO1, HIGH);
  delay(5000);
  digitalWrite(IO1, LOW);
}

void flight_loop() {
  if (DEBUG) return;
  if (millis() - photoTimer > PHOTO_INTERVAL) {
    Serial.println("Photo Time!");

    photoTimer = millis();

    float voltage40X = analogRead(IO0) * (3.3 / 1024);
    Serial.printf("Read voltage %fV\n", voltage40X);
    addData("Voltage(40X): %fV", voltage40X);

    uint16_t co2 = co2Sensor.getCO2();
    Serial.printf("CO2: %li\n", co2);
    addData("CO2: %li", co2);

    cmd_takeSphoto();

    
  }
}

void addData(const char* format, ...) {
  char buffer[256];

  char modified_format[260];
  snprintf(modified_format, sizeof(modified_format), "(%li) %s\n", rtc.now().unixtime(), format);
  
  va_list args;
  va_start(args, format);

  vsnprintf(buffer, sizeof(buffer), modified_format, args);

  va_end(args);

  if (strlen(user_text_buf0) + strlen(buffer) >= sizeof(user_text_buf0) - 100) {
    Serial.println("Data doesn't fit!");
    return;
  }

  strcat(user_text_buf0, buffer);
}
