int btn1;
int btn2;
bool led;

void setup() {
// put your setup code here, to run once:
Serial.begin(9600);
pinMode(2, OUTPUT);
pinMode(3, INPUT_PULLUP);
pinMode(4, INPUT);

digitalWrite(2, LOW);
// deklaracja zmiennej led.
led = false;

}

void loop() {

// odczyt przycisków:
btn1 = digitalRead(3);
btn2 = digitalRead(4);

// jeśli btn1 naciśnięty -> led przypisz true.
if(!btn1 == HIGH)
{
  led = true;
}

// jeśli btn2 naciśnięty -> led przypisz false.
if(btn2 == HIGH)
{
  led = false;
}

// zaświeć diodę, jeśli -> led == true.
if(led)
{
  digitalWrite(2, HIGH);
}
else
{
  digitalWrite(2, LOW);
}


}
