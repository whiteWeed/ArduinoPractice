#include "pitches.h"

int p = 9;

int melody[]={
  A3,G4,FS4,E4,E4,FS4,0,
  A3,G4,FS4,E4,E4,FS4,D4,E4,A3,0,
  E4,FS4,G4,E4,CS4,D4,E4,A3,A3,FS4,0,
  A3,G4,FS4,E4,E4,FS4,0,
  A3,G4,FS4,E4,E4,FS4,D4,E4,A3,0
};
int noteduration[]={
  4,4,4,4,4,4,32,
  4,4,4,4,8,4,8,4,16,20,
  8,4,8,8,8,4,8,8,4,8,32,
  4,4,4,4,4,4,32,
  4,4,4,4,8,4,8,4,16,20
};

void Melody();

void setup() {
  pinMode(p, 1);
  pinMode(10, 0);
}

void loop() {
  if(digitalRead(10) == 0){
    Melody();
    delay(500);
  }
  else{
    delay(500);
  }
}

void Melody() {
  for(int note=0;note<45;note++){
      int delays=1000/noteduration[note]; //박자를 ms의 시간으로 바꿔주는 역할을 한다.
      tone(p,melody[note],delays);
   /*9번 핀의 melody[]만큼의 주파수를 delays의 시간동안 주게된다.*/
      int pause=delays*2;
      delay(pause); //한 음과 음 사이의 쉬는 박자를 넣어 준다. 
      noTone(p);
  }
}

