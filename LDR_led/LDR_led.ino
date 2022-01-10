int cds = A0;
int led = 11;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  int cdsValue = analogRead(cds);
  Serial.print("cds = ");
  Serial.print(cdsValue);
  if (cdsValue >=400) {
    digitalWrite(led, HIGH);
    Serial.println("LED ON");
  }
  else {
    digitalWrite(led, LOW);
    Serial.println("LED OFF");
  }
  delay(500);
}
