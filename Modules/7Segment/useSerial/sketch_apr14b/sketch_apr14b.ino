int num[10][7] = {
/*      7
*  8         6
*       12
*  9        11
*      10
*  6  7  8  9  10 11 12 */
  {0, 0, 0, 0, 0, 0, 1}, //0
  {0, 1, 1, 1, 1, 0, 1}, //1
  {0, 0, 1, 0, 0, 1, 0}, //2
  {0, 0, 1, 1, 0, 0, 0}, //3
  {0, 1, 0, 1, 1, 0, 0}, //4
  {1, 0, 0, 1, 0, 0, 0}, //5
  {1, 0, 0, 0, 0, 0, 0}, //6
  {0, 0, 0, 1, 1, 0, 1}, //7
  {0, 0, 0, 0, 0, 0, 0}, //8
  {0, 0, 0, 1, 0, 0, 0}  //9
};
void setup() {
  pinMode(6, 1); //세그먼트 핀
  pinMode(7, 1); //세그먼트 핀
  pinMode(8, 1); //세그먼트 핀
  pinMode(9, 1); //세그먼트 핀
  pinMode(10, 1); //세그먼트 핀
  pinMode(11, 1); //세그먼트 핀
  pinMode(12, 1); //세그먼트 핀
  pinMode(5, 1); //10의 자리
  pinMode(4, 1); //1의 자리
  Serial.begin(9600);
}

void loop() {
  int n1, n2;
  if(Serial.available()){
    n1 = Serial.read() - 48; //시리얼에 입력된 두자리 수 중 첫번째 수를 n1에 저장
    delay(10);                //시리얼 대기
    n2 = Serial.read() - 48; //시리얼에 입력된 두자리 수 중 두번째 수를 n2에 저장
    delay(10);                //시리얼 대기
    Serial.println((String)n1 + " " +(String)n2); //시리얼에 입력된 수 확인
    segment(n1, n2);           //세그먼트 구현 함수 호출
  }
}
void segment(int n1, int n2){
  int count;
  while(!Serial.available()){ //시리얼에 값 들어오기 전까지 반복
    count = 0;
    digitalWrite(5, 1); //10의자리 세그먼트 켜기
    digitalWrite(4, 0); //1의 자리 세그먼트 끄기
    for(int i = 6; i <= 12; i++){
      digitalWrite(i, num[n1][count]); //배열에 미리 저장해 둔 정보를 불러옴
      count++;
    }
    count = 0;
    delay(10);
    digitalWrite(5, 0); //10의자리 세그먼트 끄기
    digitalWrite(4, 1); //1의 자리 세그먼트 켜기
    for(int i = 6; i <= 12; i++){
      digitalWrite(i, num[n2][count]); //배열에 미리 저장해 둔 정보를 불러옴
      count++;
    }
    delay(10);
  }
}

