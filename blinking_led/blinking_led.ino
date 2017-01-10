#include <Servo.h>

Servo myservo;

int inpin = A0;
int servopin = 5;
int ledpin = 3;
int potentval = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledpin, OUTPUT);
  myservo.attach(servopin);
}

void loop() {
  potentval = analogRead(inpin);//0 to 1023
  int val = map(potentval, 0, 1023, 0, 180);
  int ledval = map(potentval, 0, 1023, 0, 255);
  // put your main code here, to run repeatedly:
  analogWrite(ledpin, ledval);
  myservo.write(val);

  delay(15);
  
}
