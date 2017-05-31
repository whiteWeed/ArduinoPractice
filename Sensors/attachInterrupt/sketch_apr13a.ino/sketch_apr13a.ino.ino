volatile int B = 0;
void setup(){
  pinMode(11, 1);
  pinMode(12, 1);
  Serial.begin(9600);
  attachInterrupt(0, LED, RISING);
  digitalWrite(12, 0);
}

void loop(){
  digitalWrite(11, B);
}

void LED(){
  B = !B;
}

