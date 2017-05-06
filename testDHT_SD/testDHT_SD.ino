#include <SPI.h>
#include <SD.h>
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT22
File myFile; // สร้างออฟเจก File สำหรับจัดการข้อมูล
const int chipSelect = 4;
DHT dht(DHTPIN, DHTTYPE);
void setup()
{

Serial.begin(9600);
while (!Serial) 
{
; // รอจนกระทั่งเชื่อมต่อกับ Serial port แล้ว สำหรับ Arduino Leonardo เท่านั้น
}
}

void loop()
{
  


Serial.print("Initializing SD card...");
pinMode(SS, OUTPUT);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (!SD.begin(chipSelect)) 
{
  Serial.println("initialization failed!");
  return;
}
Serial.println("initialization done.");

myFile = SD.open("002.txt", FILE_WRITE); // เปิดไฟล์ที่ชื่อ test.txt เพื่อเขียนข้อมูล โหมด FILE_WRITE

// ถ้าเปิดไฟล์สำเร็จ ให้เขียนข้อมูลเพิ่มลงไป
  if (myFile) 
  {
    Serial.print("Writing to test.txt...");
    myFile.print("Humidity is"); // สั่งให้เขียนข้อมูล
    myFile.println(h);
    //myFile.println("---------");
    myFile.print("Temperature is");
    myFile.println(t);
    //myFile.println("---------");
    
    //myFile.close(); // ปิดไฟล์
    Serial.println("done.");
  } 
  else 
  {
        // ถ้าเปิดไฟลืไม่สำเร็จ ให้แสดง error 
     Serial.println("error opening test.txt");
  }
delay(1000);
}
