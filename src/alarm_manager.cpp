#include "alarm_manager.h"
#include "time_manager.h"
#include "audio_player.h"

void checkAlarm(Alarm &alarm) {
  if (currentHour == alarm.hour && currentMinute == alarm.minute) {
    if (currentDay >= alarm.startDay && currentDay <= alarm.endDay) {
      if (!alarm.triggered) {
        playAlarm(alarm.mp3Track);
        alarm.triggered = true;
      }
    }
  } else {
    alarm.triggered = false;
  }
}
