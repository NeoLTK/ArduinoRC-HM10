#include "bluetooth.h"

BlueTooth::BlueTooth() {
  this->TX = 10;
  this->RX = 11;
  this->baudrate = 9600;
}

BlueTooth::BlueTooth(int baudrate) : baudrate(baudrate) {
  this->TX = 10;
  this->RX = 11;
}

BlueTooth::BlueTooth(int baudrate, int TX, int RX) : baudrate(baudrate), TX(TX), RX(RX) { 
  this->TX = 10;
  this->RX = 11;
}

void BlueTooth::setup() {
   device = new SoftwareSerial(this->TX, this->RX);
   //this->serialRate();
   device->begin(this->baudrate);
}

void BlueTooth::loop() {
    
}

bool BlueTooth::serialRate() {
  long serial_rates[] = {
    9600, 57600, 115200,
    19200, 38400, 4800, 2400, 1200, 230400
  };

  for (int i = 0; i < (sizeof(serial_rates)/sizeof(long)); i++) {
    //Serial.print(".");
    
    baudrate = serial_rates[i];
    
    device->begin(baudrate);
    device->write("AT");
    device->flush();
    
    if (device->readString() == "OK") {
      //Serial.println("\nBluetooth Serial Rate detected: " + String(baudrate));
      return true;
    } else {
       device->end();
    }
  }

  Serial.println("\nBluetooth Serial Rate not detected.");
  
  return false;
}

String BlueTooth::Recev(){
  return device->readString();
}

String BlueTooth::Send(){
   return "";
}
