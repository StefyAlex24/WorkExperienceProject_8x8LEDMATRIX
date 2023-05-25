// 8x8 LED Matrix MAX7219 Example 02
// LED Smiley_Face and LED SAD_face depending on which button is pressed
//
//                                               Stefan Alexandru, May 25th 2023
//                                                 

#include <MaxMatrix.h>  // Imported library that contains required matrix and LED controller functions

int button1 = 3;  // Sets button1 to appropriate button pin
int button2 = 4;  // Sets button2 to appropriate button pin

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
  pinMode(button1, INPUT_PULLUP);  // Defines button as an input
  pinMode(button2, INPUT_PULLUP);  // Defines button as an input
}

void loop()
{
  int button1State = digitalRead(button1);  // Reads new state of button

  if (button1State == LOW) 
  {
    Serial.println("The HAPPY BUTTON has been pressed");
    m.writeSprite(0,0,face01);  // Displays LEDs for Simley Face
    delay(3000);  // Delays next operation by 3s - meaning before image clears it is displayed for 3s 
    m.clear();  // Clears the image
  }

  int button2State = digitalRead(button2);  // Reads new state of button
  if (button2State == LOW)
  {
    Serial.println("The SAD BUTTON has been pressed");
    m.writeSprite(0,0,face02);  // Displays LEDs for SAD face
    delay(3000);  // Delays next operation by 3s - meaning before image clears it is displayed for 3s 
    m.clear();  // Clears the image
  }
}
