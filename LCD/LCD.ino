// implementacja biblioteki LiguidCrystal do obsługi LCD:
#include <LiquidCrystal.h>

// deklaracja portów zarządzania wyświetlaczem LCD: 
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);
lcd.setCursor(0, 0);
lcd.print("Arduino - LCD");
lcd.setCursor(0,1);
lcd.print("Mati :)");
//lcd.cursor();
lcd.blink();
}

void loop() {
  // put your main code here, to run repeatedly:
//lcd.noCursor();
//lcd.cursor();
//delay(250);
lcd.noDisplay();
delay(500);
lcd.display();
delay(500);
}
