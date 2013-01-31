// Daniel Gilbert
// loglow@gmail.com
// copyright 2013

#include "PITimer.h"
#include <mk20dx128.h>
#include <math.h>

PITimer PITimer0(0);
PITimer PITimer1(1);
PITimer PITimer2(2);
//PITimer PITimer3(3);

void PITimer::writeValue() {
  if (myID == 0) {
    PIT_LDVAL0 = myValue;
  } else if (myID == 1) {
    PIT_LDVAL1 = myValue;
  } else if (myID == 2) {
    PIT_LDVAL2 = myValue;
  } else if (myID == 3) {
    PIT_LDVAL3 = myValue;
  }
}

PITimer::PITimer(unsigned short timerID) : myID(timerID), myValue(F_BUS), isRunning(false) {
  SIM_SCGC6 |= SIM_SCGC6_PIT;
  PIT_MCR = 0;
  writeValue();
}

void PITimer::value(unsigned long newValue) {
  myValue = newValue;
  writeValue();
}

void PITimer::period(float newPeriod) {
  myValue = floor(F_BUS * newPeriod + 0.5) - 1;
  writeValue();
}

void PITimer::frequency(float newFrequency) {
  myValue = floor(F_BUS / newFrequency + 0.5) - 1;
  writeValue();
}

unsigned long PITimer::value() {
  return myValue;
}

float PITimer::period() {
  return (myValue + 1) / float(F_BUS);
}

float PITimer::frequency() {
  return float(F_BUS) / (myValue + 1);
}

void PITimer::start() {
  isRunning = true;
  if (myID == 0) {
    PIT_TCTRL0 = 3;
    NVIC_ENABLE_IRQ(IRQ_PIT_CH0);
  } else if (myID == 1) {
    PIT_TCTRL1 = 3;
    NVIC_ENABLE_IRQ(IRQ_PIT_CH1);
  } else if (myID == 2) {
    PIT_TCTRL2 = 3;
    NVIC_ENABLE_IRQ(IRQ_PIT_CH2);
  } else if (myID == 3) {
    PIT_TCTRL3 = 3;
    NVIC_ENABLE_IRQ(IRQ_PIT_CH3);
  }
}

void PITimer::clear() {
  if (myID == 0) {
    PIT_TFLG0 = 1;
  } else if (myID == 1) {
    PIT_TFLG1 = 1;
  } else if (myID == 2) {
    PIT_TFLG2 = 1;
  } else if (myID == 3) {
    PIT_TFLG3 = 1;
  }
}

void PITimer::reset() {
  if (myID == 0) {
    PIT_TCTRL0 = 1;
    PIT_TCTRL0 = 3;
  } else if (myID == 1) {
    PIT_TCTRL1 = 1;
    PIT_TCTRL1 = 3;
  } else if (myID == 2) {
    PIT_TCTRL2 = 1;
    PIT_TCTRL2 = 3;
  } else if (myID == 3) {
    PIT_TCTRL3 = 1;
    PIT_TCTRL3 = 3;
  }
}

void PITimer::stop() {
  isRunning = false;
  if (myID == 0) {
    NVIC_DISABLE_IRQ(IRQ_PIT_CH0);
    PIT_TCTRL0 = 0;
  } else if (myID == 1) {
    NVIC_DISABLE_IRQ(IRQ_PIT_CH1);
    PIT_TCTRL1 = 0;
  } else if (myID == 2) {
    NVIC_DISABLE_IRQ(IRQ_PIT_CH2);
    PIT_TCTRL2 = 0;
  } else if (myID == 3) {
    NVIC_DISABLE_IRQ(IRQ_PIT_CH3);
    PIT_TCTRL3 = 0;
  }
}

bool PITimer::running() {
  return isRunning;
}

unsigned long PITimer::current() {
  unsigned long currentValue = 0;
  if (myID == 0) {
    currentValue = PIT_CVAL0;
  } else if (myID == 1) {
    currentValue =  PIT_CVAL1;
  } else if (myID == 2) {
    currentValue =  PIT_CVAL2;
  } else if (myID == 3) {
    currentValue =  PIT_CVAL3;
  }
  return currentValue;
}

float PITimer::remains() {
  return current() / float(F_BUS);
}