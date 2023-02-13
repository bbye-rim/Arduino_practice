void setup() {  //setup()함수 : 초기 설정
  pinMode(5, OUTPUT);   //아두이노 5번 핀을 OUTPUT 모드로 설정
}

void loop() {   //loop()함수 : 
  digitalWrite(5, 1);  //5번 핀 HIGH
  //1,000msec == 1초
  delay(1000);  //-초 상태 유지
  digitalWrite(5, 0);   //5번 핀 LOW
  delay(1000);  //-초 상태 유지 
}
