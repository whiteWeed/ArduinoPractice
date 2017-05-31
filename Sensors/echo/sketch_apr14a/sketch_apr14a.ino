const int trig = 13;
const int echo = 12;

void setup() {
  Serial.begin(9600);
  pinMode(trig, 1);
  pinMode(echo, 0);
}

void loop() {
  int dur, dis;
  
  digitalWrite(trig, 1);
  delayMicroseconds(10);
  digitalWrite(trig, 0);
  
  dur = pulseIn(echo, 1);

  dis = dur / 58;

  if(dis > 200 || dis < 0){
    Serial.println("Out of Range");
  }
  else{
    Serial.print(dis);
    Serial.println(" cm");
  }
  delay(100);
}
