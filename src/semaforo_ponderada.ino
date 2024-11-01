// Definindo os pinos para os LEDs 
#define ledVer 33   
#define ledVerm 14 
#define ledAm 26    

void setup() {
  // Configurando os pinos dos LEDs como saída 
  pinMode(ledVer, OUTPUT);
  pinMode(ledVerm, OUTPUT);
  pinMode(ledAm, OUTPUT);
}

void loop() {
  // Acende o LED vermelho por 6 segundos
  digitalWrite(ledVer, LOW);      // LED verde apagado
  digitalWrite(ledVerm, HIGH);    // LED vermelho aceso
  digitalWrite(ledAm, LOW);       // LED amarelo apagado
  delay(6000);                    // Aguarda 6 segundos

  // Acende o LED amarelo por 2 segundos
  digitalWrite(ledVer, LOW);      // LED verde apagado
  digitalWrite(ledVerm, LOW);     // LED vermelho apagado
  digitalWrite(ledAm, HIGH);      // LED amarelo aceso
  delay(2000);                    // Aguarda 2 segundos

  // Acende o LED verde por 2 segundos
  digitalWrite(ledVer, HIGH);     // LED verde aceso
  digitalWrite(ledVerm, LOW);     // LED vermelho apagado
  digitalWrite(ledAm, LOW);       // LED amarelo apagado
  delay(2000);                    // Aguarda 2 segundos

  // Acende o LED amarelo por mais 2 segundos
  digitalWrite(ledVer, LOW);      // LED verde apagado
  digitalWrite(ledVerm, LOW);     // LED vermelho apagado
  digitalWrite(ledAm, HIGH);      // LED amarelo aceso
  delay(2000);                    // Aguarda 2 segundos
}
