#include <LiquidCrystal.h>

// deklaracja portów LCD:
LiquidCrystal lcd (2, 3, 4, 5, 6, 7);

void setup() {
Serial.begin(9600);
// przyciski:
pinMode(10, INPUT_PULLUP);
pinMode(11, INPUT_PULLUP);
// lcd start:
lcd.begin (16,2);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("WYBIERZ PARAMETR");
// diody:
pinMode(12, OUTPUT);
pinMode(13, OUTPUT);
// czujniki:
pinMode(A5, INPUT);
pinMode(A0, INPUT);
}

void loop() {
// odczyt przycisków:
int btnYes = digitalRead(10);
int btnNo = digitalRead(11);
// ekran początkowy:
lcd.setCursor(0, 1);
lcd.print("TEMP.");
lcd.setCursor(9, 1);
lcd.print("SWIATL.");
// zapal diody:
digitalWrite(12, HIGH);
digitalWrite(13, HIGH);

if (!btnYes == HIGH) // warunek przycisku zielonego.
{
// odczyt temperatury:
int odczytTemp = analogRead(A0);
float tempVoltage = odczytTemp * (5.0/1024.0);
float tempKoncowa = tempVoltage * 100;
lcd.clear();
// wyświetl temperature:
lcd.setCursor(0,0);
lcd.print("TEMPERATURA:");
lcd.setCursor(0,1);
lcd.print(tempKoncowa);
lcd.print("C");
// zgaszenie diod:
digitalWrite(12, LOW);
digitalWrite(13, LOW);
// opóźnienie:
delay(3000);
lcd.clear();
}

if (!btnNo == HIGH) // warunek przycisku czerwonego.
{
int odczytRezyst = analogRead(A5);
int NatSwiatla = map(odczytRezyst, 0, 1023, 0, 100);
lcd.clear();
// wyświetl natężenie światła:
lcd.setCursor(0,0);
lcd.print("NAT. SWIATLA:");
lcd.setCursor(0,1);
lcd.print(NatSwiatla);
lcd.print("%");
// zgaszenie diod:
digitalWrite(12, LOW);
digitalWrite(13, LOW);
// opóźnienie:
delay(3000);
lcd.clear();
}
// ekran startowy:
lcd.setCursor(0,0);
lcd.print("WYBIERZ PARAMETR");
lcd.setCursor(0, 1);
lcd.print("TEMP.");
lcd.setCursor(9, 1);
lcd.print("SWIATL.");
}

