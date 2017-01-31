#include <DHT.h> // biblioteka DHT
#include <VirtualWire.h>

#define led_pin 11
#define transmit_pin 10

#define DHTPIN 2 // numer pinu sygnałowego
#define DHTTYPE DHT22 // typ czujnika (DHT11). Jesli posiadamy DHT22 wybieramy DHT22

DHT dht(DHTPIN, DHTTYPE); // definicja czujnika

float a = 0.0,b = 0.0;
String toSend="";
void setup() { 
  Serial.begin(9600); // otworzenie portu szeregowego
  dht.begin(); // inicjalizacja czujnika

  //vw_setup(2000);
  //vw_set_tx_pin(transmit_pin);
}


void loop() {
  // Odczyt temperatury i wilgotnosci powietrza
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  
  
  if (isnan(t) || isnan(h))
    {
    Serial.println("Blad odczytu danych z czujnika");
    } 
    else
    {
      // Jeśli tak, wyświetlamy wyniki pomiaru

    if(a != h || b != t)
    {
      Serial.print("Wilgotnosc: ");
      Serial.print(h);
      Serial.print(" % ");
      Serial.print("Temperatura: ");
      Serial.print(t);
      Serial.println(" *C");
      a = h;
      b = t;
      
      toSend = String(t, DEC) + "$"+ String(h, DEC) + "$";
      char msg[15]; //char array to copy the String into
   
      toSend.toCharArray(msg, toSend.length() + 1); //Copy the string (+1 is to hold the terminating null char)
      Serial.println(msg);
       
      digitalWrite(led_pin, HIGH); 
      vw_send((uint8_t *)msg, strlen(msg));
      vw_wait_tx(); 
      digitalWrite(led_pin, LOW);
    }
  }
 delay(500);
}


