#include <LiquidCrystal_I2C.h>

#define NTC 12

LiquidCrystal_I2C LCD = LiquidCrystal_I2C(0x27, 16, 2);

const float BETA = 3950;

void setup() {
  pinMode(NTC, INPUT);

  LCD.init();
  LCD.backlight();
  LCD.setCursor(0, 0);
  LCD.print("Temp = ");

  Serial.begin(9600);
}

void loop() {
  int temperatura = analogRead(NTC);
  float celsius = 1 / (log(1 / (4095. / temperatura - 1)) / BETA + 1.0 / 298.15) - 273.15;

  LCD.setCursor(7, 0);
  LCD.print(celsius);
  LCD.print(" C");

  Serial.print("Temperatura: ");
  Serial.print(celsius);
  Serial.println(" ℃");

  delay(1000);
}
