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
        VELOCIDADE_MOTOR = 0;}
    }

    int forca = 0;
    
    switch (VELOCIDADE_MOTOR) {
      case 0:
        forca = 0;  // Desliga o motor
        break;
      case 1:
        forca = 51;  // 20% da força (51/255)
        break;
      case 2:
        forca = 153;  // 60% da força (153/255)
        break;
      case 3:
        forca = 255;  // 100% da força (255/255)
        break;
      case 4:
        forca = 0;  // Desliga o motor
        break;
    }

    analogWrite(PIN9_MOTOR, forca);
  }
}
