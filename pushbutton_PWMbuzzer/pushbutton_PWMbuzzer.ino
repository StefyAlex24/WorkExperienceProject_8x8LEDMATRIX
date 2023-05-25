#include <MaxMatrix.h>
#include <avr/pgmspace.h>
#include <math.h>

const int buzzer = 6;  // Sets buzzer to the buzzer pin
const int button = 4;  // Sets push-button to the button pin

void setup() 
{
  Serial.begin(9600);  // Opens Serial Communication
  pinMode(buzzer, OUTPUT);  // Defines buzzer as an output
  pinMode(button, INPUT_PULLUP);  // Defines button as an input
}

void loop()
{
  buzzer1();  // Calls the buzzer1 function below
}

void buzzer1()
{
  int buttonState = digitalRead(button);  // Reads new state of button
  if (buttonState == LOW)
  {
    Serial.println("The BUTTON is being pressed");
    analogWrite(6,128);  // PWM using analogWrite(pin, dutyCycle) - turns ON
  }
  else
  {
    Serial.println("The BUTTON is not being pressed");
    analogWrite(6,0);  // PWM using analogWrite(pin, dutyCycle) - turns OFF
  }
}
