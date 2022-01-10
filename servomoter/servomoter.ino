//응용문제 sketch
//기본 스케치는 맨 아래에
//자세한건 책 참고

#include <Servo.h> //기본
int servoPin=9; //기본
Servo servo; //기본
int angle=0; //기본
int echoPin=3; //응용
int trigPin=2; //응용
boolean isOpened=false; //응용

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  servo.attach(servoPin);
  servo.write(angle); //초기화
}

void loop() {
  digitalWrite(trigPin, LOW);
  digitalWrite(echoPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  unsigned long duration=pulseIn(echoPin, HIGH);
  int distance=((float)(340*duration)/10000)/2;
  Serial.print(distance);
  Serial.println("cm");

  if ((distance>1)&&(distance<=5)) {
    if(isOpened==false) {
      Serial.println("open");
      for(angle=0; angle<=180; angle++) {
        servo.write(angle);
        delay(10);
      }
      isOpened=true;
    }
  }
  else if ((distance>5)&&(distance<100)) {
    if(isOpened==true) {
      Serial.println("close");
      for (angle = 180; angle >=0; angle--) {
        servo.write(angle);              
        delay(10);                       
      }
      isOpened=false;
    }
  }
  else {
    Serial.println("범위에서 벗어났습니다.");
    servo.write(0);
    isOpened=false;
  }
  delay(3000);

// servo motor sketch
//  for (angle = 0; angle < 180; angle++) {
//    servo.write(angle);       
//    delay(15);
//  }
//
//  for (angle = 180; angle > 0; angle--) {
//    servo.write(angle);              
//    delay(15);                       
//  }

}
