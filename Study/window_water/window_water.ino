// water 센서 이용한 창문 컨트롤

#include <Servo.h>

Servo servo; // Servo 클래스로 servo 객체 생성
int val = 0; // 워터센서 변수
int degree = 0; // 서보모터 각도 조절 변수

//비올 때 창문 자동으로 닫히도록

void setup() {
  // put your setup code here, to run once:
  servo.attach(7); // 서보모터 핀 설정
  servo.write(degree);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(A0);
  Serial.print("water: ");
  Serial.println(val);
  if(val>100) {
    degree = 90;
    servo.write(degree);
  }
  else {
    degree = 0;
    servo.write(degree);
  }
  delay(500);
}
