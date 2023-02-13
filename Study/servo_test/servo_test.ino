#include <Servo.h>
int SERVO_PIN = 3;
Servo myservo;

void setup() {
    myservo.attach(SERVO_PIN);
}

void loop() {
  myservo.write(100);
}
