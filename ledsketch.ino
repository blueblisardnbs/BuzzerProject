#include <Adafruit_NeoPixel.h>

#define SPEAKERPIN1         43
#define SPEAKERPIN2         45
#define SPEAKERPIN3         47
#define SPEAKERPIN4         49

int speakers[4] = {SPEAKERPIN1, SPEAKERPIN2, SPEAKERPIN3, SPEAKERPIN4};

#define GREENPIN        22
#define REDPIN          24

// Set-up of the LED-strips

#define NUMPIXELS      144 // The amount of LEDs in our strip

#define PIN1            3
#define PIN2            5
#define PIN3            6
#define PIN4            9

Adafruit_NeoPixel pixels1 = Adafruit_NeoPixel(NUMPIXELS, PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels2 = Adafruit_NeoPixel(NUMPIXELS, PIN2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels3 = Adafruit_NeoPixel(NUMPIXELS, PIN3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels4 = Adafruit_NeoPixel(NUMPIXELS, PIN4, NEO_GRB + NEO_KHZ800);

Adafruit_NeoPixel stripes[4] = {pixels1, pixels2, pixels3, pixels4};

// Set-up of the buttons

#define BUT1            23
#define BUT2            25
#define BUT3            27
#define BUT4            29

int buttons[4] = {BUT1, BUT2, BUT3, BUT4};

#define BUT1LIGHT            10
#define BUT2LIGHT            11
#define BUT3LIGHT            12
#define BUT4LIGHT            13

int buttonlights[4] = {BUT1LIGHT, BUT2LIGHT, BUT3LIGHT, BUT4LIGHT};

// Configuration of the basic parameters

int lighttime = 140; // Adjust to the time the LEDs will be on during each cycle. The smaller the value is, the faster (and harder) the game will be.
int slng = 2; // Change according to the length of the song (length in pixels/LEDs)

#define LEN             60

/*
int X[3] = {0,0,0};

int R[3] = {255,0,0};
int G[3] = {0,255,0};
int B[3] = {0,0,255};

int M[3] = {255,255,0};
int Y[3] = {255,0,255};
int C[3] = {0,255,255};
*/

String Ccolors[4] = {
  "X", "R", "G", "B"
};

int Icolors[4][3] = {
  {0,0,0},
  
  {255,0,0},
  {0,255,0},
  {0,0,255}
};

String plan[4][LEN] =

{/*
  {{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{100,0,0}},
  {{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}},
  {{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}},
  {{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{100,0,0},{0,0,0},{0,0,0},{100,0,0}},
}; // A plan of the order and REG color in which the pixels will light up for each LED strip
*/
  {"X","X","X","X","X","X","X","X","X","X","X","X","X","R","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X",},
  {"X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","G","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X",},
  {"X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","B","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X",},
  {"X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","B","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X",}
};

int planSounds[LEN] = 
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,440,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};


int r,g,b;

int strip[4][144][3]; // The configuration of all LEDs at a specific moment (in RGB) for each LED strip

int timestamp;

bool play[4] = {false, false, false, false};
bool pressed[4] = {false, false, false, false};

void setup() {

  Serial.begin(9600);

  for (int i = 0; i < 4; i++) {
    stripes[i].begin();
    stripes[i].clear();
    stripes[i].show();

    pinMode(buttons[i], INPUT_PULLUP);
    pinMode(buttonlights[i], OUTPUT);
  }

  pinMode(GREENPIN, OUTPUT);
  pinMode(REDPIN, OUTPUT);

}

// The program that is run


int minimum(int a, int b){
  if(a<b){return a;}else{return b;}
}

void playNoSound(){
  for(int i = 0; i < 4; i++){
    noTone(speakers[i]);
  }
}

void playSound(int frequency){
  for(int i = 0; i < 4; i++){
    tone(speakers[i], frequency);
  }
}

void played(int turn){
  timestamp = millis();
  while(millis() - timestamp < lighttime){
    for(int i = 0; i < 4; i++){
      if(digitalRead(buttons[i]) == 0){
        pressed[i] = true;
      } else {
        pressed[i] = false;
      }

      if(pressed[i] and play[i]){
        Serial.println("Pressed and palyed yay");
        Serial.println(turn);
        playSound(planSounds[turn -1]);
      }
    }
  }
  
  for(int i = 0; i < 4; i++){
    if(pressed[i] and play[i]){
      playNoSound();
    }
  }
}

void loop() {

  for (int turn = 0; turn < LEN; turn++) {
    
    for(int ledstrip = 0; ledstrip < 4; ledstrip++){
      digitalWrite(buttonlights[ledstrip], LOW); // all buttonlights are turned off
      
    }

    for(int pixel = -1; pixel < NUMPIXELS; pixel++){
      
      for(int ledstrip = 0; ledstrip < 4; ledstrip++){


      
      for(int i = 0; i < 4; i++){
        if(plan[ledstrip][pixel+turn] == Ccolors[i]){
          r = Icolors[i][0];
          g = Icolors[i][1];
          b = Icolors[i][2];
        }
      }

        stripes[ledstrip].setPixelColor(pixel, stripes[ledstrip].Color(r,g,b));
      }
      
      for(int ledstrip = 0; ledstrip < 4; ledstrip++){
        for(int i = 0; i < 4; i++){
          if(plan[ledstrip][pixel+turn] == Ccolors[i]){
            r = Icolors[i][0];
            g = Icolors[i][1];
            b = Icolors[i][2];
          }
        }

        if(pixel == -1){ // arrived at button(light)
          if(not(r == 0 and g == 0 and b == 0)){
            play[ledstrip] = true;
            digitalWrite(buttonlights[ledstrip], HIGH);
          } else { play[ledstrip] = false;}
        }
      }
      
      
    }
    for(int ledstrip = 0; ledstrip < 4; ledstrip++){
      stripes[ledstrip].show();
    }
    played(turn);
  }

  delay(1000);

}
