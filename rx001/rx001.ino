#include <RF24Network.h>
#include <RF24.h>
#include <SPI.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(10, 9, 6, 5, 4, 3);
RF24 radio(7,8);                // nRF24L01(+) radio attached using Getting Started board 

RF24Network network(radio);      // Network uses that radio
const uint16_t this_node = 00;    // Address of our node in Octal format ( 04,031, etc)
const uint16_t other_node = 01;   // Address of the other node in Octal format
float h;
float t;
struct payload_t 
{                 // Structure of our payload
  unsigned long h;
  unsigned long t;
};


void setup(void)
{
  Serial.begin(57600);
  Serial.println("RF24Network/examples/helloworld_rx/");
 
  SPI.begin();
  radio.begin();
  network.begin(/*channel*/ 91, /*node address*/ this_node);
  
}

void loop(void)
{
 
  network.update();                  // Check the network regularly

  
  while ( network.available() ) 
  {     // Is there anything ready for us?
    
    RF24NetworkHeader header;        // If so, grab it and print it out
    payload_t payload;
    network.read(header,&payload,sizeof(payload));
    Serial.print("Humidity    ");
    Serial.print(payload.h);
    Serial.print("%");
    Serial.println();
    Serial.print("Temperature ");
    Serial.print(payload.t);
    Serial.println("*c");
    Serial.println("----------");
    lcd.begin(16, 2);
    lcd.print("Humidity ");
    lcd.print(payload.h);
    lcd.print("%");
    //delay(1000);
    lcd.setCursor(0, 1);
    //lcd.begin(16, 2);
    lcd.print("Temp     ");
    lcd.print(payload.t);
    lcd.print("*c");
    delay(1000);
    
  }
}

