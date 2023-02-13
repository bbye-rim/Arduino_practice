#include <LiquidCrystal.h>
#include <swRTC.h>

LiquidCrystal lcd(4, 6, 10, 11, 12, 13);
String lcdString = "";
swRTC rtc;
int piezo = 5;
int btn = 7;
int state = 0; //알람 상태 확인
int temp = 730; //알람 울릴 시간 지정 730 == 07:30

//AM PM 구분
void Set_AMPM(int hour) {
  if (hour >= 12) {
    lcd.print("PM");
  }
  else {
    lcd.print("AM");
  }
  lcd.print(hour%12, DEC);
}

//void Set_AMPM(int hour) {
//  if (hour > 12 && hour < 24){
//    lcd.print("PM");
//    lcd.print(hour%12, DEC); //시간 출력
//  }
//  else if (hour == 12){
//    lcd.print("PM");
//    lcd.print(hour, DEC); 
//  }
//  else{
//    lcd.print("AM");
//    lcd.print(hour, DEC);
//  }
//}

//10보다 작은수 출력할 때 앞에 0 출력
void Set_lowThanTen(int time) {
  if (time < 10) {
    lcd.print("0");
    lcd.print(time%10);
  }
  else
    lcd.print(time);
}

//유효한 알람시간인지 체크하는 함수
int checkTheAlarmClock(int time) {
  if (time/100 < 24 && time%100 < 60) {
    Serial.println("Success");
    return time;
  }
  else {
    Serial.println("Failed");
    return 0;
  }
}

//알람이 울릴시간인지 체크
void checkTheAlarmTime(int alarmHour, int alarmMinute) {
  if (alarmHour == rtc.getHours() && alarmMinute == rtc.getMinutes()){
    analogWrite(piezo, 128);
  }
  if (rtc.getHours() == alarmHour + 1 || rtc.getMinutes() == alarmMinute + 1){
    state = 0;
  }
}

//setup
void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  rtc.stopRTC();
  rtc.setTime(10,30,00);
  rtc.setDate(14, 5, 2022);
  rtc.startRTC();
  pinMode(piezo, OUTPUT);
  pinMode(btn, INPUT);
  Serial.begin(9600);
}

void loop() {
  int day;
  
  lcd.setCursor(0, 0);

  //1초 단위로 갱신하며 현재시간 출력
  Set_AMPM(rtc.getHours());
  lcd.print(":");
  Set_lowThanTen(rtc.getMinutes());
  lcd.print(":");
  Set_lowThanTen(rtc.getSeconds());

  //날짜 출력
  lcd.print(" ");
  Set_lowThanTen(rtc.getMonth());
  lcd.print("-");
  Set_lowThanTen(rtc.getDay());

  //알람시간 출력
  lcd.setCursor(0, 1);
  lcd.print("Alarm ");
  lcd.print(" ");
  Set_AMPM(temp/100);
  lcd.print(":");
  Set_lowThanTen(temp%100);

  //1초마다 lcd 갱신
  lcdString = "";
  lcd.print(" ");
  delay(1000);

  //알람 울릴 시간인지 체크
  checkTheAlarmTime(temp/100, temp%100); 
  int btnState = digitalRead(btn);
  Serial.print("btnState : ");
  Serial.print(btnState);
  Serial.print(" / state : ");
  Serial.println(state); 
  if (btnState == HIGH) {
    if (state == 0) {
      state = 1;
    }
  }
  if (state == 1) {
    analogWrite(piezo, 0);
  }

  //시리얼 통신을 통해 알람시간을 입력받고 시리얼 모니터에 출력
  char theDay[4];
  int i=0;
  if (Serial.available()) {
    while(Serial.available()) {
      theDay[i] = Serial.read();
      i++;
    }
    day = atoi(theDay);
    if (day/100 >= 12) {
      Serial.print("PM");
      Serial.print((day/100)-12);
    }
    else {
      Serial.print("AM");
      Serial.print(day/100);
    }
    Serial.print(":");
    if (day%100 <10) {
      Serial.print("0");
      Serial.println(day%100);
    }
    temp = checkTheAlarmClock(day);
  }
}
