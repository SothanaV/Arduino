#include <LiquidCrystal.h>          //ประกาศLibrary
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT22   // initialize the library with the numbers of the interface pins
LiquidCrystal lcd(10, 9, 6, 5, 4, 3);  //ฟังก์ชั่นแรกกำหนดPins ที่ใช้ในการเชื่อมต่อ
DHT dht(DHTPIN, DHTTYPE);
void loop()
{
  /////DHT11/////
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(t) || isnan(h)) 
  {
    Serial.println("Failed to read from DHT");
  } 
  else 
  {
    Serial.print("Humidity: "); 
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("Temperature: "); 
    Serial.print(t);
    Serial.println(" *C");
  }
                                                                     // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);                                                 //กำหนดขนาดของจอ columns และ rows
                                                                    // Print a message to the LCD.
  lcd.print("Humidity ");
  lcd.print(h);    //กำหนดข้อความที่ต้องการแสดงผล
  lcd.print("%");
  lcd.setCursor(0, 1);
  lcd.print("Temp     ");
  lcd.print(t);//กำหนดตำแหน่ง Cursor
  lcd.print("*c");
  delay(1000);//กำหนดข้อความที่ต้องการแสดงผล
}
void setup()
{
 
}

