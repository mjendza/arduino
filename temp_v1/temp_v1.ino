#include <DHT.h>

#include <OneWire.h>
#include <DallasTemperature.h>
#include <EtherCard.h>

// Data wire is plugged into pin 7 on the Arduino
#define ONE_WIRE_BUS 7
// ethernet interface mac address, must be unique on the LAN
static byte mymac[] = { 0x74,0x69,0x69,0x2D,0x30,0x31 };
static byte myip[] = { 192,168,1,203 };

byte Ethernet::buffer[500];
BufferFiller bfill;

// Setup a oneWire instance to communicate with ANY OneWire devices 
OneWire oneWire(ONE_WIRE_BUS);

// Set oneWire reference to Dallas Temperature sensor. 
DallasTemperature sensors(&oneWire);

float h =0.0;
float f = 0.0; 
#define DHTTYPE DHT11 
#define DHTPIN 2 
DHT dht(DHTPIN, DHTTYPE);
void setup(void)
{
   //Serial.println("temp"); 
Serial.begin(9600);
//sensors.begin();

dht.begin();
//if (ether.begin(sizeof Ethernet::buffer, mymac) == 0)
//    Serial.println( "Failed to access Ethernet controller");
//  ether.staticSetup(myip);
  
  
  delay(10000);
}
void loop(void)
{
  readDht();
 // setHomePage();
//temp++;
//if(temp>8000){
  //temp=0;
  
  
  delay(1000);
//}

}
void setHomePage()
{
  //ethernet
 word len = ether.packetReceive();
  word pos = ether.packetLoop(len);
  
  if (pos)  // check if valid tcp data is received
    ether.httpServerReply(homePage()); // send web page data
}
void readDht(){
  //h = dht.readHumidity();
  // Read temperature as Celsius
  f = dht.readTemperature();
  
  
  Serial.println("temp"); 
  Serial.println(f); 
  //Serial.println(""); 
  //Serial.println("hum"); 
  //Serial.println(h); 
}
void readTemp()
{
 sensors.requestTemperatures();
Serial.println("");
delay(500);
Serial.print("Sensor 1: ");
Serial.println(sensors.getTempCByIndex(0)); // first founded sensor have Index 0 
}


static word homePage() {
  long t = millis() / 1000;
  word h = t / 3600;
  byte m = (t / 60) % 60;
  byte s = t % 60;
  bfill = ether.tcpOffset();
  bfill.emit_p(PSTR(
    "HTTP/1.0 200 OK\r\n"
    "Content-Type: text/html\r\n"
    "Pragma: no-cache\r\n"
    "\r\n"
    "<meta http-equiv='refresh' content='1'/>"
    "<title>Arduino server</title>"
    "<h1>$D$D:$D$D:$D$D</h1>"
    "<h1>temp $D</h1>"
    "<h1>hyd $3.5F</h1>"),
      h/10, h%10, m/10, m%10, s/10, s%10, f, h);
  return bfill.position();
}