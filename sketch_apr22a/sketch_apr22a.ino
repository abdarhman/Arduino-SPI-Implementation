#include "pins_arduino.h"
#include <stdio.h>
#include <Arduino.h>
#include <avr/pgmspace.h>
void setup ()
{
  Serial.begin(9600);
  digitalWrite(SS, HIGH);
  pinMode(SS, OUTPUT);
  //SPCR |= _BV(MSTR);
  //SPCR |= _BV(SPE);
  pinMode(SCK, OUTPUT);
  pinMode(MOSI, OUTPUT);
}
byte c = 0;
byte r = 0;
void loop ()
{
  
  if (Serial.available () > 0)
  {
    digitalWrite(SS, LOW);
    c = Serial.read();
    sendspi(c);
    r = receivespi();
    if (r <= 57 && r >= 48)
    {
      r = r - '0' ;
      Serial.println (r);
    }
    else 
    {
      char t = r ;
     Serial.println (t); 
    }
    
    
  }
  digitalWrite(SS, HIGH);
}
void sendspi (byte c)
{
  shiftOut (MOSI, 13 , MSBFIRST , c);
  delay (500);
}
byte receivespi ()
{
  byte income = shiftIn (MISO, SCK, MSBFIRST);
  Serial.println ("receiving");
  return income;
}
