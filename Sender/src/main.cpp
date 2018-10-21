
#include <Manchester.h>
#include <Arduino.h>


#define TX_PIN  1  //pin where your transmitter is connected



char textToSend[] = "Foi agora foi";
uint8_t data[200];
void setup() 
{
  man.workAround1MhzTinyCore(); //add this in order for transmitter to work with 1Mhz Attiny85/84
  man.setupTransmit(TX_PIN, MAN_9600);
}


void loop() 
{
  data[0] = strlen(textToSend)+1;
  strcat(data, textToSend); 
  man.transmitArray(data[0],data); 
  memset(data, 0, 200);
  delay(5000);
}