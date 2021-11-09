#include <LiquidCrystal.h>
#include<DHT.h>
LiquidCrystal lcd (2, 3, 4, 5, 6, 7);
int  trigpin = 8;
int echopin = 9;
DHT dht(10, DHT11);
float duration;
float distance;
float distance_inch;

void setup()
{
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  dht.begin();
}

void loop() {
  digitalWrite(8, LOW);
  delay(100);
  digitalWrite(8, HIGH);
  delay(100);
  digitalWrite(8, LOW);
  duration = pulseIn(9, HIGH);
  distance = 0.034 * duration / 2.0;
  distance_inch = distance * 0.393701;
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.print(distance);
  lcd.print(" cm");
  lcd.setCursor(0, 1);
  lcd.print("Distance: ");
  lcd.print(distance_inch);
  lcd.print(" inch");
  Serial.println("Distance: " + String(distance) + " cm");
  Serial.println("Distance: " + String(distance_inch) + " inch");
  delay(1000);
  lcd.clear();
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  lcd.setCursor(0, 0);
  lcd.print("Temp");
  lcd.print(t);
  lcd.print(" *C");
  lcd.setCursor(0, 1);
  lcd.print("Humidity");
  lcd.print(h);
  lcd.print(" %");
  Serial.println("Temperature: " + String(t) + " *C");
  Serial.println("Humidity: " + String(h) + " %");
  Serial.println();
  delay(1000);
  lcd.clear();
  }
