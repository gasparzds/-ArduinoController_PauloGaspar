1. [Introdução ao PWM](#introdução-ao-pwm)
O controlador PWM ajusta a largura dos pulsos de saída para controlar a velocidade do motor.

2. [Componentes necessários](#componentes-necessários)
Microcontrolador ou microprocessador: É o cérebro do controlador PWM, responsável por processar as entradas de referência e gerar o sinal PWM correspondente. O usado nesse projeto foi o Arduino.
Fonte de alimentação: Fornecerá a energia necessária para alimentar o controlador PWM e os componentes conectados a ele, nesse projeto foi uma bateria 5V
Componentes passivos: Nesse projeto foi utilizado resistor para garantir o bom funcionamento do controlador.
Circuitos de controle e lógica: São responsáveis por implementar a lógica de controle necessária para converter as entradas de referência em sinais PWM. Isso pode envolver o uso de comparadores, amplificadores operacionais e portas lógicas.
Botão de entrada: O botão foi  utilizado como uma forma de entrada de referência, foi  conectado a uma porta de entrada do microcontrolador e configurado para ler o estado do botão (pressionado ou não pressionado).
Driver do motor: Para fornecer a potência necessária ao motor, você precisará de um driver do motor. O driver converte o sinal PWM em sinais de potência adequados para acionar o motor. 

3. [Esquemático](#esquemático)
![ESQUEMATICO](https://github.com/gasparzds/-ArduinoController_PauloGaspar/assets/61299557/6b4e7a8b-aca4-4c03-bc0d-71a33da2e595)


4. [Código-fonte](#código-fonte)
#include <Arduino.h>

int PIN2_BOTAO = 2; int PIN9_MOTOR = 9; int SITUACAO = 0; int VELOCIDADE_MOTOR = 0;
unsigned long tempo_A = 0; 
unsigned long tempo_B = 50;


void setup() { pinMode(PIN2_BOTAO, INPUT_PULLUP);
               pinMode(PIN9_MOTOR, INPUT_PULLUP); }

void loop() {
  int aperto = digitalRead(PIN2_BOTAO);

  if (aperto != SITUACAO) {
    SITUACAO = aperto;

    if (aperto == HIGH) {
      VELOCIDADE_MOTOR++;
      if (VELOCIDADE_MOTOR > 4) {
        VELOCIDADE_MOTOR = 0;
      }
    }

    int forca = 0;

    switch (VELOCIDADE_MOTOR) {
      case 0:
        forca = 0;  
        break;
      case 1:
        forca = 51;  
        break;
      case 2:
        forca = 153;  
        break;
      case 3:
        forca = 255; 
        break;
      case 4:
        forca = 0;  
        break;
    }

    analogWrite(PIN9_MOTOR, forca);
  }
}


5. [Instruções de montagem](#instruções-de-montagem)
Microcontrolador: No Proteus, escolha um microcontrolador compatível com o Arduino. Você pode usar, por exemplo, o modelo "Arduino NANO"
Botão: Adicione um componente de botão no circuito. 
Motor: Adicione um motor ao circuito. 
Driver do motor: Para controlar o motor, você precisará de um driver adequado.
Conexões: Conecte um pino digital do microcontrolador ao pino do botão (no exemplo, o pino 2) e outro pino digital ao pino de controle do motor (no exemplo, o pino 9). Certifique-se de configurar os pinos corretamente como entradas ou saídas
Alimentação: Conecte as fontes de alimentação necessárias para o microcontrolador, o botão, o driver do motor e o próprio motor. Certifique-se de fornecer as voltagens corretas de acordo com as especificações dos componentes.


6. [Funcionamento do projeto](#funcionamento-do-projeto)

1ª PARTE
![image](https://github.com/gasparzds/-ArduinoController_PauloGaspar/assets/61299557/65a6a4c8-a564-4021-bc3e-ea43df90f4ad)
Essa linha inclui a biblioteca "Arduino.h", que fornece as funções e definições necessárias para programar o microcontrolador Arduino.

![image](https://github.com/gasparzds/-ArduinoController_PauloGaspar/assets/61299557/a8d1d1d5-d2da-4dd3-ba58-50fcabdcf08c)
Nessa seção, são definidas as constantes para os pinos do botão (2) e do motor (9), bem como as variáveis para a situação atual do botão, a velocidade do motor e os tempos A e B.

![image](https://github.com/gasparzds/-ArduinoController_PauloGaspar/assets/61299557/2225550a-bda0-485f-b148-ff499e492345)
A função setup() é chamada uma vez no início do programa. Nessa função, os pinos do botão e do motor são configurados como entradas pull-up. Isso significa que o pino interno de resistência pull-up será ativado para garantir um estado alto quando o botão não estiver pressionado.

![image](https://github.com/gasparzds/-ArduinoController_PauloGaspar/assets/61299557/cd49b139-219b-4997-ab54-6427b3a5d5cf)
![WhatsApp Image 2023-05-18 at 14 32 07](https://github.com/gasparzds/-ArduinoController_PauloGaspar/assets/61299557/f68924fc-7a3b-4f6f-a8ce-b0bbb69f7f24)
O código dentro da função loop() é executado repetidamente após a configuração inicial. Ele lê o estado atual do botão e verifica se houve uma mudança em relação ao estado anterior. Se o botão for pressionado (estado HIGH), a variável VELOCIDADE_MOTOR é incrementada. Se VELOCIDADE_MOTOR exceder 4, ele é reiniciado para 0. Em seguida, é feito um switch-case para determinar a força (valor PWM) a ser aplicada ao motor, com base no valor de VELOCIDADE_MOTOR. São especificados quatro níveis de velocidade diferentes, representados pelos valores 0, 51, 153 e 255. O caso 4 retorna 0 novamente, permitindo desligar o motor. Por fim, a função analogWrite() é usada para enviar o valor da força (PWM) ao pino do motor (PIN9_MOTOR), controlando assim a velocidade do motor.

RESUMO: No geral, o código funciona da seguinte maneira: sempre que o botão for pressionado, a velocidade do motor é incrementada. Quando a velocidade atinge o limite máximo (4), ela é reiniciada para 0. Em seguida, o código determina a força correspondente ao nível de velocidade atual e a aplica ao motor usando a função analogWrite(). O ciclo do loop() continua repetindo essas etapas indefinidamente, permitindo que o usuário ajuste a velocidade do motor através do botão.
