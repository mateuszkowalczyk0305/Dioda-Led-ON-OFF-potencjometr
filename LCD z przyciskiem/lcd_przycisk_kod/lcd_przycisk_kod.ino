#include <LiquidCrystal.h>

LiquidCrystal lcd (2, 3, 4, 5, 6, 7);

void setup() {
  // put your setup code here, to run once:
pinMode(10, INPUT_PULLUP);
pinMode(11, INPUT_PULLUP);
lcd.begin (16,2);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("WYBIERZ PARAMETR");
}

int btnYes;
int btnNo;
int odczytTemp;
float tempVoltage;
float tempKoncowa;

void loop() {
  // put your main code here, to run repeatedly:
btnYes = digitalRead(10);
btnNo = digitalRead(11);

lcd.setCursor(0, 1);
lcd.print("TEMP.");

lcd.setCursor(7, 1);
lcd.print("?????");


if (!btnYes == HIGH)
{
int odczytTemp = analogRead(A0);
float tempVoltage = odczytTemp * (5.0/1024.0);
float tempKoncowa = tempVoltage * 100;
// wyświetl temperature:
lcd.clear();
lcd.setCursor(0,0);
lcd.print("TEMPERATURA:");
lcd.setCursor(0,1);
lcd.print(tempKoncowa);
delay(300);
}
}

