#include "wifi_manager.h"
#include "time_manager.h"
#include "alarm_manager.h"
#include "audio_player.h"

/* ===========================
   ALARM CONFIGURATION
   =========================== */
Alarm alarms[] = {
  {8,  0, 2, 6, 2, false},
  {10, 0, 2, 6, 4, false},
  {10,15, 2, 6, 4, false},
  {12, 0, 2, 5, 4, false},
  {13, 0, 2, 6, 4, false},
  {11,30, 6, 6, 4, false},
  {15, 0, 2, 6, 4, false},
  {15,15, 2, 6, 4, false},
  {17, 0, 2, 5, 2, false},
  {17,30, 6, 6, 2, false}
};

const int TOTAL_ALARMS = sizeof(alarms) / sizeof(alarms[0]);

/* ===========================
   SETUP
   =========================== */
void setup() {
  Serial.begin(115200);
  delay(1000);

  connectWiFi();
  initTime();
  initAudio();

  Serial.println("IoT Alarm System Ready");
}

/* ===========================
   LOOP
   =========================== */
void loop() {
  updateTime();

  for (int i = 0; i < TOTAL_ALARMS; i++) {
    checkAlarm(alarms[i]);
  }

  delay(500);
}
