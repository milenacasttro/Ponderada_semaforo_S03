# Ponderada Semana 03 - Semáforo offline

## Parte 1: Montagem Física do Semáforo

Durante a atividade proposta em sala, realizei a montagem de um circuito que possibilita simular o funcionamento de um semáforo. Primeiramente, para iniciar a produção do semáforo, separei os componentes necessários para a sua montagem, que podem ser obervados na tabela abaixo:

| Componente                 | Quantidade | Especificações                     |
|----------------------------|------------|-------------------------------------|
| LED Verde (alto brilho)    | 1          | Tensão: 3V, Corrente: 20-30mA      |
| LED Vermelho (alto brilho) | 1          | Tensão: 2V, Corrente: 20-30mA      |
| LED Amarelo (alto brilho)  | 1          | Tensão: 2V, Corrente: 20-30mA      |
| Resistores                 | 3          | 330 ohms                           |
| Microcontrolador           | 1          | ESP32                               |
| Protoboard                 | 1          | Tamanho padrão                           |
| Jumper macho-macho         | 1          | Cor azul                            |
| Jumpers macho-fêmea        | 3          | Cor laranja                         |
| Jumpers macho-fêmea        | 3          | Cor azul                            |
| Cabo USB                   | 1          | Tipo: USB-A para Micro-USB |


Bom, após separar os componentes necessários eu estruturei o seguinte circuito:

<div align="center">
<sub>Figura 1 - Circuito do Semáforo</sub><br>
<img src="/assets/circuito.jpg" width="80%" ><br>
<sup>Fonte: Material produzido pelo autor (2024)</sup>
</div>

O circuito acima é montado em uma protoboard, onde o ESP32 está conectado, possibilitando a interação com os LEDs. Para estabelecer a conexão entre o microcontrolador e os LEDs, foram utilizados fios macho-fêmea laranjas, que indicam a tensão de 3,3V. Esses fios foram utilizados para conectar os terminais positivos dos LEDs aos pinos do ESP32, estabelecendo as seguintes ligações:

- LED Vermelho: Pino 14;
- LED Amarelo: Pino 26;
- LED Verde: Pino 33.

Os terminais negativos dos LEDs foram conectados à protoboard utilizando fios macho-fêmea azuis. Cada terminal negativo foi ligado a um resistor de 330 ohms, que atua como limitador de corrente, evitando que os LEDs recebam uma corrente acima do suportado. Os resistores foram conectados na extremidade da protoboard, formando um ponto de junção para todos os terminais negativos. Esses terminais negativos, em conjunto com os resistores, foram, então, conectados ao pino GND do ESP32 por meio de um fio macho-macho azul.

## Parte 2: Programação e Lógica do Semáforo

Após a montagem do circuito, realizei a criação de um código que seguisse a lógica exigida para o funcionamento do semáforo:

- 6 segundos ligado no vermelho;
- 2 segundos ligado no amarelo;
- 2 segundos ligado no verde;
- 2 segundos ligado no amarelo.

Primeiramente, realizei a definição dos pinos utilizados pelos LEDs:

```c++
// Definindo os pinos para os LEDs 
#define ledVer 33   
#define ledVerm 14 
#define ledAm 26    
```

Após isso, estruturei a função `void setup`, que define os pinos como os pinos estão sendo usados para cada um dos LEDs:

```c++
void setup() {
  // Configurando os pinos dos LEDs como saída 
  pinMode(ledVer, OUTPUT);
  pinMode(ledVerm, OUTPUT);
  pinMode(ledAm, OUTPUT);
}  
```

Por fim, montei a função `void loop`, que foi responsável pela lógica de acender a apagar os LEDs corretos pelo tempo determinado acima. Sendo assim, toda a função foi construida seguindo a mesma estrutura: Definição do estado dos LEDs (HIGH - acesso ou LOW - apagado) seguidos pela defição de um delay de acordo com as instruções de duração.

```c++
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
```

Juntando o circuito montado e o código explicado acima, pode-se obter o semáforo funcionando como mostrado no vídeo: 
_[Vídeo do Semáforo](https://youtube.com/shorts/deZxTAHkoFo?feature=share)_

## Parte 3: Avaliação de Pares

Trio de Avaliação: Milena Castro, Carolina Santos e Cecília Coelho.

## Avaliação Recebida:

#### Avaliadora: Carolina Santos

#### Avaliada: Milena Castro

|Critério|	Contempla (Pontos)|	Contempla Parcialmente (Pontos)	|Não Contempla (Pontos)	|Observações do Avaliador|
|-|-|-|-|-|
|Montagem física com cores corretas, boa disposição dos fios e uso adequado de resistores	|X|--|--| 3- O protótipo físico está bem organizado com os fios das cores corretas (laranja e azul) para ligar os positivos e negativos dos leds com a esp32|	
|Temporização adequada conforme tempos medidos com auxílio de algum instrumento externo	|X|--|--|3- O semáforo segue os tempos corretos estabelecidos pelo exercício, utilizando delay de 2 e 6 segundos de acordo com a cor do semáforo |	
|Código implementa corretamente as fases do semáforo e estrutura do código (variáveis representativas e comentários) |X|--|--| 3- Código organizado, variáveis bem estabelecidas e claras e código comentado|	
|Ir além: Implementou um componente de extra, fez com millis() ao invés do delay() e/ou usou ponteiros no código |--|-- |0 | Não implementado|	
| | | | |Pontuação Total: 9|

## Demais Avaliações:

#### Avaliadora: Milena Castro

#### Avaliada: Cecília Coelho

|Critério|	Contempla (Pontos)|	Contempla Parcialmente (Pontos)	|Não Contempla (Pontos)	|Observações do Avaliador|
|-|-|-|-|-|
|Montagem física com cores corretas, boa disposição dos fios e uso adequado de resistores	| X	| --	| -- | A montagem e o uso de resistores estão feitos de maneira correta, o uso dos fios está seguindo as conveções dentro das restrições de cabos disponíveis. |	
|Temporização adequada conforme tempos medidos com auxílio de algum instrumento externo	| X	| --	| -- | |	
|Código implementa corretamente as fases do semáforo e estrutura do código (variáveis representativas e comentários) |	X |	-- |	--  | Código organizado e comentado.|	
|Ir além: Implementou um componente de extra, fez com millis() ao invés do delay() e/ou usou ponteiros no código |	X |	-- |	-- |Implementou dois componentes extras (buzzer e sensor ultrassonico), além de também utilizar millis. |	
| | | | |Pontuação Total: 10 |

#### Avaliadora: Cecília Coelho

#### Avaliada: Carolina Santos

|Critério|	Contempla (Pontos)|	Contempla Parcialmente (Pontos)	|Não Contempla (Pontos)	|Observações do Avaliador|
|-|-|-|-|-|
|Montagem física com cores corretas, boa disposição dos fios e uso adequado de resistores	| X	|--	|--  |--   |	
|Temporização adequada conforme tempos medidos com auxílio de algum instrumento externo	| X	|--	| --  | --  |	
|Código implementa corretamente as fases do semáforo e estrutura do código (variáveis representativas e comentários) | X |--	 |-- |--  |	
|Ir além: Implementou um componente de extra, fez com millis() ao invés do delay() e/ou usou ponteiros no código |	-- | X |	-- |-- |	
| | | | |Pontuação Total: 9,5|

