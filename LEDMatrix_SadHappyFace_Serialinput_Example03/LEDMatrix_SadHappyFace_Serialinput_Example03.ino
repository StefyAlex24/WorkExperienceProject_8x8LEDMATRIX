// 8x8 LED Matrix MAX7219 Example 03
// LED Smiley_Face and LED SAD_face depending on the serial input
//
//                                               Stefan Alexandru, May 25th 2023
// 

#include <MaxMatrix.h>  // Imported library that contains required matrix and LED controller functions

char input;  // Variable to which the input will be set to

int data = 12;  // Sets data to the DIN pin on MAX7219 module
int load = 10;  // Sets load to the CS pin on the MAX7219 module
int clock = 11;  // Sets clock to the CLK pin on the MAX7219 module
int maxInUse = 1;   // Variable to set how many MAX7219's you'll use

MaxMatrix m(data, load, clock, maxInUse);  // Defines the module

char face01[] = {8, 8, B00111100, B01000010, B10101001, B10000101, B10000101, B10101001, B01000010, B00111100,}; // How SMILEY FACE is displayed on the 8x8 LED Matrix
char face02[] = {8, 8, B00111100, B01000010, B10100101, B10001001, B10001001, B10100101, B01000010, B00111100,}; // How SAD FACE is displayed on the 8x8 LED Matrix
char testLEDs[] = {8, 8, B11111111, B11111111, B11111111, B11111111, B11111111, B11111111, B11111111, B11111111,};  // Turns all the LEDs on - to see if they all work properly 

void setup()
{
  m.init();  // Function to initialise the LED module
  m.setIntensity(15);  // Dot matrix intensity 0-15
  Serial.begin(9600);  // Opens Serial Communication, sets data rate to 9600 bps
}

void loop()
{
  if (Serial.available())  // Gets the number of bytes (characters) available for reading from the serial port
  {
    input = Serial.read();  // Reads incoming serial data
    if (input == 'g' || input == 'G') {goodH();} //If the input is g or G function goodH() will be called
    if (input == 'b' || input == 'B') {badS();} //If the input is b or B function badS() will be called
    Serial.println(input);  // Prints whatever the input variable is, in the serial monitor
  }
}

void goodH()
{
  m.writeSprite(0,0,face01);  // Displays LEDs for Simley Face
  delay(3000);  // Delays next operation by 3s - meaning before image clears it is displayed for 3s 
  m.clear();  // Clears the image
}

void badS()
{
  m.writeSprite(0,0,face02);  // Displays LEDs for SAD face
  delay(3000);  // Delays next operation by 3s - meaning before image clears it is displayed for 3s 
  m.clear();  // Clears the image
}
