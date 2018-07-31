#include "motor.h"

Motor::Motor() : pin(0){}
Motor::Motor(int pin) : pin(pin) {}

void Motor::setup () {
  pinMode(this->pin, OUTPUT);
  analogWrite(this->pin, LOW);
}

void Motor::accel() {
  if(!this->Acc) 
    return;
  
  analogWrite(this->pin, this->Acc); 
  delay(10);  
}

void *Motor::setRate(String val){
  int On = atoi(val.c_str());
  this->Acc = On;
}

void Motor::loop() {
  this->accel();
}

