#ifndef ALARM_MANAGER_H
#define ALARM_MANAGER_H

struct Alarm {
  int hour;
  int minute;
  int startDay;
  int endDay;
  int mp3Track;
  bool triggered;
};

void checkAlarm(Alarm &alarm);

#endif
