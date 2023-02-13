// 온습도 센서와 블루투스 연결을 이용한 에어컨 컨트롤

#include <DHT.h>
#include <SoftwareSerial.h>
DHT dht(8, DHT11);
SoftwareSerial btSerial(9, 10);

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  btSerial.begin(9600);
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  float humi = dht.readHumidity(); // 습도
  float temp = dht.readTemperature(); // 섭씨 온도

  btSerial.print("습도: ");
  btSerial.print(humi);
  btSerial.print(" % ");
  btSerial.print(", 온도: ");
  btSerial.print(temp);
  btSerial.print(" 도");

  if(humi > 70 || temp > 25) digitalWrite(13, HIGH);
  else digitalWrite(13, LOW);

  if(btSerial.available()) {
    char btData = btSerial.read();

    if(btData == 'n') {
      digitalWrite(13, HIGH);
    }
    else if(btData == 'f') {
      digitalWrite(13, LOW);
    }
  }
  
  delay(2000);
}
