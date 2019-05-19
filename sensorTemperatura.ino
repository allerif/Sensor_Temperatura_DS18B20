
/*
  Programa: Sensor temperatura DS18B20
  Autor: Izabelle Aller
*/

// Bibliotecas para o DS18B20:

#include <OneWire.h> // Ler o sensor de temperatura.
#include <DallasTemperature.h> // Converte o dado para valores em graus Celsius.

// Definir porta do DS18B20:

#define portaTemperatura 2

// Definir uma instancia do oneWire para comunicacao com o sensor:

OneWire oneWire(portaTemperatura);

// Passar referencia oneWire para Dallas Temperature:

DallasTemperature sensorTemperatura(&oneWire);

/********************************************************************/

void setup(void)
{

  // Iniciar porta serial :

  Serial.begin(9600);

  // Iniciar sensor:

  sensorTemperatura.begin();

}

/********************************************************************/

void loop(void)
{

  // Ler dados do sensor:

  sensorTemperatura.requestTemperatures();

  // Mostra dados no serial monitor:

  // Serial.print("Temperatura [C]: ");
  Serial.println(sensorTemperatura.getTempCByIndex(0));

  // Aguardar 1 segundo:

  delay(1000);

}
/********************************************************************/
