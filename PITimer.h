#ifndef __PITIMER_H__
#define __PITIMER_H__

class PITimer {
  private:
    unsigned short myID;
    unsigned long myValue;
    bool isRunning;
    void writeValue();
  public:
    PITimer(unsigned short timerID);
    void value(unsigned long newValue);
    void period(float newPeriod);
    void frequency(float newFrequency);
    unsigned long value();
    float period();
    float frequency();
    void start();
    void clear();
    void reset();
    void stop();
    bool running();
    unsigned long current();
};

extern PITimer PITimer0;
extern PITimer PITimer1;
extern PITimer PITimer2;
extern PITimer PITimer3;

#endif