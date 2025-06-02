#include <Wire.h>
#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

const float Rs = 1.0;

void setup() {
  lcd.begin(16, 2);
  lcd.setBacklight(1);
  lcd.setCursor(0, 0);
  lcd.print("Resistance:");
}

void loop() {
  float vJunction = analogRead(A0) * (5.0 / 1023.0);
  float vRx = vJunction;
  float vRs = 5.0 - vJunction;

  float current = vRs / Rs;
  float Rx = (current > 0) ? vRx / current : 0;

  lcd.setCursor(0, 1);
  lcd.print("Rx: ");
  lcd.print(Rx, 4);
  lcd.print(" Ohms   ");

  delay(1000);
}

