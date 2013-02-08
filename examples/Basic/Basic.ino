#include "PITimer.h"

uint32_t timer0Count = 0;
uint32_t timer1Count = 0;
uint32_t timer2Count = 0;

void timerCallback0() {
  // runs every second
  timer0Count++;
  Serial.print("Timer 0: ");
  Serial.print(timer0Count);
  Serial.print("\t");
  Serial.print("Timer 1: ");
  Serial.print(timer1Count);
  Serial.print("\t");
  Serial.print("Timer 2: ");
  Serial.println(timer2Count);
}

void timerCallback1() {
  // runs every 5 seconds
  timer1Count++;
}

void timerCallback2() {
  // runs 2000 times per second
  timer2Count++;
}

void setup() {
  Serial.begin(true);
  PITimer1.period(5);
  PITimer2.frequency(2000);
  PITimer2.start(timerCallback2); // 2 KHz
  PITimer1.start(timerCallback1); // 5 seconds
  PITimer0.start(timerCallback0); // 1 second
}

void loop() {
}
