// Random Generated Virtual Dice displayed on 8x8 LED Matrix activated by push-button
// 
//
//                                               Stefan Alexandru, May 26th 2023
//

#include <MaxMatrix.h>  // Imported library that contains required matrix and LED controller functions

int button = 4;  // Sets button to appropriate button pin
long randNumber;  //  Defines variable as long number (-2,147,483,648 to 2,147,483,647)

int data = 12;  // Sets data to the DIN pin on MAX7219 module
int load = 10;  // Sets load to the CS pin on the MAX7219 module
int clock = 11;  // Sets clock to the CLK pin on the MAX7219 module
int maxInUse = 1;   // Variable to set how many MAX7219's you'll use

MaxMatrix m(data, load, clock, maxInUse);  // Defines the module

char one[] = {2, 8, B00011000, B00011000,};  // How dice NO. one is displayed on the 8x8 LED Matrix
char two[] = {6, 8, B00011000, B00011000, B00000000, B00000000, B00011000, B00011000};  // How dice NO. two is displayed on the 8x8 LED Matrix
char three[] = {6, 8, B00000110, B00000110, B01100000, B01100000, B00000110, B00000110,};  // How dice NO. three is displayed on the 8x8 LED Matrix
char four[] = {6, 8, B01100110, B01100110, B00000000, B00000000, B01100110, B01100110,};  // How dice NO. four is displayed on the 8x8 LED Matrix
char five[] = {6, 8, B01100110, B01100110, B00011000, B00011000, B01100110, B01100110,};  // How dice NO. five is displayed on the 8x8 LED Matrix
char six[] = {6, 8, B11011011, B11011011, B00000000, B00000000, B11011011, B11011011,};  // How dice NO. six is displayed on the 8x8 LED Matrix
char test[] = {8, 8, B11111111, B11111111, B11111111, B11111111, B11111111, B11111111, B11111111, B11111111,};  // Turns all the LEDs on - to see if they all work properly

void setup()
{
  m.init();  // Function to initialise the LED module
  m.setIntensity(15);  // Dot matrix light intensity 0-15
  Serial.begin(9600);  // Opens Serial Communication, sets data rate to 9600 bps
  pinMode(button, INPUT_PULLUP);  // Defines button as an input

  //  Defines where seed for ran.num.gen is picked up from
  //  Generates different seed numbers each time sketch runs
  //  Since pin is floating value that will seed the ran.num.gen will never be the same thus making it truly random
  randomSeed(analogRead(0));
}

void loop()
{
  int buttonState = digitalRead(button);  // Reads new state of button
  if (buttonState == LOW)
  {
    Serial.println("The BUTTON has been pressed");
    randomNumber();  // Calls the randomNumber function below
    whatNumber();  // Calls the whatNumber function below
  }
}

void randomNumber()  // Defines the randomNumber function - random number generator
{
  randNumber = random(1, 7);  // Generates a random number from 1 to 7
  delay(100);  // Delays next operation by 0.1s 
  Serial.println(randNumber);  // Prints the random number that has been generated in the serial monitor
}

void whatNumber()  //  Defines the whatNumber function - what happens depending on the number generated
{
  if (randNumber == 1)  // When the random number generated is 1 then:
  {
    m.writeSprite(3,0,one);  // Displays the dice NO. one on LED display
    delay(3000);  // Delays next operation by 3s - meaning before image clears it is displayed for 3s
    m.clear();  // Clears the image
  }
  if (randNumber == 2)
  {
    m.writeSprite(1,0,two);
    delay(3000);
    m.clear();
  }
  if (randNumber == 3)
  {
    m.writeSprite(1,0,three);
    delay(3000);
    m.clear();
  }
  if (randNumber == 4)
  {
    m.writeSprite(1,0,four);
    delay(3000);
    m.clear();
  }
  if (randNumber == 5)
  {
    m.writeSprite(1,0,five);
    delay(3000);
    m.clear();
  }
  if (randNumber == 6)
  {
    m.writeSprite(1,0,six);
    delay(3000);
    m.clear();
  }
}
