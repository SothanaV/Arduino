#include "DHT.h"
#include <RF24Network.h>
#include <RF24.h>
#include <SPI.h>
#include <LiquidCrystal.h>
#define DHTPIN 2
#define DHTTYPE DHT11
int TempSensor = A3;
float Temp = 0;
int Sensor = A2;
float SensorValue = 0;
//int Vcc = 2;

RF24 radio(7,8);                    // nRF24L01(+) radio attached using Getting Started board 

RF24Network network(radio);          // Network uses that radio

const uint16_t this_node = 01;        // Address of our node in Octal format
const uint16_t other_node = 00;       // Address of the other node in Octal format

const unsigned long interval = 1; //ms  // How often to send 'hello world to the other unit

unsigned long last_sent;             // When did we last send?
unsigned long packets_sent;          // How many have we sent already


struct payload_t 
{                  // Structure of our payload
  unsigned long SensorValue;
  unsigned long Temp;
  unsigned long t;
  unsigned long h;
};
LiquidCrystal lcd(12, 11, 4, 5, 6, 7);  //ฟังก์ชั่นแรกกำหนดPins ที่ใช้ในการเชื่อมต่อ //LCD
DHT dht(DHTPIN, DHTTYPE);
void setup(void)
{
  //////nRF24//////
  Serial.begin(57600);
  Serial.println("RF24Network/examples/helloworld_tx/");
 
  SPI.begin();
  radio.begin();
  network.begin(/*channel*/ 91, /*node address*/ this_node);
  //pinMode(Vcc,OUTPUT);
  ///////LCD/////////
  lcd.begin(16, 2);                                                 //กำหนดขนาดของจอ columns และ rows
                                                                    // Print a message to the LCD.
  lcd.print("Hello !!!");                                           //กำหนดข้อความที่ต้องการแสดงผล
  lcd.setCursor(0, 1);                                              //กำหนดตำแหน่ง Cursor
  lcd.print("Sothana_V");                                           //กำหนดข้อความที่ต้องการแสดงผล
  //////////DHT11////////
  dht.begin();
}

void loop() 
{
  /////DHT11/////
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  int x = 100;
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
  /////LM35/////
  //Temp = analogRead(TempSensor);
  //SensorValue = analogRead(Sensor);
  //Temp = Temp*0.315;
  network.update();// Check the network regularly
  //digitalWrite(Vcc,HIGH);
  
  unsigned long now = millis();              // If it's time to send a message, send it!
  if ( now - last_sent >= interval  )
  {
    last_sent = now;
    Serial.print("Sending...");
    Serial.print(Temp);
    Serial.print(x);
    Serial.println();
    //Serial.print("..........");
    //Serial.print(SensorValue);
    payload_t payload = {x};
    RF24NetworkHeader header(/*to node*/ other_node);
    bool ok = network.write(header,&payload,sizeof(payload));
    if (ok)
      Serial.print("ok.");
    else
      Serial.println("failed.");
  }
}


