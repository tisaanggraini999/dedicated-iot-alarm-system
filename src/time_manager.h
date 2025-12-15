#ifndef TIME_MANAGER_H
#define TIME_MANAGER_H

#include <WiFiUdp.h>
#include <NTPClient.h>

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", 7 * 3600);

int currentHour   = 0;
int currentMinute = 0;
int currentDay    = 0;

unsigned long lastNTPUpdate = 0;
const unsigned long NTP_INTERVAL = 60000;

void initTime() {
  timeClient.begin();
}

void updateTime() {
  if (millis() - lastNTPUpdate >= NTP_INTERVAL) {
    timeClient.update();
    lastNTPUpdate = millis();

    currentHour   = timeClient.getHours();
    currentMinute = timeClient.getMinutes();
    currentDay    = timeClient.getDay();

    Serial.printf("Time: %02d:%02d | Day: %d\n",
                  currentHour, currentMinute, currentDay);
  }
}

#endif
