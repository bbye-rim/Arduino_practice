const int passiveB = 10; //스피커 핀
int bt[3] = {6, 7, 8}; //버튼 핀
int melody[3] = {262, 294, 330}; //도미솔 진동수

void setup() {
  //버튼 핀 설정
  for(int i=0; i<3; i++) {
    pinMode(bt[i], INPUT);
  }
}

void loop() {
  //6번 핀에 연결된 버튼이 눌린 경우 '도' 소리 재생
  if(digitalRead(bt[0]) == HIGH) {
    tone(passiveB, melody[0]);
  }
  //7번 핀에 연결된 버튼이 눌린 경우 '미' 소리 재생
  else if(digitalRead(bt[1]) == HIGH) {
    tone(passiveB, melody[1]);
  }
  //8번 핀에 연결된 버튼이 눌린 경우 '솔' 소리 재생
  else if(digitalRead(bt[2]) == HIGH) {
    tone(passiveB, melody[2]);
  }
  else {
    noTone(passiveB); //소리 재생 모두 정지
  }
}
