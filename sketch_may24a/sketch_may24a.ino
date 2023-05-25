#include <MaxMatrix.h>
#include <avr/pgmspace.h>
#include <math.h>

const int buzzer = 6;
const int button2 = 4;

void setup() 
{
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(button2, INPUT_PULLUP);
}

void loop()
{
  int buttonState = digitalRead(button2);

  if (buttonState == LOW) 
  {
    Serial.println("The button is being pressed");
    analogWrite(6,128);
  }
  else 
  {
    Serial.println("The button is not being pressed");
    analogWrite(6,0);
  }
}
