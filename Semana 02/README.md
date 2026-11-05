# Semana 2: Processos, Sensores e Transdutores

## 1. Objetivo do Protótipo
Construir uma estação de monitorização que integre uma entrada discreta (botão), uma entrada analógica contínua (potenciómetro) e uma medição de temperatura (DHT22), atuando sobre um LED e classificando estados de processo.

## 2. Mapa de Pinos e Ligações
* **BTN (Pushbutton):** Pino D2 e GND (Usa INPUT_PULLUP, acionado em LOW).
* **LED:** Pino D8 e GND (Em série com resistência de 220 Ω).
* **POT (Potenciómetro):** Pino A0 (Alimentado por 5V e GND).
* **DHT22:** Pino D4 (Alimentado por 5V e GND).

## 3. Regras de Classificação (Prioridade)
1. **FALHA DE SENSOR:** Se a temperatura for inválida (NaN).
2. **ALARME:** Se Temperatura >= 40ºC OU Potenciómetro >= 750.
3. **ATENÇÃO:** Se Temperatura >= 30ºC OU Potenciómetro >= 400.
4. **NORMAL:** Nenhuma das regras anteriores satisfeita.

## 4. Limitações da Simulação e Seleção Industrial
A simulação comprova a coerência funcional, mas não valida alcance, resposta temporal, ruído elétrico, grau IP ou calibração. 
Numa câmara térmica industrial, os componentes didáticos seriam substituídos por:
* **Porta (Botão):** Sensor indutivo ou chave fim de curso industrial (24 Vcc).
* **Pressão (Potenciómetro):** Transmissor de pressão 0-10 bar (Sinal 4-20 mA).
* **Temperatura (DHT22):** RTD Pt100 com transmissor 4-20 mA.
