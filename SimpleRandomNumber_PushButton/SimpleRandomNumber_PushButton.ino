//  Simple Random Number with push-button activation
//
//
//                                               Stefan Alexandru, May 26th 2023
//

int button = 4;  // Sets button to appropriate button pin
long randNumber;  //  Defines variable as long number (-2,147,483,648 to 2,147,483,647)

void setup()
{
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
  }
}

void randomNumber()  // Defines the randomNumber function
{
  randNumber = random(1, 20);  // Generates a random number from 1 to 19
  delay(1000);  // Delays next operation by 1s 
  Serial.println(randNumber);  // Prints the random number that has been generated in the serial monitor
}

