//ranges dos valores dos canais 1 e 2
int minEsquerda = 998;
int maxEsquerda = 1400;
int minDireita = 1550;
int maxDireita = 1970;

int minFrente = 1550;
int maxFrente = 1988;
int minTras = 990;
int maxTras = 1420;

int ch1Pin = A0;
int ch2Pin = A1;
int velocidadePin = 6;
int motorEsquerdoFrentePin = 2;
int motorEsquerdoTrasPin = 3;
int motorDireitoFrentePin = 4;
int motorDireitoTrasPin = 5;

void setup() {
  Serial.begin(9600);
  pinMode(ch1Pin,INPUT);
  pinMode(ch2Pin,INPUT);

  pinMode(velocidadePin, OUTPUT);
  pinMode(motorEsquerdoFrentePin, OUTPUT);
  pinMode(motorEsquerdoTrasPin, OUTPUT);
  pinMode(motorDireitoFrentePin, OUTPUT);
  pinMode(motorDireitoTrasPin, OUTPUT);
}



void loop() {
double ch1 = pulseIn(ch1Pin,HIGH);
double ch2 = pulseIn(ch2Pin,HIGH);


//prints para identificar os ranges de cada canal
//Serial.print("ch1: ");
///Serial.print(ch1);
//Serial.print("\t");
//Serial.print("ch2: ");
Serial.print(velocidade(ch2));
Serial.println("");

analogWrite(velocidadePin, 0);
digitalWrite(motorEsquerdoFrentePin, LOW);
digitalWrite(motorEsquerdoTrasPin, LOW);
digitalWrite(motorDireitoFrentePin, LOW);
digitalWrite(motorDireitoTrasPin, LOW);

if(analogicoPraFrente(ch2)){
  analogWrite(velocidadePin, velocidade(ch2));

  if(!analogicoPraEsquerda(ch1) && !analogicoPraDireita(ch1)){
    //Serial.print("pra frente"); 
    digitalWrite(motorEsquerdoFrentePin, HIGH);
    digitalWrite(motorDireitoFrentePin, HIGH);
  }
  else if(analogicoPraDireita(ch1)){
    //Serial.print("pra frente à direita");
    digitalWrite(motorEsquerdoFrentePin, HIGH);
  }
  else{
    //Serial.print("pra frente à esquerda");
    digitalWrite(motorDireitoFrentePin, HIGH);
  }
}

else if(analogicoPraTras(ch2)){
  analogWrite(velocidadePin, velocidade(ch2));

  if(!analogicoPraEsquerda(ch1) && !analogicoPraDireita(ch1)){
    //Serial.print("pra tras");
    digitalWrite(motorEsquerdoTrasPin, HIGH);
    digitalWrite(motorDireitoTrasPin, HIGH);
  }
  else if(analogicoPraDireita(ch1)){
    //Serial.print("pra tras à direita");
    digitalWrite(motorEsquerdoTrasPin, HIGH);
  }
  else{
    //Serial.print("pra tras à esquerda");
    digitalWrite(motorDireitoTrasPin, HIGH);
  }
}

else {
  analogWrite(velocidadePin, 120);

  if(analogicoPraDireita(ch1)){
    //Serial.print("giro para direita");
    digitalWrite(motorEsquerdoFrentePin, HIGH);
    digitalWrite(motorDireitoTrasPin, HIGH);
  }
  else if(analogicoPraEsquerda(ch1)){
    //Serial.print("giro para esquerda");
    digitalWrite(motorEsquerdoTrasPin, HIGH);
    digitalWrite(motorDireitoFrentePin, HIGH);
  }
}

}

int velocidade(double ch) {
  int velocidade = 0;
  int velocidadeFrente = map(ch, minFrente, maxFrente, 0, 255);   
  int velocidadeTras = map((maxTras + minTras) - ch, minTras, maxTras, 0, 255); 

  if (velocidadeFrente > 0 || velocidadeTras > 0){
    if(velocidadeFrente > velocidadeTras){
      velocidade = velocidadeFrente;
    }
    else{
      velocidade = velocidadeTras;
    }
  }
  return velocidade;
}
bool analogicoPraFrente(double ch){
  return ch >= minFrente;
}
bool analogicoPraTras(double ch){
  return ch <= maxTras;
}
bool analogicoPraEsquerda(double ch){
  return ch <= maxEsquerda;
}
bool analogicoPraDireita(double ch){
  return ch >= minDireita;
}



