#include <LiquidCrystal.h>          //ประกาศLibrary
                                    // initialize the library with the numbers of the interface pins
LiquidCrystal lcd(10, 9, 6, 5, 4, 3);  //ฟังก์ชั่นแรกกำหนดPins ที่ใช้ในการเชื่อมต่อ
void setup()
{
                                                                    // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);                                                 //กำหนดขนาดของจอ columns และ rows
                                                                    // Print a message to the LCD.
  lcd.print("HELLO!!!");                                           //กำหนดข้อความที่ต้องการแสดงผล
  lcd.setCursor(0, 1);                                              //กำหนดตำแหน่ง Cursor
  lcd.print("Sothana Naii");                                           //กำหนดข้อความที่ต้องการแสดงผล
}
void loop()
{
}
