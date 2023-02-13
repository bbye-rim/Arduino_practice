int echoPin = 3;
int trigPin = 2;
int led = 7;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
// 없어도 상관없는 3줄
//  digitalWrite(trigPin, LOW);
//  digitalWrite(echoPin, LOW);
//  delayMicroseconds(2);
  //트리거 신호 발생
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  //pulseIn()함수 이용하여 왕복시간 계산
  unsigned long duration = pulseIn(echoPin, HIGH);
  //cm로 환산하여 물체와의 거리 계산
  int distance = ((float)(340 * duration) / 10000) / 2;
  //거리에 따른 led 제어문
  if ((distance > 5) && (distance < 10)) {
    Serial.print(distance);
    Serial.println("cm");
    digitalWrite(led, HIGH);
  }
  //led의 경우 else문이 없다면 LOW의 경우가 없기 때문에
  //else if (distance >= 10) 인 경우
  //5cm보다 작은 경우 HIGH상태를 유지하고 거리 출력이 되지 않는다.
  //led는 HIGH만 있기 때문에 LOW명령이 들어오기 전까지 꺼지지 않는 것...
  //else문이 없다면 if문을 제외한 부분에서 동작이 제대로 이루어지지 않는다.
  //else문을 쓰게 되면 다른 조건 없이 if문을 제외한 부분에 모두 동작하게 된다.

  //아래 else if 대신에 else를 써도 같은 말이다.
  //else {
  else if ((distance >= 10) || (distance <= 5)) {
    Serial.print(distance);
    Serial.println("cm");
    digitalWrite(led, LOW);
  }
  delay(500);
}
