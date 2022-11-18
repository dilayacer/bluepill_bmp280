/*
Altitude sickness, the mildest form being acute mountain sickness (AMS), is the harmful effect of high altitude, 
caused by rapid exposure to low amounts of oxygen at high elevation. Altitude sickness typically occurs only above 
2,500 metres (8,000 ft), though some are affected at lower altitudes [1].

Reference
[1] Altitude sickness, https://en.wikipedia.org/wiki/Altitude_sickness
*/

#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>            
#include <Adafruit_GFX.h>
#include <Adafruit_BMP280.h>
#include <Adafruit_PCD8544.h>

#define BMP280_I2C_ADDRESS  0x76
Adafruit_BMP280 bmp;

char text[12];

Adafruit_PCD8544 display = Adafruit_PCD8544(PB3, PB5, PB10, PA15, PB11);

void setup() {
  
  bmp.begin(BMP280_I2C_ADDRESS);
  display.clearDisplay();
  display.begin();
  display.setTextSize(1);
  display.setTextColor(BLACK, WHITE);
  display.setCursor(3, 0);
  display.print("M.A.S"); //Mountaineer Alarm System
  display.display();
  
  bmp.setSampling(Adafruit_BMP280 :: MODE_NORMAL, 
                  Adafruit_BMP280 :: SAMPLING_X2,
                  Adafruit_BMP280 :: SAMPLING_X16,
                  Adafruit_BMP280 :: FILTER_X16,
                  Adafruit_BMP280 :: STANDBY_MS_500 );

   pinMode(PA3, OUTPUT); //led
   pinMode(PB8, OUTPUT); //vib. motor
  }

void ldr(){
  int light = analogRead(PA6);
  if (light > 900) {
    digitalWrite(PA3, LOW);
  }
  if (light < 850) {
    digitalWrite(PA3, HIGH);
    delay(100);
    digitalWrite(PA3, LOW);
  }

  void vib(){
     
     digitalWrite(PB8, HIGH);
     delay(1000);
     digitalWrite(PB8, LOW);
     delay(1000);
  }
//motor ile led i sensöre bağla
}
void loop() {
  float temp = bmp.readTemperature();
  float pres = bmp.readPressure()/100;
  float alt  = bmp.readAltitude(1013.25);
  
  display.setCursor(7, 10);
  if(temp >= 0)
    display.print(' ');
  else
    display.print('-');
  sprintf(text, "%02u.%02u C", (int)abs(temp), (int)(abs(temp) * 100) % 100);
  display.print(text);
   
  display.setCursor(15, 20);
  sprintf(text, "%04u.%02u hPa", (int)pres, (int)((uint32_t)(pres * 100) % 100));
  display.print(text);
}