int led = 4; //포트 설정

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int cds = analogRead(A0); //A0으로 들어오는 값을 cds에 저장
  Serial.println(cds); //시리얼 모니터에 출력

  if(cds<200) {
    digitalWrite(led, HIGH);
  }
  else {
    digitalWrite(led, LOW);
  }
  delay(200);
}
