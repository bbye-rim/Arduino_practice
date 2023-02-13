void setup() {
  pinMode(13, OUTPUT); //led센서
  pinMode(8, INPUT); //버튼
}

void loop() {
  int value = digitalRead(8); //버튼으로 받은 값 저장 0 또는 1

  if(value == HIGH) { //버튼이 눌렸다면 led 켜기
    digitalWrite(13, HIGH);
  }
  else { //버튼이 눌리지 않았다면 led 끄기
    digitalWrite(13, LOW);
  }
}
