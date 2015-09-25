/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"

const long B_UP = 0x20DF02FD;
const long B_DOWN = 0x20DF827D;
const long B_RIGHT = 0x20DF609F;
const long B_LEFT = 0x20DFE01F;
const long B_OK = 0x20DF22DD;
const long B_BLUE = 0x20DF8679;
const long B_YELLOW = 0x20DFC639;

int RECV_PIN = 7;
int LED = 6;
IRrecv irrecv(RECV_PIN);
decode_results results;

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *lMotor = AFMS.getMotor(1);
Adafruit_DCMotor *rMotor = AFMS.getMotor(2);

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  AFMS.begin();
  lMotor->run(FORWARD);
  lMotor->setSpeed(0);
  rMotor->run(FORWARD);
  rMotor->setSpeed(0);
  pinMode(LED, OUTPUT);
}

int lspeed = 0;
int rspeed = 0;

void loop() {
  
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
    switch (results.value) {
      case B_UP:
        lspeed+= 10; if(lspeed>250) lspeed = 250;
        Serial.print(lspeed, DEC);
        Serial.println(" fel lspeed");
        break;
      case B_DOWN:
        lspeed-=10; if(lspeed<-250) lspeed = -250;
        Serial.print(lspeed, DEC);
        Serial.println(" le lspeed");
        break;
      case B_RIGHT:
        rspeed+= 10; if(rspeed>250) rspeed = 250; 
        Serial.print(rspeed, DEC);
        Serial.println(" jobb rspeed");
        break;
      case B_LEFT:
        rspeed-=10; if(rspeed<-250) rspeed = -250;
        Serial.print(rspeed, DEC);
        Serial.println(" bal rspeed");
        break;
     /* case 0xFFFFFFFF:
        speed = speed + 10; Serial.print(speed, DEC);
        Serial.println(" ism*");
        break;*/
        case B_OK:
        lspeed = 0; rspeed = 0; Serial.print(rspeed, DEC);
        Serial.println(" OK speed=0");
        break;
        case B_BLUE:
        digitalWrite(LED, HIGH);
        Serial.println("LED on");
        break;
        case B_YELLOW:
        digitalWrite(LED, LOW);
        Serial.println("LED off");
        break;
    }    
    //ha nyomva tartok egy gombot, akkor FFFFFFF jön. 
    //el kell menteni az utolsó parancsot, 
    //és az FFFFF annak ismétegetését jelenthet i
    if(lspeed>0){ lMotor->run(FORWARD);}
    else {lMotor->run(BACKWARD);}
    lMotor->setSpeed(abs(lspeed));
    
    if(rspeed>0){ rMotor->run(FORWARD);}
    else {rMotor->run(BACKWARD);}
    rMotor->setSpeed(abs(rspeed));
  }
  delay(10);
}
