void setup() {
  pinMode(13, 1);
  pinMode(12, 1);
  pinMode(11, 1);
  Serial.begin(9600);
  digitalWrite(13, 0);
  digitalWrite(12, 0);
  digitalWrite(11, 0);
}

void loop() {
  int num;
  if(Serial.available()){
    num = Serial.read() - 48;
    delay(5);
  }
  if(num == 1){
    while(!Serial.available()){
      on(13);
      delay(500);
      off(11);
      on(12);
      delay(500);
      off(13);
      on(11);
      delay(500);
      off(12);
    }
    off(13);
    off(12);
    off(11);
  }
  if(num == 2){
    while(!Serial.available()){
      on(13);
      delay(250);
      off(13);
      delay(250);
      on(13);
      on(12);
      delay(250);
      off(13);
      off(12);
      delay(250);
      on(13);
      on(12);
      on(11);
      delay(250);
      off(13);
      off(12);
      off(11);
      delay(250);
      on(12);
      on(11);
      delay(250);
      off(12);
      off(11);
      delay(250);
      on(11);
      delay(250);
      off(11);
      delay(250);
    }
    off(13);
    off(12);
    off(11);
  }
}
void on(int i){
  digitalWrite(i, 1);
}
void off(int i){
  digitalWrite(i, 0);
}

