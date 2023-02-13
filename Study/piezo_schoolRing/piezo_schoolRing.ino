#define a 262 //도
#define b 294 //레
#define c 330 //미
#define d 349 //파
#define e 392 //솔
#define f 440 //라
#define g 494 //시
#define h 523 //도

int piezo = 3;
int notes[] = {e,e,f,f,e,e,c,e,e,c,c,b,e,e,f,f,e,e,c,e,c,b,c,a};

void setup() {
  pinMode(piezo, OUTPUT);
}

void loop() {
  for (int i = 0; i < 7; i++) {
    tone(piezo, notes[i]);
    delay(500);
  }
  delay(1000);

  for (int i = 7; i < 12; i++) {
    tone(piezo, notes[i]);
    delay(500);
  }
  delay(1000);

  for (int i = 12; i < 19; i++) {
    tone(piezo, notes[i]);
    delay(500);
  }
  delay(1000);

  for (int i = 19; i < 24; i++) {
    tone(piezo, notes[i]);
    delay(500);
  }
  delay(1000);
}
