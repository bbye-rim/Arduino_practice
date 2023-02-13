// 블루투스 연결을 이용한 창문 컨트롤

#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(9, 10); // 블루투스 모듈의 Rx=10번핀, Tx=9번핀
Servo servo;

void setup() {
  // put your setup code here, to run once:
  servo.attach(7);
  Serial.begin(9600);
  mySerial.begin(9600);
  servo.write(90);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(mySerial.available()) {
    char myData = mySerial.read();

    if(myData == 'o') {
      servo.write(0);
    }
    if(myData == 'c') {
      servo.write(90);
    }
  }
}
