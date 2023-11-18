#include <LCD_I2C.h>

LCD_I2C lcd(0x3F, 16, 2);

void setup() {
  for(int i=3; i<=12; i++){
    pinMode(i, OUTPUT);
  }
    pinMode(A0, INPUT);

     lcd.begin();
     lcd.backlight();

}
boolean start = true;
int val = 0;
int procent = 0;

void loop() {
  if(start){
  for(int i=3; i<=12; i++){
    digitalWrite(i, HIGH);
    delay(100);
    digitalWrite(i, LOW);
  }
  start = false;
  }
  lcd.print("           ");
  val = (analogRead(A0)*(9/1015.00))+3;
  procent = (analogRead(A0)*(100/1015.00));
  
  digitalWrite(val, HIGH);
  for(int i=val+1; i<=12; i++){
    digitalWrite(i, LOW);
  }
  lcd.setCursor(0,0);
  lcd.print(procent);
  lcd.print(" %");
  delay(15);
}
