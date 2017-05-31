#include <SoftwareSerial.h> //시리얼통신 라이브러리 호출

int blueTx = 2; //Tx (보내는핀 설정)at
int blueRx = 3; //Rx (받는핀 설정)
int LED = 12;
bool LED_st = 0;
String myString = "";
int buzzerPin = 10;
SoftwareSerial mySerial(blueTx, blueRx);  //시리얼 통신을 위한 객체선언

void setup() {
  pinMode(12, 0); //신호 받는 핀
  pinMode(LED, 1);
  Serial.begin(9600);   //시리얼모니터
  mySerial.begin(9600); //블루투스 시리얼
}

void loop() {
  if (digitalRead(12) == 1) { //신호 들어오면
    mySerial.write("AT+ROLE=S\r"); //모드 바까주고
    mySerial.print("받은 문자"); //문자 보내줌
    mySerial.write("AT+ROLE=M\r"); //다시 모드 바까줌
  }
  if (mySerial.available()) {
    char myChar = (char)mySerial.read();
    myString += myChar;
    delay(5);
  }
  digitalWrite(LED, LED_st);
  delay(100);
  LED_st = !LED_st;
}
