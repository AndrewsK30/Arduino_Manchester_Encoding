
#include "Manchester.h"
#include <Arduino.h>

#define RX_PIN 5



#define BUFFER_SIZE 200
uint8_t buffer[BUFFER_SIZE];

void setup() 
{

  
  Serial.begin(9600);
  man.setupReceive(RX_PIN, MAN_9600);
  man.beginReceiveArray(BUFFER_SIZE, buffer);
  
  Serial.println("receiver");
}

void loop() 
{

  if (man.receiveComplete()) 
  {

    uint8_t receivedSize = 0;
    receivedSize = buffer[0];

    for(uint8_t i=1; i<receivedSize; i++)
      Serial.write(buffer[i]);
    
    Serial.println();

    man.beginReceiveArray(BUFFER_SIZE, buffer);
  }
}