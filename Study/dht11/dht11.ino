#include <DHT.h>

// 온습도 센서는 아날로그 핀에서도 가능
//DHT dht(A0, DHT11);
DHT dht(9, DHT11);

void setup() {
  Serial.begin(9600);
  dht.begin(); // 제조사에서 요구하는 사용 함수
}

void loop() {
  delay(3000);
  int dht_temp = dht.readTemperature();
  int dht_hum = dht.readHumidity();
  Serial.print("온도 : ");
  Serial.print(dht_temp);
  Serial.print("C     ");
  Serial.print("습도 : ");
  Serial.print(dht_hum);
  Serial.println("%");
}
