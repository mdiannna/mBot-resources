#include <Tone.h>

#define P_HIGH NOTE_G5
#define P_LOW NOTE_D5

Tone player; 


void setup() {
  player.begin(8);
}

void loop() {
  player.play(P_HIGH);
  delay(1000);

  player.play(P_LOW);
  delay(1000);

  player.play(P_HIGH);
  delay(1000);

  player.play(P_LOW);
  delay(1000);

  player.stop();
  delay(2000);
}
