#include <Servo.h>

Servo myservo;
int servopin = 5;

const unsigned long timeBetweenPlayMS = 1000ul*60ul*60ul*24ul;
const unsigned long timeRoundMin = 1000ul;
const unsigned long timeRoundMax = 6000ul;
const int degreemin = 40;
const int degreemax = 140;

const int playrounds = 200;

const int PLAY = 0;
const int WAIT = 1;

int state = PLAY;
int currentround = playrounds;
unsigned long lastPlayTime;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(servopin);
 
  state = PLAY;
  lastPlayTime = millis();
  currentround = playrounds;
}

void loop() {
  if(state == PLAY) {
    doplay();
  } else {
    dowait();
  }
  
}

void doplay() {
  int degree = random(degreemin, degreemax);
  int dlay = random(timeRoundMin, timeRoundMax);
  
  myservo.write(degree);
  delay(dlay);
  currentround--;
  
  if(currentround == 0) {
    state = WAIT;
  }
}
void dowait() {
  if(millis() - lastPlayTime > timeBetweenPlayMS) {
    state = PLAY;
    lastPlayTime = millis();
    currentround = playrounds;
  }
}

