#include <Servo.h>
int servoPin = 9;
Servo servo;
int angle = 0;
int echo = 3;
int trig = 2;

// 문이 열렸는지 닫혔는지 상태 확인
boolean isOpened = false;

void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  servo.attach(servoPin);
  servo.write(angle);
}

void loop() {
  // 트리거 신호 발생
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  // 물체와의 왕복시간 측정
  unsigned long duration = pulseIn(echo, HIGH);

  // 물체와의 거리 계산
  int distance = ((float)(340 * duration) / 10000) / 2;
  Serial.print(distance);
  Serial.println("cm");

  // 물체와의 거리에 따른 서보모터 동작 제어
  if ((distance > 1) && (distance <= 30)) {
    if (isOpened == false) {
      Serial.println("OPEN");
      for (angle=0; angle<=180; angle++) {
        servo.write(angle);
        delay(10);
      }
      isOpened = true;
    }
  }
  else if ((distance > 30) && (distance <= 100)) {
    if (isOpened == true) {
      Serial.println("CLOSE");
      for (angle=180; angle<=0; angle--) {
        servo.write(angle);
        delay(10);
      }
      isOpened = false;
    }
  }
  else {
    Serial.println("측정 범위 벗어났습니다.");
    servo.write(0);
    isOpened = false;
  }
  delay(3000);
}
