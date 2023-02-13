#include <LiquidCrystal.h>
#include <swRTC.h>

LiquidCrystal lcd(4, 6, 10, 11, 12, 13);       //RS 핀, E핀, 데이터 핀 4개
String lcdString = "";                   //객체 선언 : 출력 할 글자 저장

swRTC rtc; 

int temp;

//AM PM을 구분해 주는 함수
void Set_AMPM(int hour) {
  if(hour >=12) 
    lcd.print("PM ");
  else 
    lcd.print("AM ");

  lcd.print(hour%12, DEC);     //시간 출력
}

//10보다 작은수를 출력할때 앞에 0을 출력하게 하는 함수
void Set_lowThanTen(int time) {
  if(time < 10) {
    lcd.print("0");
    lcd.print(time%10);
  }
  else
    lcd.print(time);
}


void setup() {                   
  lcd.begin(16,2);         //LCD 크기 지정, 2줄 16칸
  lcd.clear();             //화면 초기화
  
  rtc.stopRTC();           //정지
  rtc.setDate(14, 5, 2022);  //일, 월, 년 초기화 
  rtc.setTime(13,05,30);    //시간, 분, 초 초기화
  rtc.startRTC();          //시작
  
  Serial.begin(9600);      //시리얼 포트 초기화 
  Serial.begin(9600);                    //시리얼 통신 초기화
}

void loop() {
  int day;
  lcd.setCursor(0,0);                    //커서를 0,0에 지정 

  //날짜를 LCD에 출력
  Set_lowThanTen(rtc.getYear());
  lcd.print("/");
  Set_lowThanTen(rtc.getMonth());
  lcd.print("/");
  Set_lowThanTen(rtc.getDay());   

  lcd.setCursor(0,1);
  //1초 단위로 갱신하며 현재시간을 LCD에 출력
  Set_AMPM(rtc.getHours()); 
  lcd.print(":");
  Set_lowThanTen(rtc.getMinutes());
  lcd.print(":");
  Set_lowThanTen(rtc.getSeconds());
   
  //1초마다 LCD갱신
  lcdString = "";                      //문자열 초기화
  lcd.print("               ");        //전 글씨 삭제
  delay(1000); 
}
