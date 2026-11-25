# Semana 3 - Sinais analógicos e digitais

## Tabela de E/S
| Tag | Endereço | Tipo (Natureza) | Faixa/Estado | Função (Papel) |
|---|---|---|---|---|
| BTN_COMANDO | D2 | DI (Entrada Discreta) | HIGH/LOW | Comando/estado |
| POT_BRUTO | A0 | AI (Entrada Analógica) | 0-1023 | Variável simulada |
| DHT22_SENSOR | D4 | Digital codificada | - | Temperatura/umidade |
| LED_ALARME | D8 | DO (Saída Discreta) | OFF/ON | Sinalização |
| PCT_CALCULADO| Interno | Numérico | 0-100% | Variável derivada |

## Casos de teste
| Caso | Entrada | Esperado | Obtido | Situação |
|---|---|---|---|---|
| A1 | Botão solto; pot mínimo | 0; próximo de 0 | 0, 0 | Validado |
| A2 | Botão pressionado; pot mínimo | 1; próximo de 0 | 1, 0 | Validado |
| A3 | Botão solto; pot meio | 0; próximo de 512 | 0, 489 | Validado |
| A4 | Botão solto; pot máximo | 0; próximo de 1023 | 0, 1015 | Validado |
| A5 | Teste Lim. Inferior (Planilha) | Estado FALHA (<0) | Bruto -10 = FALHA | Validado (injetado) |
| A6 | Teste Lim. Superior (Planilha) | Estado FALHA (>100) | Bruto 1050 = FALHA | Validado (injetado) |

## Conclusão
O simulador e a folha de cálculo validam adequadamente a lógica de conversão e escalonamento (0-1023 para 0-100%) e a prioridade dos estados (FALHA, PERIGO, ATENÇÃO, NORMAL). O gráfico de tendência construído na folha de cálculo demonstra o comportamento dinâmico da grandeza ao longo do tempo. É importante ressalvar que a simulação de software não valida parâmetros físicos reais, tais como a tolerância dos resistores, o ruído eletromagnético no cabo, o aterramento ou o comportamento elétrico de um transmissor industrial físico.
