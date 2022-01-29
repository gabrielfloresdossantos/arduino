#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init();                      // inicializa o LCD
  // imprime a msg no lcd
  lcd.backlight();
  lcd.setCursor(1, 0); // (coluna, linha)
  lcd.print("Hello, world!");
}


void loop()
{
}
