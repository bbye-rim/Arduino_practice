int piezo = 3;
int del = 1000;

void setup() {
  pinMode(piezo, OUTPUT);
}

void loop() {
  analogWrite(piezo, 0);
  delay(del);
  analogWrite(piezo, 63);
  delay(del);
  analogWrite(piezo, 127);
  delay(del);
  analogWrite(piezo, 249);
  delay(del);
}
