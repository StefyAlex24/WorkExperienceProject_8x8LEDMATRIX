const int buzzer = 6;   // Sets buzzer to the buzzer pin
int note = 1000;  // Sets the pitch for the buzzer tone
int timeUnit = 100;  // Variable used to measure time for dots, dashes, breaks and pauses
char input;  // Variable to which the input will be set to

void setup() 
{
 Serial.begin(9600);  // Opens Serial Communication, sets data rate to 9600 bps
}

void loop() 
{
  if (Serial.available())  // Gets the number of bytes (characters) available for reading from the serial port
  {
  input = Serial.read();   // Reads incoming serial data
  if (input == 'a' || input == 'A') {lA();} //If the input is a or A function lA() will be called
  if (input == 'b' || input == 'B') {lB();} 
  if (input == 'c' || input == 'C') {lC();}
  if (input == 'd' || input == 'D') {lD();}
  if (input == 'e' || input == 'E') {lE();}
  if (input == 'f' || input == 'F') {lF();}
  if (input == 'g' || input == 'G') {lG();}
  if (input == 'h' || input == 'H') {lH();}
  if (input == 'i' || input == 'I') {lI();}
  if (input == 'j' || input == 'J') {lJ();}
  if (input == 'k' || input == 'K') {lK();}
  if (input == 'l' || input == 'L') {lL();}
  if (input == 'm' || input == 'M') {lM();}
  if (input == 'n' || input == 'N') {lN();}
  if (input == 'o' || input == 'O') {lO();}
  if (input == 'p' || input == 'P') {lP();}
  if (input == 'q' || input == 'Q') {lQ();}
  if (input == 'r' || input == 'R') {lR();}
  if (input == 's' || input == 'S') {lS();}
  if (input == 't' || input == 'T') {lT();}
  if (input == 'u' || input == 'U') {lU();}
  if (input == 'v' || input == 'V') {lV();}
  if (input == 'w' || input == 'W') {lW();}
  if (input == 'x' || input == 'X') {lX();}
  if (input == 'y' || input == 'Y') {lY();}
  if (input == 'z' || input == 'Z') {lZ();}
  if (input == ' ') {wordPause();}
  Serial.println(input);  // Prints whatever the input variable is, in te serial monitor
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

void dot()  // Emit sound for 100 milliseconds
{
  tone(buzzer, note, timeUnit);  // Generates a square wave of the specified frequency on a pin
  delay(timeUnit*2);
}

void dash()  // Emit sound for 300 milliseconds
{
  tone(buzzer, note, timeUnit*3);
  delay(timeUnit*4);
}

void letterPause()  // Delay between letters for 300 milliseconds
{
  delay(timeUnit*3);
}

void wordPause()  // Delay between words for 700 milliseconds
{
  delay(timeUnit*7);
}
