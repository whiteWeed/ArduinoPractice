void setup() {
  Serial.begin(9600);
  pinMode(13, 1);
}

void loop() {
  if(Serial.available()){
    int a = Serial.read() - 48;

    if(a == 1){
      digitalWrite(13, 1);
    }
    else if(a == 0){
      digitalWrite(13, 0);
    }
  }
}
