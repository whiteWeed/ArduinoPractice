//마스터
//복도에 설치되어 사감이 지나가는 것을 감지하면
//슬레이브에게 신호를 보낸다.
#include <SoftwareSerial.h>

const int Echo = 13;
const int Trig = 12;
const int txpin = 2;
const int rxpin = 3;

SoftwareSerial bt(txpin, rxpin);

void setup() {
  Serial.begin(9600);
  bt.begin(9600);
  pinMode(Echo, 1);
  pinMode(Trig, 0);
}

void loop() {
  long dur;
  long dis;
  char sig;

  digitalWrite(Echo, 0);
  delayMicroseconds(2);

  digitalWrite(Echo, 1);
  delayMicroseconds(5);
  digitalWrite(Echo, 0);

  dur = pulseIn(Trig, 1);

  dis = dur / 58;

  Serial.println(dis);
  if (dis <= 50) {
    bt.write("1");
    delay(20);
  }
  else {
    bt.write("0");
    delay(20);
  }

  delay(80);
}
