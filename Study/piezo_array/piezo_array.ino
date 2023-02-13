int piezo = 3;
int numTones = 8;

int tones[] = {262, 294, 330, 349, 392, 440, 494, 523};

void setup() {
  pinMode(piezo, OUTPUT);
}

void loop() {
  for (int i = 0; i < numTones; i++) {
    tone(piezo, tones[i]);
    delay(500);
  }
  noTone(piezo);
  delay(1000);
}
