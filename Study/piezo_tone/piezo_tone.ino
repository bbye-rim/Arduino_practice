int piezo = 3;
int del = 1000;

void setup() {
  pinMode(piezo, OUTPUT);
}

void loop() {
  tone(piezo, 261);
  delay(del);
  tone(piezo, 293);
  delay(del);
  tone(piezo, 329);
  delay(del);
  noTone(piezo);
  delay(del);
}
