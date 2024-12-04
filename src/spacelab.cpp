#include <stdarg.h>
#include <Wire.h>
#include "Quest_CLI.h"

#define SPEED_FACTOR 30

#define ONE_SECOND  1000
#define ONE_MIN     60 * ONE_SECOND
#define ONE_HOUR    60 * ONE_MIN

#define PHOTO_INTERVAL ONE_MIN / SPEED_FACTOR

unsigned long photoTimer = millis();

void flight_setup() {
  Serial.println(PHOTO_INTERVAL);
}

void flight_loop() {
  if (millis() - photoTimer > PHOTO_INTERVAL) {
    Serial.println("Photo Time!");

    photoTimer = millis();

    float voltage2X = analogRead(A6) * (3.3 / 1024);
    addData("Voltage(2X): %fV", voltage2X);

    nophotophoto();
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