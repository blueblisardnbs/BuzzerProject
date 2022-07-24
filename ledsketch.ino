#include <Adafruit_NeoPixel.h>

#define SPEAKERPIN         42

#define GREENPIN        22
#define REDPIN          24

// Set-up of the LED-strips

#define NUMPIXELS      144 // The amount of LEDs in our strip

#define PIN1            11
#define PIN2            10
#define PIN3            9
#define PIN4            6

Adafruit_NeoPixel pixels1 = Adafruit_NeoPixel(NUMPIXELS, PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels2 = Adafruit_NeoPixel(NUMPIXELS, PIN2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels3 = Adafruit_NeoPixel(NUMPIXELS, PIN3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels4 = Adafruit_NeoPixel(NUMPIXELS, PIN4, NEO_GRB + NEO_KHZ800);

Adafruit_NeoPixel stripes[4] = {pixels1, pixels2, pixels3, pixels4};

// Set-up of the buttons

#define BUT1            2
#define BUT2            3
#define BUT3            4
#define BUT4            5

int buttons[4] = {BUT1, BUT2, BUT3, BUT4};

// Configuration of the basic parameters

int lighttime = 100; // Adjust to the time the LEDs will be on during each cycle. The smaller the value is, the faster (and harder) the game will be.
int slng = 2; // Change according to the length of the song (length in pixels/LEDs)

int pl1[4][1000][3]; // A plan of the order and REG color in which the pixels will light up for each LED strip

int strip[4][144][3]; // The configuration of all LEDs at a specific moment (in RGB) for each LED strip

bool play[4] = {false, false, false, false};
bool pressed[4] = {false, false, false, false};

int timestamp;

void setup() {
  
  Serial.begin(9600);

  for(int i = 0; i < 4; i++){
    
    stripes[i].begin();

    pinMode(buttons[i], INPUT_PULLUP);
  }

  pinMode(GREENPIN, OUTPUT);
  pinMode(REDPIN, OUTPUT);
}

// The program that is run

void green(){
  digitalWrite(GREENPIN, HIGH);
  tone(SPEAKERPIN, 100);//play a pleasant tone
}

void red(){
  digitalWrite(REDPIN, HIGH);
  //play an unpleasant tone
}


void loop() {

  green();
  /*
  for(int i = 0; i < 4; i++){
    if(!(strip[i][144][0] == 0 && strip[i][144][1] == 0 && strip[i][144][2] == 0)){
      play[i] = true;
    }
    pressed[i] = false;
  }
  
  for(int pixel = 1; pixel <= 144; pixel++){
    for(int i = 0; i < 4; i++){
      stripes[i].setPixelColor(i, stripes[i].Color(strip[pixel][0],strip[0][pixel][1],strip[0][pixel][2]));
    }
  }

  timestamp = millis();
  
  while(millis() - timestamp < lighttime){
    for(int i = 0; i < 4; i++){
      if(digitalRead(buttons[i]) == 0){
        pressed[i] = true;
      }
    }
  }
  
  for(int i = 0; i < 4; i++){
      stripes[i].show();
  }

  for(int i = 0; i < 4; i++){
    if(play[i] == true && pressed == true){
      green();
    }else{
      red();
    }
  }
  */
}
