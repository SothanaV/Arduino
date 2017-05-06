/*
ขา - ต่อกับ กราวน์
ขา + ต่อกับไฟ 5 หรือ 3.3 โวลต์
ขา S ต่อกับขา A1
ขา Vcc ต่อกับไฟที่ต้องการวัด
- ถ้าบอร์ด arduino ใช้ไฟเลี้ยง 3.3V ไฟที่วัดได้สูงสุดคือ 16.5V 
- ถ้าบอร์ด arduino ใช้ไฟเลี้ยง 5V ไฟที่วัดได้สูงสุดคือ 24.9V
*/
int val11;
float val2;

void setup()
{
Serial.begin(9600);
}
void loop()
{
float temp;
val11=analogRead(1);
temp=val11/6.2;
val11=(int)temp;//
val2=((val11%100)/10.0);
Serial.println(val2);
delay(1000);
}
