// Daniel Gilbert
// loglow@gmail.com
// copyright 2013



#ifndef __PITIMER_H__
#define __PITIMER_H__



#include <stdint.h>



class PITimer {
  private:
    uint8_t myID;
    uint32_t myValue;
    bool isRunning;
    void writeValue();
    float round(float value);
    static const uint16_t valueMin = 640;
  public:
    PITimer(uint8_t timerID);
    void value(uint32_t newValue);
    void period(float newPeriod);
    void frequency(float newFrequency);
    uint32_t value();
    float period();
    float frequency();
    void start(void (*newISR)());
    void clear();
    void reset();
    void stop();
    bool running();
    uint32_t current();
    float remains();
    void (*myISR)();
};



extern PITimer PITimer0;
extern PITimer PITimer1;
extern PITimer PITimer2;
//extern PITimer PITimer3;



#endif



// EOF