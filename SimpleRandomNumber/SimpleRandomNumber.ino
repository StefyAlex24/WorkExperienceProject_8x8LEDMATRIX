// Simple Random number 1 to 19
// Random number from 1 to 19 displayed in serial monitor only once
//
//                                               Stefan Alexandru, May 26th 2023
//

long randNumber;  //  Defines variable as long number (-2,147,483,648 to 2,147,483,647)

void setup() 
{
  Serial.begin(9600);  //  Opens Serial Communication, sets data rate to 9600 bps 
  //  Defines where seed for ran.num.gen is picked up from
  //  Generates different seed numbers each time sketch runs
  //  Since pin is floating value that will seed the ran.num.gen will never be the same therefore making it truly random
  randomSeed(analogRead(0));

  randNumber = random(1, 20);  // Generates a random number from 1 to 19
  Serial.println(randNumber);
}

void loop() 
{

}
