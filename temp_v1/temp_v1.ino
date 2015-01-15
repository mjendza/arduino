#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into pin 7 on the Arduino
#define ONE_WIRE_BUS 7

// Setup a oneWire instance to communicate with ANY OneWire devices 
OneWire oneWire(ONE_WIRE_BUS);

// Set oneWire reference to Dallas Temperature sensor. 
DallasTemperature sensors(&oneWire);

void setup(void)
{
Serial.begin(9600);
sensors.begin();
}
void loop(void)
{
sensors.requestTemperatures();
Serial.println("");
delay(500);
Serial.print("Sensor 1: ");
Serial.println(sensors.getTempCByIndex(0)); \\ first founded sensor have Index 0
}
