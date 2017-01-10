int transpin = 8;
int temppin = A4;

int ON = 49;
int OFF = 48;
int TEMP = 50;

float REF_VOLT_ON =3.3;
float REF_VOLT_OFF = 3.3;
bool onrightnow = false;

void setup() {
  Serial.begin(9600);
  analogReference(EXTERNAL);
  // put your setup code here, to run once:
  pinMode(transpin, OUTPUT);
  pinMode(temppin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    int in = Serial.read();
    
    if(in == ON) {
      onthings();
    }
    if(in == OFF) {
      offthings();
    }
    if(in == TEMP) {
      tempthings();
    }
    delay(1000);
  }
}

void onthings() {
  digitalWrite(transpin, HIGH);
  onrightnow = true;
  Serial.println("turning on");
}
void offthings() {
  digitalWrite(transpin, LOW);
  onrightnow = false;
  Serial.println("turning off");
}
void tempthings() {
  int read = analogRead(temppin);

  float refvolt = REF_VOLT_OFF;
  if(onrightnow) {
    refvolt = REF_VOLT_ON;
  }
  
  float v = read * refvolt;
  v /= 1024.0;

  Serial.print("v=");Serial.println(v);
  // now print out the temperature
  float temperatureC = (v - 0.5) * 100 ;  //converting from 10 mv per degree wit 500 mV offset
                                          //to degrees ((voltage - 500mV) times 100)
  Serial.print(temperatureC); Serial.println(" degrees C");
  
  // now convert to Fahrenheit
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
  Serial.print(temperatureF); Serial.println(" degrees F");  
  Serial.println(temperatureF);
}

