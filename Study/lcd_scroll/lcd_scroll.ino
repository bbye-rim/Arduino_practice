#include <LiquidCrystal.h>

LiquidCrystal lcd(3, 4, 10, 11, 12, 13);

void setup() {
  lcd.begin(16,2); //lcd 시작 : 한줄에 16개의 문자로 2줄 입력
  lcd.clear(); //내용 초기화
  lcd.setCursor(0, 0); //(0, 0)으로 커서 이동
  lcd.print("My name is Baek Yerim"); //글자 출력
  lcd.setCursor(0, 1); //(0, 1)로 커서 이동
  lcd.print("YOU DID IT!!"); //글자 출력
}

void loop() {
  //왼쪽으로 스크롤
  for(int position=0; position<8; position++) {
    lcd.scrollDisplayLeft();
    delay(150);
  }
  delay(2000);
  
  //오른쪽으로 스크롤
  for(int position=0; position<8; position++) {
    lcd.scrollDisplayRight();
    delay(150);
  }
  delay(2000);
}
