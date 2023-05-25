//
//  Push-Button activated Buzzer that outputs 'help' in Morse Code
//
//                                                   Stefan Alexandru, May 25th 2023
//

const int buzzer = 6;  // Sets buzzer to the buzzer pin
const int button = 4; // Sets button to the button pin
int note = 1000;  // Sets the pitch for the buzzer tone
int timeUnit = 100; // Variable used to measure time for dots, dashes, breaks and pauses

void setup() 
{
  Serial.begin(9600);  // Opens Serial Communication, sets data rate to 9600 bps
  pinMode(buzzer, OUTPUT);  // Defines buzzer as an output
  pinMode(button, INPUT_PULLUP);  // Defines button as an input
}

void loop() 
{
  int buttonState = digitalRead(button);  // Reads new state of button

  if (buttonState == LOW)
  {
    Serial.println("The BUTTON has been pressed");
    help();  // Calls the help function below
  }
}


// Letter functions
void lA () {dot();dash();letterPause();}  //letter A in morse code
void lB () {dash();dot();dot();dot();letterPause();}
void lC () {dash();dot();dash();dot();letterPause();}
void lD () {dash();dot();dot();letterPause();}
void lE () {dot();letterPause();}
void lF () {dot();dot();dash();dot();letterPause();}
void lG () {dash();dash();dot();letterPause();}
void lH () {dot();dot();dot();dot();letterPause();}
void lI () {dot();dot();letterPause();}
void lJ () {dot();dash();dash();dash();letterPause();}
void lK () {dash();dot();dash();letterPause();}
void lL () {dot();dash();dot();dot();letterPause();}
void lM () {dash();dash();letterPause();}
void lN () {dash();dot();letterPause();}
void lO () {dash();dash();dash();letterPause();}
void lP () {dot();dash();dash();dot();letterPause();}
void lQ () {dash();dash();dot();dash();letterPause();}
void lR () {dot();dash();dot();letterPause();}
void lS () {dot();dot();dot();letterPause();}
void lT () {dash();letterPause();}
void lU () {dot();dot();dash();letterPause();}
void lV () {dot();dot();dot();dash();letterPause();}
void lW () {dot();dash();dash();letterPause();}
void lX () {dash();dot();dot();dash();letterPause();}
void lY () {dash();dot();dash();dash();letterPause();}
void lZ () {dash();dash();dot();dot();letterPause();}

void dot() // Emit sound for 100 milliseconds
{
  tone(buzzer, note, timeUnit);
  delay(timeUnit*2);
}

void dash() // Emit sound for 300 milliseconds
{
  tone(buzzer, note, timeUnit*3);
  delay(timeUnit*4);
}

void letterPause() // Delay between letters for 300 milliseconds
{
  delay(timeUnit*3);
}

void wordPause()  // Delay between words for 700 milliseconds
{
  delay(timeUnit*7);
}

void help() // Help in morse code using functions above for each character
{
  lH(); lE (); lL (); lP ();
}
