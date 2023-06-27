#include "DHT.h" 
#define DHTPIN A0
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}
 
void loop() {
  float h = dht.readHumidity();
  //Pembacaan untuk data kelembapan
  float t = dht.readTemperature();
  //Pembacaan dalam format celcius (c)
  if (isnan(h) || isnan(t)) {
    Serial.println("Pembacaan data dari module sensor gagal!");
    return;
  }
  float htoc = dht.computeHeatIndex(h, t, false);
  //Prosedur pembacaaan data indeks panas dalam bentuk celcius
  Serial.print(h);
  Serial.print("-");
  Serial.print(t);
  Serial.print("-");
  Serial.print(htoc);
  Serial.println("-");
  delay(1000);
}
