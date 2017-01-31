#include "DHT.h" // biblioteka DHT

#define DHTPIN 2 // numer pinu sygnałowego
#define DHTTYPE DHT22 // typ czujnika (DHT11). Jesli posiadamy DHT22 wybieramy DHT22

DHT dht(DHTPIN, DHTTYPE); // definicja czujnika

float a = 0.0,b = 0.0;

void setup()
{
Serial.begin(9600); // otworzenie portu szeregowego
dht.begin(); // inicjalizacja czujnika
}

void loop()
{
// Odczyt temperatury i wilgotności powietrza
float t = dht.readTemperature();
float h = dht.readHumidity();

// Sprawdzamy czy są odczytane wartości
if (isnan(t) || isnan(h))
{
// Jeśli nie, wyświetlamy informację o błędzie
Serial.println("Blad odczytu danych z czujnika");
} else
{
// Jeśli tak, wyświetlamy wyniki pomiaru

if(a != h || b != t){
  Serial.print("Wilgotnosc: ");
  Serial.print(h);
  Serial.print(" % ");
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.println(" *C");
  a = h;
  b = t;
}

}
}


