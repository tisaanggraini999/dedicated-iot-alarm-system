#include "audio_player.h"

static const int DFPLAYER_RX = 17;
static const int DFPLAYER_TX = 16;

HardwareSerial dfSerial(2);
DFRobotDFPlayerMini dfPlayer;

void initAudio() {
  dfSerial.begin(9600, SERIAL_8N1, DFPLAYER_TX, DFPLAYER_RX);

  Serial.println("Initializing DFPlayer...");
  if (!dfPlayer.begin(dfSerial, false, true)) {
    Serial.println("DFPlayer init failed!");
    while (true);
  }

  dfPlayer.volume(25);
  Serial.println("DFPlayer Ready");
}

void playAlarm(int track) {
  Serial.printf("Playing MP3 Track %d\n", track);
  dfPlayer.play(track);
}
