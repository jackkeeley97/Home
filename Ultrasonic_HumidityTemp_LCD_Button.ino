#include <dht.h>
#include <LiquidCrystal.h>
#define DHT11_PIN A0
LiquidCrystal lcd(1, 2, 4, 5, 6, 7);
dht DHT;

const int trigPin = 9;
const int echoPin = 10;
long duration;
int distanceCm, distanceInch;
const int buttonPin = 12;     // the number of the pushbutton pin
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
}

void loop() {

  buttonState = digitalRead(buttonPin); // read the state of the pushbutton value:
  
 switch (buttonState) {
    case 0:
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      duration = pulseIn(echoPin, HIGH);
      distanceCm= duration*0.034/2;
      distanceInch = duration*0.0133/2;
      lcd.setCursor(0,0); // Sets the location at which subsequent text written to the LCD will be displayed
      lcd.print("Distance: "); // Prints string "Distance" on the LCD
      lcd.print(distanceCm); // Prints the distance value from the sensor
      lcd.print(" cm");
      delay(10);
      lcd.setCursor(0,1);
      lcd.print("Distance: ");
      lcd.print(distanceInch);
      lcd.print(" inch");
      delay(10);
      break;
    case 1:
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
      break;
      }
}
