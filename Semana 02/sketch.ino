#include <DHT.h>

const int BTN = 2;
const int LED = 8;
const int POT = A0;

#define DHTPIN 4
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// Variável global para guardar o estado anterior do alarme
bool alarmeTemperatura = false; 

void atualizarAlarmeTemperatura(float t) {
  if (isnan(t)) return;
  if (!alarmeTemperatura && t >= 40.0) {
    alarmeTemperatura = true; // liga em 40 ºC
  } else if (alarmeTemperatura && t <= 37.0) {
    alarmeTemperatura = false; // desliga em 37 ºC
  }
}

const char* classificarComHisterese(float t, int bruto) {
  if (isnan(t)) return "FALHA DE SENSOR";
  
  atualizarAlarmeTemperatura(t);
  
  if (alarmeTemperatura || bruto >= 750) return "ALARME";
  if (t >= 30.0 || bruto >= 400) return "ATENCAO";
  
  return "NORMAL";
}

void setup() {
  pinMode(BTN, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  bool detectado = (digitalRead(BTN) == LOW);
  digitalWrite(LED, detectado ? HIGH : LOW);
  
  int bruto = analogRead(POT);
  float t = dht.readTemperature();

  Serial.print("BTN=");
  Serial.print(detectado ? "PRESSIONADO" : "LIBERADO");
  Serial.print(" | POT=");
  Serial.print(bruto);
  Serial.print(" | TEMP=");

  if (isnan(t)) {
    Serial.print("INVALIDA | ESTADO=");
    Serial.print(classificarComHisterese(t, bruto));
  } else {
    Serial.print(t, 1);
    Serial.print(" C | ESTADO=");
    Serial.print(classificarComHisterese(t, bruto));
  }
  
  Serial.println();
  delay(1000);
}
