
void setup() {
  pinMode(9, 1);
  pinMode(10, 1);
  pinMode(11, 1);
}

void loop(){
  int r = 0, g = 0, b = 0;
  if(Serial.available()){
    r = Serial.read() - 48;
    delay(5);
    g = Serial.read() - 48;
    delay(5);
    b = Serial.read() - 48;
    delay(5);
    Serial.println((String)r + " " + (String)g + " " + (String)b);
  }
  analogWrite(9, b);
  analogWrite(10, g);
  analogWrite(11, r);
}
