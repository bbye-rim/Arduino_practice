int speakerPin = 8; //스피커 핀 설정

int numTones = 8; //for문 반복수 설정 : 톤의 개수
//도레미파솔라시도 진동수 배열로 저장
int tones[] = {261, 277, 294, 311, 330, 349, 370, 392};

void setup() {
  
}

void loop() {
  //도레미파솔라시도 순서대로 소리 나오도록
  for(int i=0; i<numTones; i++) {
    tone(speakerPin, tones[i]); //tone함수 : tone(출력핀, 진동수)
    delay(500);
  }
  noTone(speakerPin); //소리 재생 모두 정지
  delay(1000);
}
