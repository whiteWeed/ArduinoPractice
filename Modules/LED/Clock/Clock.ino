int H = 0, M = 0, H_pin = 2, M_pin = 3, cnt_M = 0, i;
int COL[4] = {10, 11, 12, 13}, ROW[6] = {4, 5, 6, 7, 8, 9};
int HOUR[12][2] = {
  {1, 5},
  {1, 4},
  {1, 3},
  {1, 2},
  {1, 1},
  {1, 0},
  {0, 5},
  {0, 4},
  {0, 3},
  {0, 2},
  {0, 1},
  {0, 0}
};
int MINUTE[12][2] = {
  {2, 0},
  {2, 1},
  {2, 2},
  {2, 3},
  {2, 4},
  {2, 5},
  {3, 0},
  {3, 1},
  {3, 2},
  {3, 3},
  {3, 4},
  {3, 5},
};
void setup() {
  for(i = 0; i < 4; i++){
    pinMode(COL[i], 1);
    digitalWrite(COL[i], 0);
  }
  for(i = 0; i < 6; i++){
    pinMode(ROW[i], 1);
    digitalWrite(ROW[i], 1);
  }
  pinMode(H_pin, 2);
  pinMode(M_pin, 2);
}

void loop() {
  if(digitalRead(H_pin) == 0){
    H += 1;
    delay(200);
    cnt_M += 20;
  }
  if(cnt_M == 30000){
    cnt_M = 0;
    M += 1;
  }
  if(H == 12){ H = 0; }
  if(M == 12){ M = 0; cnt_M = 0; H += 1; }
  digitalWrite(COL[HOUR[H][0]], 1);
  digitalWrite(ROW[HOUR[H][1]], 0);
  delay(20);
  digitalWrite(COL[HOUR[H][0]], 0);
  digitalWrite(ROW[HOUR[H][1]], 1);
  cnt_M += 2;
}
