int red=11;
int green=10;
int blue=9;
//RGB led에서 가장 긴 다리가 GND
//GND에서 하나짜리가 R, 그 옆으로 순서대로 G, B

void setup() {
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}

void loop() {
  analogWrite(red,0);
  analogWrite(green,0);
  analogWrite(blue,0);
  delay(1000);

  analogWrite(red,255);
  analogWrite(green,0);
  analogWrite(blue,0);
  delay(1000);

  analogWrite(red,0);
  analogWrite(green,255);
  analogWrite(blue,0);
  delay(1000);

  analogWrite(red,0);
  analogWrite(green,0);
  analogWrite(blue,255);
  delay(1000);
}
