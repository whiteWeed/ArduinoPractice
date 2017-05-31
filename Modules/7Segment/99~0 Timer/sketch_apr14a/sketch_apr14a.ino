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
}

void loop() {
  int n1, n2;
  for(int i = 100; i >=0; i--){
    if(i != 0){
      segment((i-1)/10, (i-1)%10); //첫번째 인수에 10의자리 저장, 두번째 인수에 1의자리 저장
    }
    else if(i == 0){
      i = 101; //후치감소 연산자 고려해서 101로 저장
    }
  }
}
void segment(int n1, int n2){
  int count;
  for(int j = 0; j < 50; j++){ //딜레이가 한번 반복에 20ms만큼 실행되니까 50번 반복으로 1초 만들어줌
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

