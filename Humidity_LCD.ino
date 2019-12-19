#include <dht.h>
#include <LiquidCrystal.h>
#define DHT11_PIN A0
LiquidCrystal lcd(1, 2, 4, 5, 6, 7);
dht DHT;

void setup(){
  lcd.begin(16, 2);
}

void loop()
{
  int readData = DHT.read11(DHT11_PIN);
  float t = DHT.temperature;
  float h = DHT.humidity;
  lcd.setCursor(0,0); 
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(h);
  lcd.print("%");
  delay(2000);
}

