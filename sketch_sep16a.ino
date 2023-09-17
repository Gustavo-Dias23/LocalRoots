#include <Adafruit_Sensor.h>
#include <DHT.h>

#define DHTPIN 7      // Define a porta em que o sensor está conectado
#define DHTTYPE DHT11 // Define o tipo de sensor DHT que você está usando

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(2000); // Aguarda alguns segundos entre as leituras

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Verifica se a leitura foi bem-sucedida
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Falha ao ler o sensor DHT!");
    return;
  }

  Serial.print("Umidade: ");
  Serial.print(humidity);
  Serial.print("%\t");

  Serial.print("Temperatura: ");
  Serial.print(temperature);
  Serial.println("°C");
}