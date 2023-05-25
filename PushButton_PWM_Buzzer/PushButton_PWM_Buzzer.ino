//
//  Push-Button activated Buzzer using PWM (Square Waves)
//
//                                                  Stefan Alexandru, May 23rd 2023
//

const int buzzer = 6;  // Sets buzzer to the buzzer pin
const int button = 4;  // Sets push-button to the button pin

void setup() 
{
  Serial.begin(9600);  // Opens Serial Communication, sets data rate to 9600 bps
  pinMode(buzzer, OUTPUT);  // Defines buzzer as an output
  pinMode(button, INPUT_PULLUP);  // Defines button as an input
}

void loop()
{
  buzzer1();  // Calls the buzzer1 function below
}

void buzzer1()  // Defines the buzzer1 function
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
