//슬레이브
//마스터 에게서 신호를 받아와서 LED를 깜빡이는 것을 통해
//사감의 출몰을 알려준다.
#include <SoftwareSerial.h>

const int red = 13;
const int white1 = 11;
const int white2 = 10;
const int txpin = 2;
const int rxpin = 3;

int i = 100;
int j;
int g_sta = 0;

SoftwareSerial bt(txpin, rxpin);

void danger();

void setup() {
  Serial.begin(9600);
  bt.begin(9600);
  pinMode(red, 1);
  pinMode(white1, 1);
  pinMode(white2, 1);
  digitalWrite(red, 0);
  analogWrite(white1, i);
  analogWrite(white2, i);
}

void loop() {
  int Sa_Gam;
  if (i == 255) {
    g_sta = 1;
  }
  else if (i == 100) {
    g_sta = 0;
  }
  if (bt.available()) {
    Sa_Gam = (int)bt.read();
    Serial.println(Sa_Gam);
    delay(10);
    if (Sa_Gam == 49) {
      danger();
      return;
    }
    else {
      analogWrite(white1, i);
      analogWrite(white2, i);
      if (g_sta == 0) i += 5;
      else if (g_sta == 1) i -= 5;
      delay(30);
    }
  }
}

void danger() {
  analogWrite(white1, 0);
  analogWrite(white2, 0);
  for (j = 0; j < 6; j++) {
    digitalWrite(red, 1);
    delay(250);
    digitalWrite(red, 0);
    delay(150);
  }
  return;
}

