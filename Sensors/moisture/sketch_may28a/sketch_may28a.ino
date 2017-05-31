#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int soil = A0;

void setup() {
  lcd.begin(16, 2);

  Serial.begin(9600);
  lcd.setCursor(0,0);
  lcd.print("Moisture(0-1024) :   ");
}

void loop() {
  int value = analogRead(soil);

  Serial.print("read sensor value : ");
  Serial.println(value);

  int moisture_value = 1024 - value;

  lcd.setCursor(0,1);
  lcd.print(moisture_value);

  if(moisture_value < 100){
    lcd.print("    (LOW)    ");
  } else if(moisture_value < 100){
    lcd.print("    (HIGH)   ");
  }else {
    lcd.print("             ");
  }

  delay(1000);
}
