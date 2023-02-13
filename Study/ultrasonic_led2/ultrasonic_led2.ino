int echoPin = 3;
int trigPin = 2;
int bled = 8;
int rled = 7;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(bled, OUTPUT);
  pinMode(rled, OUTPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  digitalWrite(echoPin, LOW);
  delayMicroseconds(2);
  //트리거 신호 발생
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  //pulseIn()함수 이용하여 왕복시간 계산
  unsigned long duration = pulseIn(echoPin, HIGH);
  //cm로 환산하여 물체와의 거리 계산
  int distance = ((float)(340 * duration) / 10000) / 2;
  if ((distance > 1) && (distance <= 5)) {
    Serial.print(distance);
    Serial.println("cm");
    digitalWrite(bled, LOW);
    digitalWrite(rled, HIGH);
  }
  else if ((distance > 5) && (distance <= 10)) {
    Serial.print(distance);
    Serial.println("cm");
    digitalWrite(bled, HIGH);
    digitalWrite(rled, LOW);
  }
  else {
    Serial.print(distance);
    Serial.println("cm");
    digitalWrite(bled, LOW);
    digitalWrite(rled, LOW);
  }
  delay(500);
}
