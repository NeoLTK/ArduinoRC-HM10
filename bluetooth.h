#ifndef Bluetooth_H
#define Bluetooth_H

#include <SoftwareSerial.h>
#include <Arduino.h>

class BlueTooth {
  public:
    BlueTooth();
    BlueTooth(int);
    BlueTooth(int, int, int);

    void setup();
    void loop();
    
    bool serialRate();
    String Recev();
    String Send();
    SoftwareSerial *device;
    
  private:
    int baudrate;
    int RX;
    int TX;
    
    
};
#endif
