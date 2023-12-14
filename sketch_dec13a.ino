void setup() {
  Serial.begin(9600);
  pinMode(3,INPUT);
  pinMode(5,INPUT);

}

int minEsquerda = 998;
int maxEsquerda = 1400;
int minDireita = 1550;
int maxDireita = 1970;

int minFrente = 1550;
int maxFrente = 1988;
int minTras = 998;
int maxTras = 1420;

void loop() {
double ch1 = pulseIn(3,HIGH);
double ch2 = pulseIn(5,HIGH);

Serial.print("ch2: ");
Serial.print(ch2);
Serial.print("\t");
Serial.print("velocidade: ");
Serial.print(velocidade(ch2));
Serial.print("\t");
Serial.print("analogicoPraFrente: ");
Serial.print(analogicoPraFrente(ch2));
Serial.print("\t");
Serial.print("analogicoPraTras: ");
Serial.print(analogicoPraTras(ch2));
Serial.print("\t");
Serial.print("analogicoPraEsquerda: ");
Serial.print(analogicoPraEsquerda(ch1));
Serial.print("\t");
Serial.print("analogicoPraDireita: ");
Serial.print(analogicoPraDireita(ch1));
Serial.println("");

if()

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



