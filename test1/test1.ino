#include <LiquidCrystal.h>
#include "DHT.h"
#include <SPI.h>
#include <SD.h>
LiquidCrystal lcd(10, 9, 6, 5, 4, 3);
#define DHTPIN 2
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
const int chipSelect = 7;
File dataFile;
void setup() 
{
  Serial.begin(9600);
  int x,y,z,w =0;
  /*// Open serial communications and wait for port to open:
  Serial.begin(9600);
  SPI.begin();
  Serial.print("Initializing SD card...");
  // make sure that the default chip select pin is set to
  // output, even if you don't use it:
  pinMode(SS, OUTPUT);
  
  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) 
  {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    while (1) ;
  }
  Serial.println("card initialized.");
  
  // Open up the file we're going to log to!
  dataFile = SD.open("data.txt", FILE_WRITE);
  if (! dataFile) 
  {
    Serial.println("error opening datalog.txt");
    // Wait forever since we cant write data
    while (1) ;
  }*/
}
 
void loop() 
{
  /////MQ2/////
  float sensor_volt2; 
  float RS_air2; //  Get the value of RS via in a clear air
  float R02;  // Get the value of R0 via in H2
  float sensorValue2;
  /////MQ5/////
  float sensor_volt5; 
  float RS_air5; //  Get the value of RS via in a clear air
  float R05;  // Get the value of R0 via in H2
  float sensorValue5;
  /////MQ9/////
  float sensor_volt9; 
  float RS_air9; //  Get the value of RS via in a clear air
  float R09;  // Get the value of R0 via in LPG
  float sensorValue9;
  /////MQ135/////
  float sensor_volt135; 
  float RS_air135; //  Get the value of RS via in a clear air
  float R135;  // Get the value of R0 via in LPG
  float sensorValue135;
  /////DHT22/////
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  /////VOLTMETER////
  int val11;
  float val2;
    ////CAL/////
  /////MQ2/////   
  
  /////CAL/////
  sensorValue2=0.0f;
  for(int q = 0 ; q < 100 ; q++)
  {
   sensorValue2 = sensorValue2 + analogRead(A1);
  }
  sensorValue2 = sensorValue2/100.0;
  sensor_volt2 = sensorValue2/1024*5.0;
  RS_air2 = (5.0-sensor_volt2)/sensor_volt2; // omit *RL
  R02 = RS_air2/9.8; // The ratio of RS/R0 is 9.8 in a clear air from Graph (Found using WebPlotDigitizer)
  /////MQ5/////
  sensorValue5=0.0f;  
    for(int p = 0 ; p < 100 ; p++)
  {
    sensorValue5 = sensorValue5 + analogRead(A2);
  }
  sensorValue5 = sensorValue5/100.0;
  sensor_volt5 = sensorValue5/1024*5.0;
  RS_air5 = (5.0-sensor_volt5)/sensor_volt5; // omit *RL
  R05 = RS_air5/6.5; // The ratio of RS/R0 is 6.5 in a clear air from Graph (Found using WebPlotDigitizer)
 /////MQ9/////
 sensorValue9=0.0f;
 for(int z = 0 ; z < 100 ; z++)
  {
    sensorValue9 = sensorValue9 + analogRead(A0);
  }
  sensorValue9 = sensorValue9/100.0;
  sensor_volt9 = sensorValue9/1024*5.0;
  RS_air9 = (5.0-sensor_volt9)/sensor_volt9; // omit *RL
  R09 = RS_air9/9.9; // The ratio of RS/R0 is 9.9 in LPG gas from Graph (Found using WebPlotDigitizer)
  /////MQ135/////
  sensorValue135=0.0f;
  for(int w = 0 ; w < 100 ; w++)
  {
    sensorValue135 = sensorValue135 + analogRead(A3);
  }
  sensorValue135 = sensorValue135/100.0;
  sensor_volt135 = sensorValue135/1024*5.0;
  RS_air135 = (5.0-sensor_volt135)/sensor_volt135; // omit *RL
  R135 = RS_air135/9.5; // The ratio of RS/R0 is 9.9 in LPG gas from Graph (Found using WebPlotDigitizer)
  /////DHT22/////
   ////non////
   /////VoltMeter/////
  float temp;
  val11=analogRead(8);
  temp=val11/6.21;
  val11=(int)temp;//
  //val2=((val11%100)/10.0);
  val2=(val11/10)-1;
   //////////////////////////////
  Serial.print("sensor_voltMQ2  ");
  Serial.println(sensor_volt2);
  Serial.print("sensor_voltMQ5  ");
  Serial.println(sensor_volt5);
  Serial.print("sensor_voltMQ9  ");
  Serial.println(sensor_volt9);
  Serial.print("sensor_voltMQ135");
  Serial.println(sensor_volt135);
  Serial.print("Humidity:    "); 
  Serial.print(h);
  Serial.println(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C");
  Serial.println(val2);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("S2:");
  lcd.print(sensor_volt2);
  lcd.print(" ");
  lcd.print("S5:");
  lcd.print(sensor_volt5);
  lcd.setCursor(0, 1);
  lcd.print("S9:");
  lcd.print(sensor_volt9);
  lcd.print(" ");
  lcd.print("S135");
  lcd.print(sensor_volt135);
  delay(1000);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Humidity ");
  lcd.print(h);    //กำหนดข้อความที่ต้องการแสดงผล
  lcd.print("%");
  lcd.setCursor(0, 1);
  lcd.print("Temp     ");
  lcd.print(t);//กำหนดตำแหน่ง Cursor
  lcd.print("*c");
  delay(1000);//กำหนดข้อความที่ต้องการแสดงผล
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("VOLT");
  lcd.print(val2);    //กำหนดข้อความที่ต้องการแสดงผล
  lcd.print("V");
  delay(1000);
  /*dataFile.print("sensor_voltMQ2  ");
  dataFile.println(sensor_volt2);
  dataFile.print("sensor_voltMQ5  ");
  dataFile.println(sensor_volt5);
  dataFile.print("sensor_voltMQ9  ");
  dataFile.println(sensor_volt9);
  dataFile.print("sensor_voltMQ135");
  dataFile.println(sensor_volt135);
  dataFile.print("Humidity:    "); 
  dataFile.print(h);
  dataFile.print(" %\t");
  dataFile.print("Temperature: ");
  dataFile.print(t);
  dataFile.println(" *C");
  dataFile.print("VOLT: ");
  dataFile.print(val2);
  dataFile.println("V");
  dataFile.flush();*/
}
