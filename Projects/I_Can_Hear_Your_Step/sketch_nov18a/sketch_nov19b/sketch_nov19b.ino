int sensorPin = A0;
int LEDPin = 11;
int buzzerPin = 10;

void setup() {
  pinMode(sensorPin, 0);
  pinMode(LEDPin, 1);
  pinMode(buzzerPin, 1);
  Serial.begin(9600);
}

void loop() {
  Serial.println(analogRead(sensorPin));
  if(analogRead(sensorPin) <= 900){
    digitalWrite(buzzerPin, 1);
    digitalWrite(LEDPin, 1);
    delay(500);
    digitalWrite(buzzerPin, 0);
    digitalWrite(LEDPin, 0);
    delay(500);
  }
}
