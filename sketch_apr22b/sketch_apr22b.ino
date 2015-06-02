#include "pins_arduino.h"

void setup (void)
{
  Serial.begin (9600);
  pinMode(MISO, OUTPUT);
  pinMode (MOSI, INPUT);
  SPCR |= _BV(SPE);
  SPCR |= _BV(SPIE);

}

ISR (SPI_STC_vect)
{
  
  //byte c = shiftIn (MOSI, SCK, LSBFIRST);
  //c = c + 1 ;
  //shiftOut (MISO, SCK,LSBFIRST, c);
  Serial.println(SPDR);
  //byte c = SPDR;
  //Serial.println(c);
  //SPDR = c + 1 ;
  //Serial.println(SPDR);
}

void loop (void)
{
  //if (digitalRead (SS) == HIGH)
    //;
  
}
