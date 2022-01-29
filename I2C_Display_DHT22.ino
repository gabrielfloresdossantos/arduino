#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#define DHTPIN            2  // pino onde sera ligado o sensor



//defina o modelo do sensor que sera utilizado

//#define DHTTYPE           DHT11     // DHT 11
#define DHTTYPE           DHT22     // DHT 22 (AM2302)
//#define DHTTYPE           DHT21     // DHT 21 (AM2301)

DHT_Unified dht(DHTPIN, DHTTYPE);


LiquidCrystal_I2C lcd(0x27, 16, 2); // define o modelo do lcd

void setup()
{
  lcd.init();                      // inicializa o LCD
  dht.begin();                     // inicializa o DHT

  sensor_t sensor;
  dht.temperature().getSensor(&sensor); // chama as informações do sensor
  dht.humidity().getSensor(&sensor);


  lcd.backlight();

}


void loop()
{
  delay(500);
  sensors_event_t event;
  //temperatura
  dht.temperature().getEvent(&event);
  lcd.setCursor(0, 0); // (coluna, linha)
  lcd.print("Temp:");
  lcd.print(event.temperature);
  lcd.setCursor(10, 0); // (coluna, linha)
  lcd.print("*C");
  //humidade
  dht.humidity().getEvent(&event);
  lcd.setCursor(0, 1); // (coluna, linha)
  lcd.print("Humd:");
  lcd.print(event.relative_humidity);
  lcd.setCursor(10, 1); // (coluna, linha)
  lcd.print("%");

}
