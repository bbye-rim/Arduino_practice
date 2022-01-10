int red=11;
int green=10;
int blue=9;
int sw=7;
int count;

void setup() {
  count=0;
  Serial.println(count);
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(sw, INPUT_PULLUP);
}

void setLEDcolor(int red_color, int green_color, int blue_color) {
  analogWrite(red,red_color);
  analogWrite(green,green_color);
  analogWrite(blue,blue_color);
}

void loop() {
  if (digitalRead(sw)==LOW) {
    count=count+1;
    delay(1000);
    Serial.println(count);
  }
  if (count==0) setLEDcolor(0,0,0);
  if (count==1) setLEDcolor(255,0,0);
  if (count==2) setLEDcolor(0,255,0);
  if (count==3) setLEDcolor(0,0,255);
  if (count==4) setLEDcolor(255,255,255);
  if (count==5) count=0;
}
