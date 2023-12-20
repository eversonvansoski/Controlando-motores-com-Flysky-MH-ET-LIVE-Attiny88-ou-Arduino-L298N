//ranges dos valores dos canais 1 e 2
//comentados e utilizados nas funções no final do código para economia de memória, necessário pela limitação do MH-ET LIVE Tiny88
//caso utilize arduino, pode-se utilizar das variáveis globais, pois possui maior capacidade

//int minEsquerda = 998;
//int maxEsquerda = 1400;
//int minDireita = 1550;
//int maxDireita = 1970;
//int minFrente = 1550;
//int maxFrente = 1988;
//int minTras = 990;
//int maxTras = 1420;


int motorEsquerdoFrentePin = 5;
int motorEsquerdoTrasPin = 6;
int motorDireitoFrentePin = 7;
int motorDireitoTrasPin = 8;
int velocidadePin = 9;

void setup() {
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);

  pinMode(velocidadePin, OUTPUT);
  pinMode(motorEsquerdoFrentePin, OUTPUT);
  pinMode(motorEsquerdoTrasPin, OUTPUT);
  pinMode(motorDireitoFrentePin, OUTPUT);
  pinMode(motorDireitoTrasPin, OUTPUT);
}



void loop() {
double ch1 = pulseIn(A0,HIGH);
double ch2 = pulseIn(A1,HIGH);


//prints para identificar os ranges de cada canal
//Serial.print("ch1: ");
//Serial.print(ch1);

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
  //Serial.println("");
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
  //Serial.println("");
}

else {
  analogWrite(velocidadePin, 80);

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
  //Serial.println("");
}

}

int velocidade(double ch) {
  int velocidade = 0;
  if (ch > 0){
    int velocidadeFrente = map(ch, 1550, 1988, 0, 255);   
    int velocidadeTras = map((1420 + 990) - ch, 990, 1420, 0, 255); 

    if (velocidadeFrente > 0 || velocidadeTras > 0){
      if(velocidadeFrente > velocidadeTras){
        velocidade = velocidadeFrente;
      }
      else{
        velocidade = velocidadeTras;
      }
    }
  }
  if (velocidade > 3 && velocidade < 60){
    velocidade = 60;
  }
  return velocidade;
}

bool analogicoPraFrente(double ch){
  return ch >= 1550; //valor minimo do analógico para frente
}
bool analogicoPraTras(double ch){
  return ch <= 1420; //valor maximo do analógico para tras
}
bool analogicoPraEsquerda(double ch){
  return ch <= 1400; //valor maximo do analógico para a esquerda
}
bool analogicoPraDireita(double ch){
  return ch >= 1550; //valor minimo do analógico para a direita
}



