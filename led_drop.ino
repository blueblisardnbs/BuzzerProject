int start = 2;
int stop = 11;

int buzzerPin = 13;

void dropLed(int lag, int buzzTime){

  for (int led = start; led <= stop; led++){
    int st = millis();
    while((millis() - st) < lag){
       digitalWrite(led ,HIGH);
    }
    digitalWrite(led, LOW);
  }
  
  int sto = millis();
  while(millis() - sto < buzzTime){
    tone(buzzerPin, 800); 
  }
  noTone(buzzerPin);
}

void setup() {
  for (int led = start; led <= stop; led++){
    pinMode(led, OUTPUT);
  }
}

void loop() {
  dropLed(50, 300);
  delay(1000);
}
