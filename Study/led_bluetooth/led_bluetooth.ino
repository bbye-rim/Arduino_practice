//LED 조도센서 및 블루투스 연결

#include <SoftwareSerial.h>

SoftwareSerial btSerial = SoftwareSerial(9,10);

int mainLed = 3;
int subLed = 4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  btSerial.begin(9600);
  pinMode(mainLed, OUTPUT);
  pinMode(subLed, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  if(btSerial.available() >0){
    char btData = btSerial.read();

    if(btData == 'n') {
      digitalWrite(mainLed, HIGH);
    }
    else if(btData == 'f') {
      digitalWrite(mainLed, LOW);
    }
  }

  int cds = analogRead(A0); //A0으로 들어오는 값을 cds에 저장
  Serial.println(cds); //시리얼 모니터에 출력

  if(cds>900) {
    digitalWrite(subLed, HIGH);
  }
  else {
    digitalWrite(subLed, LOW);
  }
  delay(200);
}
