#include <RF24Network.h>
#include <RF24.h>
#include <SPI.h>
int s = A5;
int sVaule = 0;
int K = 0;
RF24 radio(7,8);                    // nRF24L01(+) radio attached using Getting Started board 
RF24Network network(radio);          // Network uses that radio
const uint16_t this_node = 01;        // Address of our node in Octal format
const uint16_t gateway_node = 00;       // Address of the other node in Octal format
unsigned long last_sent;             // When did we last send?
unsigned long packets_sent;          // How many have we sent already
struct payload_t 
{                  // Structure of our payload
  unsigned int s;
};
void setup() 
{
  Serial.begin(9600);

}

void loop() 
{
  sVaule = analogRead(s);
  K = sVaule/10;
  if(K<10)
  {
    Serial.println("FAIL");
  }
  else
  {
  Serial.println(K);
  }
}
