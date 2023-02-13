//자동으로 열리는 쓰레기통
//코드 참고 링크
//https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=dokkosam&logNo=221256779261

//닫힌 경우 빨간 led 켜지기
//열린 경우 초록 led 켜지기

/*핀 번호 설정은 필요시 수정하여 사용*/
/*외형 구상은 링크 상관없이 자유롭게*/

#include <Servo.h>

int SERVO_PIN = 3; //서보모터 핀 설정
//초음파 센서 핀 설정
int echo = 6;
int trig = 7;
//led 센서 핀 설정
int red = 8;
int green = 9;

//서보모터 객체 설정
Servo myservo;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  myservo.attach(SERVO_PIN); //서보모터 초기화
}

void loop() {
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  //거리 계산
  unsigned long duration = pulseIn(echo, HIGH);
  float distance = ((34000 * duration) / 1000000) / 2; //초음파센서값 cm단위로 변환

/*각도는 직접 실행해서 확인해보면서 수정*/
  //쓰레기통에 가까워질 경우 초록색 led가 켜지고 뚜껑이 열린다.
  if (distance <=10) {
    myservo.write(100);
    digitalWrite(green, HIGH);
    digitalWrite(red, LOW);
    delay(5000);
  }
  //쓰레기통에서 멀어진 경우 빨간색 led가 켜지고 뚜겅이 닫힌다.
  else {
    myservo.write(0);
    digitalWrite(green, LOW);
    digitalWrite(red, HIGH);
  }
  delay(100);
}
