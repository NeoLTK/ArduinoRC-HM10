#include <Servo.h>
#include "bluetooth.h"
#include "motor.h"

BlueTooth bluetooth;
Motor motor(6);

Servo myservo;

char** splitString(String string, char *delim){
  char *cstring = new char[string.length() + 1];
  strcpy(cstring, string.c_str());
  
  char *Array[10];

  Array[0] = strtok(cstring, delim);
  for(int i = 1; Array[i]!= NULL; i++) {
     delay(10);
     Array[i] = strtok(NULL, delim);
  }

  return Array;
}


void *servo(String value){
  if(!value) {
   
    return;
  }
  
  int intVal = atoi(value.c_str());
  
  if((intVal < 0) || (intVal > 180)) 
    return;
  
  Serial.println("Servo: " + value + "°");
  myservo.write(intVal);
  return;
}

void *acc(String v){
  motor.setRate(v);
}

void (*function[2])(String) = {&servo, &acc};
String fName[2] = {"s", "m"};

void callFunc(String str){
  char **cmdRecev = splitString(str, ":");
  
  for (int a = 0; cmdRecev[a]; a++){
    for (int i = 0; fName[i]; i++){
      if (strcmp(fName[i][0], cmdRecev[a][0]) == 0){
         (*function[i])(cmdRecev[++a]); 
      }
    }
  }
}


void setup() {
  Serial.begin(9600);
  while(!Serial){}
  
  myservo.attach(9);
  bluetooth.setup();
  motor.setup();
}


void loop() {
  if (bluetooth.device->available()) {
      String s = "";
      char c;
      while((c = bluetooth.device->read()) != -1) {
        s += c;
        delay(5);
      }
  
      Serial.println("Received: " + s);
      callFunc(s);
    }
    
  if (Serial.available()) {
      String s = "";
      char c;
      while((c = Serial.read()) != -1) {
        s += c;
        delay(5);
      }
      
      Serial.println("send: " + s);
      callFunc(s);
      bluetooth.device->print(s);
    } 
    
    motor.loop();
}
