int sw1 = 2;
int sw2 = 3;
int sw3 = 4;
int led1 = 5;
int led2 = 7;
int relay = 6;
int vsw2 = 0;
void setup() 
{
 pinMode(sw1,INPUT);
 pinMode(sw2,INPUT);
 pinMode(sw3,INPUT);
 pinMode(led1,OUTPUT);
 pinMode(led2,OUTPUT);
 pinMode(relay,OUTPUT);
 digitalWrite(led1,LOW);
 digitalWrite(led2,LOW);
 digitalWrite(relay,LOW);
}

void loop() 
{
  //vsw2 = digitalRead(sw2);
  //digitalWrite(relay,vsw2);
  if(sw1 == HIGH)
  {
    digitalWrite(led1,HIGH);
      if(sw2 == HIGH)
      {
        digitalWrite(led2,HIGH);
          if(sw3 == HIGH)
          {
            //digitalWrite(led3,HIGH);
            digitalWrite(relay,HIGH);
          }
          else
          {
            //digitalWrite(led3,LOW);
            digitalWrite(relay,LOW);
          }
      }
      else
      {
        digitalWrite(led2,LOW);
      }
  }
  else
  {
    digitalWrite(led1,LOW);
  }
}

