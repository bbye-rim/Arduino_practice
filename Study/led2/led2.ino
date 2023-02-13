void setup() {
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  digitalWrite(4, 0);
  digitalWrite(5, 1);
  delay(1000);
  digitalWrite(4, 1);
  digitalWrite(5, 0);
  delay(1000);
}
