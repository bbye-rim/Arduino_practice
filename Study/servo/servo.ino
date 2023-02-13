#include <Servo.h>
int servoPin = 9;
Servo servo;
// int angle = 0;

void setup() {
  Serial.begin(9600);
  // attach()
  // 몇번핀에 서보모터가 연결되어 있는지 확인하고 알려주는 함수
  servo.attach(servoPin); 
  Serial.println("각도를 입력하세요. (0~180도)");
  // write()
  // PWM 신호를 각도에 맞게 내보내라.
  servo.write(0);
}

void loop() {
// 기본예제
//  for (angle=0; angle<180; angle=angle+10) {
//    servo.write(angle);
//    delay(1000);
//  }
//  for (angle=180; angle>0; angle=angle-10) {
//    servo.write(angle);
//    delay(1000);
//  }

// 입력값에 따른 서보모터 회전 각도 제어
// 다시 0도로 돌아가지 않는 방법이 무엇일까....
  if (Serial.available()) {
    int angle = Serial.parseInt();
    Serial.println(angle);
    if ((angle >= 0) && (angle <= 180)) {
      servo.write(angle);
      delay(15);
    }
    else {
      Serial.println("0~180의 값을 입력하세요.");
      delay(15);
    }
  }
}
