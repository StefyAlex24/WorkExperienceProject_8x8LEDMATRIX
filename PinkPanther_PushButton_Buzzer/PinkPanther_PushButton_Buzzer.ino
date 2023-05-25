#include <pitches.h>  // Library imported that contains required notes, etc.
#define REST 0  // Defines REST, the library doesn't include REST

const int buzzer = 6;  // Sets buzzer to the buzzer pin
const int button = 4;  // Sets push-button to the button pin
int tempo = 120;  // Sets the speed of the music

// Notes of the melody + Note durations
// e.g 4 =  quarter note, 8 = eighteenth, -4 = dotted quarter note
int melody[] =
{

  // Pink Panther theme song

  REST,2, REST,4, REST,8, NOTE_DS4,8, 
  NOTE_E4,-4, REST,8, NOTE_FS4,8, NOTE_G4,-4, REST,8, NOTE_DS4,8,
  NOTE_E4,-8, NOTE_FS4,8,  NOTE_G4,-8, NOTE_C5,8, NOTE_B4,-8, NOTE_E4,8, NOTE_G4,-8, NOTE_B4,8,   
  NOTE_AS4,2, NOTE_A4,-16, NOTE_G4,-16, NOTE_E4,-16, NOTE_D4,-16, 
  NOTE_E4,2, REST,4, REST,8, NOTE_DS4,4,

  NOTE_E4,-4, REST,8, NOTE_FS4,8, NOTE_G4,-4, REST,8, NOTE_DS4,8,
  NOTE_E4,-8, NOTE_FS4,8,  NOTE_G4,-8, NOTE_C5,8, NOTE_B4,-8, NOTE_G4,8, NOTE_B4,-8, NOTE_E5,8,
  NOTE_DS5,1,   
  NOTE_D5,2, REST,4, REST,8, NOTE_DS4,8, 
  NOTE_E4,-4, REST,8, NOTE_FS4,8, NOTE_G4,-4, REST,8, NOTE_DS4,8,
  NOTE_E4,-8, NOTE_FS4,8,  NOTE_G4,-8, NOTE_C5,8, NOTE_B4,-8, NOTE_E4,8, NOTE_G4,-8, NOTE_B4,8,   
  
  NOTE_AS4,2, NOTE_A4,-16, NOTE_G4,-16, NOTE_E4,-16, NOTE_D4,-16, 
  NOTE_E4,-4, REST,4,
  REST,4, NOTE_E5,-8, NOTE_D5,8, NOTE_B4,-8, NOTE_A4,8, NOTE_G4,-8, NOTE_E4,-8,
  NOTE_AS4,16, NOTE_A4,-8, NOTE_AS4,16, NOTE_A4,-8, NOTE_AS4,16, NOTE_A4,-8, NOTE_AS4,16, NOTE_A4,-8,   
  NOTE_G4,-16, NOTE_E4,-16, NOTE_D4,-16, NOTE_E4,16, NOTE_E4,16, NOTE_E4,2,
};

int notes = sizeof(melody) / sizeof(melody[0]) / 2;  // sizeof() gives the number of bytes, each int has two bytes - there are two values per note therefore each note is four bytes
int wholenote = (60000 * 4) / tempo;  // Calculates the duration of a whole note in ms (60s / tempo)*4 beats
int divider = 0, noteDuration = 0;  // Variables

void setup()
{
  Serial.begin(9600);  // Opens Serial Communication, sets data rate to 9600 bps
  pinMode(button, INPUT_PULLUP);  // Defines button as an input
}

void loop()
{
  int buttonState = digitalRead(button);  // Reads new state of button
  if(buttonState == LOW)
  {
    Serial.println("The BUTTON has been pressed");
    buzzer1();  // Calls the buzzer1 function below
  }
}

void buzzer1()
{
  // Iterate over the notes of the melody. 
  // Remember, the array is twice the number of notes (melody notes + note durations)
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) 
  {
    divider = melody[thisNote + 1];  // Calculates the duration ofr each note
    if (divider > 0)
    {
      noteDuration = (wholenote) / divider;
    }
    else if (divider < 0)
    {
      noteDuration = (wholenote) / abs(divider);  // Dotted notes are represented with negatice duartions
      noteDuration *= 1.5;  // Increases the duration by 50% for dotted notes
    }
    tone(buzzer, melody[thisNote], noteDuration*0.9);  // Note only plays 90% of the duartion, leaving 10% as a pause
    delay(noteDuration);  // Wait for the specified duartion before playing the next note
    noTone(buzzer);  // After all notes are played tone stops
  }
}
