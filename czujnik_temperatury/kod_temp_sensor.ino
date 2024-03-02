#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6,7);

void setup() {
  // put your setup code here, to run once:
lcd.begin(16, 2);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("TEMPERATURA:");
}

int odczyt;
float voltage;
float temperaturaC;

void loop() {
  // put your main code here, to run repeatedly:
int odczyt = analogRead(A0);

float voltage = odczyt * (5.0/1024.0);

float temperaturaC = voltage * 100;
lcd.setCursor(0,1);
lcd.print(temperaturaC);
lcd.print(" ");
lcd.print("C");
delay(1000);
}
