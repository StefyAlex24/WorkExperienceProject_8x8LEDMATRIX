// 8x8 LED Matrix MAX7219 Example 01
// LED Cycle - A, B, Smiley Face and then Meh face
//
//                                                  Stefan Alexandru, May 24th 2023
//                                                 

#include <MaxMatrix.h>  // Imported library that contains required matrix and LED controller functions

int data = 12;  // Sets data to the DIN pin on MAX7219 module
int load = 10;  // Sets load to the CS pin on the MAX7219 module
int clock = 11;  // Sets clock to the CLK pin on the MAX7219 module
int maxInUse = 1;   // Variable to set how many MAX7219's you'll use

MaxMatrix m(data, load, clock, maxInUse); // Defines the module

char A[] = {4, 8, B01111110, B10001000, B10001000, B01111110,};  // How letter A is displayed on the 8x8 LED Matrix
char B[] = {4, 8, B01101100, B10010010, B10010010, B11111110,};  // How letter B is displayed on the 8x8 LED Matrix
char face01[] = {8, 8, B00111100, B01000010, B10101001, B10000101, B10000101, B10101001, B01000010, B00111100,};  // How SMILEY FACE is displayed on the 8x8 LED Matrix
char face02[] = {8, 8, B00111100, B01000010, B10101001, B10001001, B10001001, B10101001, B01000010, B00111100,};  // How MEH FACE is displayed on the 8x8 LED Matrix
char testLEDs[] = {8, 8, B11111111, B11111111, B11111111, B11111111, B11111111, B11111111, B11111111, B11111111,};  // Turns all the LEDs on - to see if they all work properly

void setup()
{
  m.init();  // Function to initialise the LED module
  m.setIntensity(15);  // Dot matrix intensity 0-15
}

void loop()
{
  m.writeSprite(2,0,A);  // m.writeSprite(x,y,sprite) so offsets 2 to the right in x-direction the prints A on the LED Matrix
  delay(750);  // Diplays image for 0.75s - delays the next operation in the loop by 0.75s
  m.clear();  // After the delay A is cleared off the screen

  m.writeSprite(2,0,B);  // m.writeSprite(x,y,sprite) so offsets 2 to the right in x-direction the prints B on the LED Matrix
  delay(750);  // Diplays image for 0.75s - delays the next operation in the loop by 0.75s
  m.clear();  // After the delay B is cleared off the screen

  m.writeSprite(0,0,face01);  // 0 offsets in x,y displays face01 
  delay(2000);  // Displays image for 2s
  m.clear();  // After 2s the image is cleared

  m.writeSprite(0,0,face02);  // 0 offsets in x,y displays face02 
  delay(2000);  // Displays image for 2s
  m.clear();  // After 2s the image is cleared
}