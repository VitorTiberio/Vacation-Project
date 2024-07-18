//Developer: Vitor Augusto Tibério 
//Undergraduate - Electrical Engineering - University São Paulo (USP) - Brazil 

//Defining the variables

int buzzer = 10;
int green = 13;
int yellow = 12;
int red = 11; 

// In the setup, the code is going to run once a time
void setup() {
  pinMode (11, OUTPUT); //red light 
  pinMode (12, OUTPUT); //yellow light 
  pinMode (13, OUTPUT); //green light
  pinMode (10, OUTPUT); //buzzer 

}

void loop() {
  digitalWrite (green, HIGH); 
  delay(10000);
  digitalWrite(green, LOW);
  digitalWrite(yellow, HIGH); 
  delay(3000);
  digitalWrite(yellow, LOW);
  digitalWrite(red, HIGH);
  tone (buzzer, 3000);
  delay (1500);
  noTone(buzzer);
  delay(10000);
  digitalWrite(red,LOW);
  tone (buzzer, 1000);
  delay (1500);
  noTone (buzzer);
  delay (1500);
}
 