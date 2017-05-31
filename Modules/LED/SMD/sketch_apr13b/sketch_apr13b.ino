void setup() {
  pinMode(9, 1);
  pinMode(10, 1);
  pinMode(11, 1);
  Serial.begin(9600);
}

void loop() {
  int r, g, b;
  if(Serial.available()){
    r = Serial.read() - 48;
    delay(5);
    g = Serial.read() - 48;
    delay(5);
    b = Serial.read() - 48;
    delay(5);
    r = map(r, 0, 9, 0, 1023);
    g = map(g, 0, 9, 0, 1023);
    b = map(b, 0, 9, 0, 1023);
    Serial.println((String)r + " " + (String)g + " " + (String)b);
  }
  while(!Serial.available()){
    analogWrite(11, r);
    analogWrite(10, g);
    analogWrite(9, b);
  }
}
