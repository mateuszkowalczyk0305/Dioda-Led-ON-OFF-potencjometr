#include <LiquidCrystal.h>

#define trigPin 6
#define echoPin 5

// deklaracja portów LCD:
LiquidCrystal lcd (7, 8, 9, 10, 11, 12);

void setup()
{
  Serial.begin(9600);
  pinMode(4, OUTPUT); // buzzer
  pinMode(2, OUTPUT); // dioda
  pinMode(trigPin, OUTPUT); // pin (trigger -> output)
  pinMode(echoPin, INPUT); // pin (echo -> input)
}

void loop()
{
  wyswietlacz();
  zakres(10, 100); // buzzer ON -> obiekt w odleglosci <50 cm, 100 cm>
  delay(500);
}

int zmierzOdleglosc()
{
  long czas; // deklaracja zmiennej czasowej
  long dystans;  // deklaracja zmiennej wyliczającej dystans

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  czas = pulseIn(echoPin, HIGH); // odczyt czasu trwania impulsu wysokiego na echopin
  dystans = czas / 58; // 58 to wartość producenta związana z predkością dźwięku

  return dystans;
}

void zakres(int a, int b)
{
  int odleglosc = zmierzOdleglosc();

  if ((odleglosc > a) && (odleglosc < b))
  {
    digitalWrite(4, HIGH);// odpal buzzer
    digitalWrite(2, LOW); // zapal diode

  }
  else
  {
    digitalWrite(4, LOW);
  }
}

void wyswietlacz()
{
  // wyświetlenie wyniku
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("ODLEGLOSC: ");
  lcd.setCursor(0,1);
  lcd.print(zmierzOdleglosc());
  lcd.setCursor(4,1);
  lcd.print("cm");
  delay(100);
}
