float temp;
//int tempPin = A1;
void setup()
{
  Serial.begin(9600);
 
}
void loop()
{
  temp = analogRead(tempPin);
  temp = temp*0.33;
  Serial.print("Temperature is ");
  Serial.print(temp);
  Serial.print("*c");
  Serial.println();
  delay(1000);
}

