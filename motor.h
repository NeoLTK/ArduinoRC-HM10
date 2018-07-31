#ifndef Motor_h
#define Motor_h

#include <Arduino.h>
class Motor {
  public:
    Motor();
    Motor(int);
    
    void setup();
    void loop();
    void *setRate(String);

    
  private:
    void accel();
    int Acc;
    int pin;
};

#endif

