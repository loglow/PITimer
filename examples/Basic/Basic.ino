#include "PITimer.h"

void setup() {
  PITimer1.period(5);
  PITimer2.frequency(2000);
  PITimer0.start(); // 1 second
  PITimer1.start(); // 5 seconds
  PITimer2.start(); // 2 KHz
}

void pit0_isr() {
  PITimer0.clear();
  // runs every second
}

void pit1_isr() {
  PITimer1.clear();
  // runs every 5 seconds
}

void pit2_isr() {
  PITimer2.clear();
  // runs 2000 times per second
}

void loop() {
}
