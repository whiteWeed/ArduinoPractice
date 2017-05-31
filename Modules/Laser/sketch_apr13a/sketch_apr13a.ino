int laser = 10;
int button = 9;

void setup(){
  pinMode(laser, 1);
  pinMode(button, 0);
}

void loop(){
  if(!digitalRead(button)){
    digitalWrite(laser, 1);
  }
  else{
    digitalWrite(laser, 0);
  }
}

