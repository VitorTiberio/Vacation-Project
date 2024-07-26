int baixo = 8; //define green LED
int medio = 9; //define yellow LED 
int alto = 10; //define red LED 
int nivel = A0; //define analog pin 
int valor = 0; //define auxiliary variable
int buzzer = 11; //define speaker 
int contagem = 0; // define other auziliary variable

void setup() {
  pinMode (baixo, OUTPUT); //define green LED as output
  pinMode (medio, OUTPUT); //define yellow LED as output
  pinMode (alto, OUTPUT); //define red LED as output
  pinMode (nivel, INPUT); //define sensor as input (analog)
  pinMode(buzzer, OUTPUT); //define speaker as output
  Serial.begin(9600);
  digitalWrite(baixo, LOW);
  digitalWrite(medio, LOW);
  digitalWrite(alto, LOW);
}

void loop() {
  valor = analogRead(nivel); //read the analog value in sensor and "store" in "valor"
  Serial.print("Valor lido pelo sensor de nível: "); //print the value of level sensor in screen 
  Serial.println(valor); //print the data in serial port
  if (valor <= 580) {   //conditional to LED green works
    digitalWrite(baixo, HIGH);
    digitalWrite(medio, LOW);
    digitalWrite(alto, LOW);
    valor = analogRead(nivel);
  }
  else if (valor <= 630 && valor > 580){ //conditional to LED yellow works
    digitalWrite(baixo, LOW);
    digitalWrite(medio, HIGH);
    digitalWrite(alto, LOW);
    valor = analogRead(nivel);
  }
  else if (valor > 630){ //conditional to LED red and speaker works
    digitalWrite(baixo, LOW);
    digitalWrite(medio, LOW);
    digitalWrite(alto, HIGH);
    while (contagem <= 3){ //loop from speaker alarm (when the recipe is full)
      tone(buzzer, 1000);
      delay(500);
      contagem = contagem + 1;
    }
    valor = analogRead(nivel);
    contagem = 0;
  }
}
