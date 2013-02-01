#include "PITimer.h"

void timerCallback0() {
  // runs every second
}

void timerCallback1() {
  // runs every 5 seconds
}

void timerCallback2() {
  // runs 2000 times per second
}

void setup() {
  PITimer1.period(5);
  PITimer2.frequency(2000);
  PITimer0.start(timerCallback0); // 1 second
  PITimer1.start(timerCallback1); // 5 seconds
  PITimer2.start(timerCallback2); // 2 KHz
}

void loop() {
}