const int BTN = 2;
const int POT = A0;
const int LED_ALARME = 8;
unsigned long amostra = 0;

const char* classificar(float pct) {
  if (pct < 0.0 || pct > 100.0) return "FALHA";
  if (pct >= 85.0) return "PERIGO";
  if (pct >= 70.0) return "ATENCAO";
  return "NORMAL";
}

void setup() {
  pinMode(BTN, INPUT_PULLUP);
  pinMode(LED_ALARME, OUTPUT);
  Serial.begin(9600);
  Serial.println("amostra, botao, bruto, pct, tempC, estado");
}

void loop() {
  bool botao = digitalRead(BTN) == LOW;
  int bruto = analogRead(POT);
  
  // O sufixo .0 força o cálculo em ponto flutuante
  float pct = 100.0 * bruto / 1023.0;
  float tempC = pct; 
  
  const char* estado = classificar(pct);
  digitalWrite(LED_ALARME, pct >= 85.0);

  Serial.print(amostra++); Serial.print(",");
  Serial.print(botao); Serial.print(",");
  Serial.print(bruto); Serial.print(",");
  Serial.print(pct, 2); Serial.print(",");
  Serial.print(tempC, 2); Serial.print(",");
  Serial.println(estado);

  delay(500);
}const int BTN = 2;
const int POT = A0;
const int LED_ALARME = 8;
unsigned long amostra = 0;

const char* classificar(float pct) {
  if (pct < 0.0 || pct > 100.0) return "FALHA";
  if (pct >= 85.0) return "PERIGO";
  if (pct >= 70.0) return "ATENCAO";
  return "NORMAL";
}

void setup() {
  pinMode(BTN, INPUT_PULLUP);
  pinMode(LED_ALARME, OUTPUT);
  Serial.begin(9600);
  Serial.println("amostra, botao, bruto, pct, tempC, estado");
}

void loop() {
  bool botao = digitalRead(BTN) == LOW;
  int bruto = analogRead(POT);
  
  // O sufixo .0 força o cálculo em ponto flutuante
  float pct = 100.0 * bruto / 1023.0;
  float tempC = pct; 
  
  const char* estado = classificar(pct);
  digitalWrite(LED_ALARME, pct >= 85.0);

  Serial.print(amostra++); Serial.print(",");
  Serial.print(botao); Serial.print(",");
  Serial.print(bruto); Serial.print(",");
  Serial.print(pct, 2); Serial.print(",");
  Serial.print(tempC, 2); Serial.print(",");
  Serial.println(estado);

  delay(500);
}
