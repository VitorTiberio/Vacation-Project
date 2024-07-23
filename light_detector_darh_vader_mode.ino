//Develop by Vitor Augusto Tibério - Undergraduate at Electrical Engineering - University São Paulo (USP) - Brazil
//From this code, I used a part of project from Abhishek Ghosh
// Link from his Git: https://github.com/AbhishekGhosh/Arduino-Buzzer-Tone-Codes/blob/master/star-wars.ino 
// I adapt his code for this apliccation
//=============================================================================================================================================================
// Varáveis de Controle da Lógica Eletrônica
int ldr = A0; 
int valorldr = 0; 
int led = 11;
int controle = 0;
int buzzer = 10;
//=============================================================================================================================================================
// Defining the melodies
#define  c3    7634
#define  d3    6803
#define  e3    6061
#define  f3    5714
#define  g3    5102
#define  a3    4545
#define  b3    4049
#define  c4    3816    // 261 Hz 
#define  d4    3401    // 294 Hz 
#define  e4    3030    // 329 Hz 
#define  f4    2865    // 349 Hz 
#define  g4    2551    // 392 Hz 
#define  a4    2272    // 440 Hz 
#define  a4s   2146
#define  b4    2028    // 493 Hz 
#define  c5    1912    // 523 Hz
#define  d5    1706
#define  d5s   1608
#define  e5    1517    // 659 Hz
#define  f5    1433    // 698 Hz
#define  g5    1276
#define  a5    1136
#define  a5s   1073
#define  b5    1012
#define  c6    955
#define  R     0      // "Reset" note
// Melody 1: Star Wars Imperial March
int melody1[] = { a4, R,  a4, R,  a4, R,  f4, R, c5, R,  a4, R,  f4, R, c5, R, a4, R,  e5, R,  e5, R,  e5, R,  f5, R, c5, R,  g5, R,  f5, R,  c5, R, a4, R};
int beats1[]  = { 50, 20, 50, 20, 50, 20, 40, 5, 20, 5,  60, 10, 40, 5, 20, 5, 60, 80, 50, 20, 50, 20, 50, 20, 40, 5, 20, 5,  60, 10, 40, 5,  20, 5, 60, 40};
//=============================================================================================================================================================
// Melody 2: Star Wars Theme
int melody2[] = { f4,  f4, f4,  a4s,   f5,  d5s,  d5,  c5, a5s, f5, d5s,  d5,  c5, a5s, f5, d5s, d5, d5s, c5, R};
int beats2[]  = { 21,  21, 21,  128,  128,   21,  21,  21, 128, 64,  21,  21,  21, 128, 64,  21, 21,  21, 128, 40 }; 
//=============================================================================================================================================================
int MAX_COUNT = sizeof(melody1) / 2; // Melody length, for looping. 
int MAX_COUNT_2 = sizeof(melody2) / 2; // Melody lenght for looping
long tempo = 10000; // Set overall tempo
int pause = 1000; // Set length of pause between notes
int rest_count = 50; // Loop variable to increase Rest length (BLETCHEROUS HACK; See NOTES)
int toneM = 0;
int beat = 0;
long duration  = 0;

void setup(){
  pinMode(ldr, INPUT); 
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  
}
void playTone() {
  long elapsed_time = 0;
  if (toneM > 0) { // if this isn't a Rest beat, while the tone has 
    //  played less long than 'duration', pulse speaker HIGH and LOW
    while (elapsed_time < duration) {
 
      digitalWrite(buzzer,HIGH);
      delayMicroseconds(toneM / 2);
 
      // DOWN
      digitalWrite(buzzer, LOW);
      delayMicroseconds(toneM / 2);
 
      // Keep track of how long we pulsed
      elapsed_time += (toneM);
    } 
  }
  else { // Rest beat; loop times delay
    for (int j = 0; j < rest_count; j++) { // See NOTE on rest_count
      delayMicroseconds(duration);  
    }                                
  }                                 
}

void loop(){
  digitalWrite(led, LOW);
  valorldr= analogRead(ldr);
  Serial.print("Valor lido pelo LDR: ");
  Serial.println(valorldr);
  if (valorldr > 900) {
  digitalWrite(led, HIGH);
  for (int i=0; i<MAX_COUNT_2; i++) {
    toneM = melody2[i];
    beat = beats2[i];
    duration = beat * tempo; // Set up timing
    playTone(); // A pause between notes
    delayMicroseconds(pause);
    }
  valorldr = analogRead(ldr);
  }
  else if (valorldr < 600) {
  digitalWrite(led, HIGH); 
  for (int i=0; i<MAX_COUNT; i++) {
    toneM = melody1[i];
    beat = beats1[i];
    duration = beat * tempo; // Set up timing
    playTone(); // A pause between notes
    delayMicroseconds(pause);
    }
  valorldr = analogRead(ldr);
  }
}