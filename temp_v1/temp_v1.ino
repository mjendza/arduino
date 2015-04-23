#include <IRremote.h>
#include <SoftwareSerial.h>
//http://www.arduino.cc/en/Reference/SoftwareSerial
int RECV_PIN = 5;
IRrecv irrecv(RECV_PIN);
decode_results results;

SoftwareSerial mySerial(10, 11); // RX, TX

void setup()
{
  Serial.begin(9600);
 
  irrecv.enableIRIn(); // Start the receiver
  digitalWrite(6, HIGH);
  //digitalWrite(12, HIGH);  
  pinMode(6, OUTPUT);     
  //pinMode(12, OUTPUT);
  
    // set the data rate for the SoftwareSerial port
  mySerial.begin(4800);
  mySerial.println("Hello, world?");
  
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    //FF6897 button "1"

    irrecv.resume(); // Receive the next value
  }
  delay(4000);
  digitalWrite(6, HIGH); // dioda na Arduino
  //digitalWrite(12, HIGH); // przekaźnik
  delay(4000);
  digitalWrite(6, LOW);
  //digitalWrite(12, LOW);
  
//   if (mySerial.available())
//    Serial.write(mySerial.read());
//  if (Serial.available())
//    mySerial.write(Serial.read());
}


