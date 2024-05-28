
#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd_1(0);

int TempSensore = A0;
int UmiditaAriaSensore = A1;
int UmiditaTerraSensore = A2;
int LuceSensore = A3;

int PompaAccesa = 2;
int PompaSpenta = 3;

int AriaAccesa = 13;
int AriaSpenta = 12;

void setup() {

Serial.begin(9600);
pinMode(PompaAccesa, OUTPUT);
pinMode(PompaSpenta, OUTPUT);

pinMode(AriaAccesa, OUTPUT);
pinMode(AriaSpenta, OUTPUT);

  digitalWrite(PompaAccesa, LOW);
  digitalWrite(PompaSpenta, LOW);
  digitalWrite(AriaAccesa, LOW);
  digitalWrite(AriaSpenta, LOW);
  
    lcd_1.begin(16, 2);
}



void loop() {
  int Temperatura = analogRead(TempSensore);
  int UmiditaAria = analogRead(UmiditaAriaSensore);
  int UmiditaTerra = analogRead(UmiditaTerraSensore);
  int Luce = analogRead(LuceSensore);

  if(UmiditaTerra < 532)  {
      digitalWrite(PompaAccesa, LOW);
      digitalWrite(PompaSpenta, HIGH);
  }else{
      digitalWrite(PompaAccesa, HIGH);
      digitalWrite(PompaSpenta, LOW);    
  }

  if(Temperatura < 182)  {
      digitalWrite(AriaAccesa, LOW);
      digitalWrite(AriaSpenta, HIGH);
  }else{
      digitalWrite(AriaAccesa, HIGH);
      digitalWrite(AriaSpenta, LOW);    
  }


  Serial.print("Temperatura :");
  Serial.println(Temperatura);
  Serial.print("Umidità aria :");
  Serial.println(UmiditaAria);
  Serial.print("Umidità terra :");
  Serial.println(UmiditaTerra);
  Serial.print("Luce :");
  Serial.println(Luce);
  
  lcd_1.setCursor(0, 0);
  lcd_1.print("Um. Terra: ");
  lcd_1.print(UmiditaTerra);
  
  lcd_1.setCursor(0, 1);
  lcd_1.print("Temperatura: ");
  lcd_1.print(Temperatura);
  
  delay(2000);
}
