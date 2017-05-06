#include <LiquidCrystal.h>          //ประกาศLibrary
int val11;
float val2;                                    // initialize the library with the numbers of the interface pins
LiquidCrystal lcd(10, 9, 6, 5, 4, 3);  //ฟังก์ชั่นแรกกำหนดPins ที่ใช้ในการเชื่อมต่อ
void setup()
{
                                                                    // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);                                                 //กำหนดขนาดของจอ columns และ rows
                                                                   // Print a message to the LCD
}
void loop()
{
  float temp;
  val11=analogRead(1);
  temp=val11/6.234;
  val11=temp;//
  val2=(val11/10.00);
  Serial.println(val2);
  lcd.setCursor(0, 0);
  lcd.print("VOLT");                                           //กำหนดข้อความที่ต้องการแสดงผล
  lcd.setCursor(0, 1);                                              //กำหนดตำแหน่ง Cursor
  lcd.print(val2);
  lcd.print("  V");
}
