#include <SoftwareSerial.h>
char receivedChar;
int  LED = 5; // LED on pin 13
SoftwareSerial mySerial(11, 12); // RX, TX

//RX on Bluetooth to TCX on Arduino through a voltage divider 50ohm from arduino and 100ohm to ground. This is so we can drop the the voltage down to 3.3v (roughly)
// Use blueterm on android to get messages
int sensorPin = A0;
void setup()
{
  // Open serial communications and wait for port to open:
  pinMode(LED, OUTPUT);
  mySerial.begin(9600);  
}

void loop() // run over and over
{

  while (!mySerial.available());   // stay here so long as COM port is empty
 
  receivedChar = mySerial.read();
  if (receivedChar == '1') {
    digitalWrite(LED, HIGH);
  }// if it's a 1 turn LED on
  if (receivedChar == '2') {
    digitalWrite(LED, LOW);
  } // if it's a 2 turn LED off
  
}

