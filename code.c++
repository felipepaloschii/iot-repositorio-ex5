// C++ code
//
const int led1 = 11;
const int led2 = 10;
const int botao = 7;

int estado = 0;
int ultimoEstadoBotao = HIGH;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(botao, INPUT_PULLUP);

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
}

void loop() {
  int estadoBotao = digitalRead(botao);

  if (estadoBotao == LOW && ultimoEstadoBotao == HIGH) {
    estado++;

    if (estado > 3) {
      estado = 1;
    }

    if (estado == 1) {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
    }
    else if (estado == 2) {
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
    }
    else if (estado == 3) {
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
    }

    delay(200);
  }

  ultimoEstadoBotao = estadoBotao;
