#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

// sin retorno y sin argumentos
void mostrarDatos() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.print("Humedad: ");
  Serial.print(h);
  Serial.print(" % - Temp: ");
  Serial.print(t);
  Serial.println(" °C");
}

//  sin retorno y con argumentos
void imprimirMensaje(String texto) {
  Serial.println(texto);
}

//  con retorno y sin argumentos
float leerTemperatura() {
  return dht.readTemperature();
}

//  con retorno y con argumentos
float multiplicar(float a, float b) {
  return a * b;
}


void loop() {
  mostrarDatos();                 
  delay(1000);

  float t1 = leerTemperatura();   
  delay(1000);
  float t2 = leerTemperatura();

  float resultado = multiplicar(t1, t2);  
  imprimirMensaje("Multiplicación de temperaturas:");  
  Serial.println(resultado);

  if (resultado > 200) {
    Serial.print("PELIGRO: T1=");
    Serial.print(t1);
    Serial.print(" °C, T2=");
    Serial.println(t2);
  }

  delay(1000);
}
