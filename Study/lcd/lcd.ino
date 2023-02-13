#include <LiquidCrystal.h>

LiquidCrystal lcd(3, 4, 10, 11, 12, 13);
//V0 : 가변저항과 연결
//RS : 3번 핀은 가변저항에 연결하여 lcd에 나타나는 문자의 선명도 조절
//E : 4번 핀은 명령어를 실행하기 위한 시점 결정
//DB0 ~ DB7 : 데이터 또는 명령어 전송 단자
//DB0 ~ DB3까지는 생략
//DB4 ~ DB7까지 4개의 단자만 사용
//데이터 단자 모두 사용할 경우 아두이노의 디지털 핀이 부족할 수 있으므로 보통 4개 단자만 사용
//BLA와 BLK는 백라이트 사용하기 위한 단자

void setup() {
  lcd.begin(16,2); //lcd 시작 : 한줄에 16개의 문자로 2줄 입력
  lcd.clear(); //내용 초기화
  lcd.setCursor(0, 0); //(0, 0)으로 커서 이동
  lcd.print("Hello World!!"); //글자 출력
  lcd.setCursor(0, 1); //(0, 1)로 커서 이동
  lcd.print("YOU DID IT!!"); //글자 출력
}

void loop() {
  
}
