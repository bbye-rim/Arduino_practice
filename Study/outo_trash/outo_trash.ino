//가까이가면 자동으로 열리는 쓰레기통
//코드 참고 링크
//https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=dokkosam&logNo=221256779261

//핀 번호 설정은 필요시 수정하여 사용
//외형 구상은 링크 상관없이 자유롭게

#include <Servo.h>

#define SERVO_PIN 9 //서보모터 핀 설정

//초음파 센서 핀 설정
int echo = 6;
int trig = 7;

//서보모터 객체 설정
Servo myservo;

//int cnt = 0;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  myservo.attach(SERVO_PIN); //서보모터 초기화
}

void loop() {
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  unsigned long duration = pulseIn(echo, HIGH);
  float distance = ((34000 * duration) / 1000000) / 2; //초음파센서값 cm단위로 변환

//각도는 직접 실행해서 확인해보면서 수정  
  if (distance <=10) {
    myservo.write(150);
    delay(3000);
//    if(cnt >= 10){
//      myservo.write(150);
//    }
//    else cnt = cnt + 2;
  }
  else {
    myservo.write(90);
//    if (cnt == 0) {
//      myservo.write(90);
//    }
//    else cnt--;
  }
//  delay(100);
}
