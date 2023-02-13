//전역변수는 setup()보다 먼저 선언을 해주어야 함.
int echoPin = 3;
int trigPin = 2;

void setup() {
  Serial.begin(9600); //
  pinMode(trigPin, OUTPUT); //트리거 신호 내보내고
  pinMode(echoPin, INPUT);  //트리거 신호를 받아들이고
}

void loop() {
  //트리거 신호 발생
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  //pulseIn()함수 이용하여 왕복시간 계산
  unsigned long duration = pulseIn(echoPin, HIGH);
  //cm로 환산하여 물체와의 거리 계산
  float distance = ((float)(340 * duration) / 10000) / 2;
  Serial.print(distance);
  Serial.println("cm");   //cm로 거리 출력
  delay(500);
}
