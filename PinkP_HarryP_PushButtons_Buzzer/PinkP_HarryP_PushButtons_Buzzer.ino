#include <pitches.h>  // Library imported that contains required notes, etc.
#define REST 0  // Defines REST, the library doesn't include REST

const int buzzer = 6;  // Sets buzzer to the buzzer pin
const int button1 = 3;  // Sets push-button1 to the appropriate button pin
const int button2 = 4;  // Sets push-button2 to the appropriate button pin

int tempoH = 144;  // Sets the speed of Harry Potter
int tempoP = 120;  // Sets the speed of Pink Panther


// Notes of the melody + Note durations
// e.g 4 =  quarter note, 8 = eighteenth, -4 = dotted quarter note
int melodyH[] = 
{

  // Harry Potter theme song

  REST, 2, NOTE_D4, 4,
  NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4,
  NOTE_G4, 2, NOTE_D5, 4,
  NOTE_C5, -2, 
  NOTE_A4, -2,
  NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4,
  NOTE_F4, 2, NOTE_GS4, 4,
  NOTE_D4, -1, 
  NOTE_D4, 4,

  NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4, //10
  NOTE_G4, 2, NOTE_D5, 4,
  NOTE_F5, 2, NOTE_E5, 4,
  NOTE_DS5, 2, NOTE_B4, 4,
  NOTE_DS5, -4, NOTE_D5, 8, NOTE_CS5, 4,
  NOTE_CS4, 2, NOTE_B4, 4,
  NOTE_G4, -1,
  NOTE_AS4, 4,
     
  NOTE_D5, 2, NOTE_AS4, 4,//18
  NOTE_D5, 2, NOTE_AS4, 4,
  NOTE_DS5, 2, NOTE_D5, 4,
  NOTE_CS5, 2, NOTE_A4, 4,
  NOTE_AS4, -4, NOTE_D5, 8, NOTE_CS5, 4,
  NOTE_CS4, 2, NOTE_D4, 4,
  NOTE_D5, -1, 
  REST,4, NOTE_AS4,4,  

  NOTE_D5, 2, NOTE_AS4, 4,//26
  NOTE_D5, 2, NOTE_AS4, 4,
  NOTE_F5, 2, NOTE_E5, 4,
  NOTE_DS5, 2, NOTE_B4, 4,
  NOTE_DS5, -4, NOTE_D5, 8, NOTE_CS5, 4,
  NOTE_CS4, 2, NOTE_AS4, 4,
  NOTE_G4, -1,  
};

// Notes of the melody + Note durations
// e.g 4 =  quarter note, 8 = eighteenth, -4 = dotted quarter note
int melodyP[] =
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

// For Harry Potter
int notesH = sizeof(melodyH) / sizeof(melodyH[0]) / 2;  // sizeof() gives the number of bytes, each int has two bytes - there are two values per note therefore each note is four bytes
int wholenoteH = (60000 * 4) / tempoH;  // Calculates the duration of a whole note in ms (60s / tempo)*4 beats
int dividerH = 0, noteDurationH = 0;  // Variables

// For Pink Panther
int notesP = sizeof(melodyP) / sizeof(melodyP[0]) / 2;
int wholenoteP = (60000 * 4) / tempoP;
int dividerP = 0, noteDurationP = 0;

void setup() 
{
  Serial.begin(9600);  // Opens Serial Communication, sets data rate to 9600 bps
  pinMode(button1, INPUT_PULLUP);  // Defines button1 as an input
  pinMode(button2, INPUT_PULLUP);  // Defines button2 as an input
}

void loop()
{
  int buttonStateH = digitalRead(button1);  // Reads new state of button1
  if (buttonStateH == LOW)
  {
    Serial.println("BUTTON 1 has been pressed");
    buzzerH(); // Calls the buzzerH function below
  }

  int buttonStateP = digitalRead(button2);  // Reads new state of button2
  if (buttonStateP == LOW)
  {
    Serial.println("BUTTON 2 has been pressed");
    buzzerP(); // Calls the buzzerP function below
  }
} 

void buzzerH()
{
  // Iterate over the notes of the melody. 
  // Remember, the array is twice the number of notes (melody notes + note durations)
  for (int thisNoteH = 0; thisNoteH < notesH * 2; thisNoteH = thisNoteH + 2) 
  {
    dividerH = melodyH[thisNoteH + 1];  // Calculates the duration ofr each note
    if (dividerH > 0)
    {
      noteDurationH = (wholenoteH) / dividerH;
    } 
    else if (dividerH < 0) 
    {
      noteDurationH = (wholenoteH) / abs(dividerH);  // Dotted notes are represented with negatice duartions
      noteDurationH *= 1.5;  // Increases the duration by 50% for dotted notes
    }
    tone(buzzer, melodyH[thisNoteH], noteDurationH*0.9);  // Note only plays 90% of the duartion, leaving 10% as a pause
    delay(noteDurationH);  // Wait for the specified duartion before playing the next note
    noTone(buzzer);  // After all notes are played tone stops
  }
}

// All comments used for buzzerH apply for buzzerP
void buzzerP()
{
  for (int thisNoteP = 0; thisNoteP < notesP * 2; thisNoteP = thisNoteP + 2) 
  {
    dividerP = melodyP[thisNoteP + 1];
    if (dividerP > 0) 
    {
      noteDurationP = (wholenoteP) / dividerP;
    } 
    else if (dividerP < 0)
    {
      noteDurationP = (wholenoteP) / abs(dividerP);
      noteDurationP *= 1.5; 
    }
    tone(buzzer, melodyP[thisNoteP], noteDurationP*0.9);
    delay(noteDurationP);
    noTone(buzzer);
  }
}
