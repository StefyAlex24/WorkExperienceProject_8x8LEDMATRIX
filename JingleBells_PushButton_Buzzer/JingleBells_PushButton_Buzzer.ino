//
//  Push-Button activated Buzzer that outputs a simple Jingle Bells song
//
//                                                  Stefan Alexandru, May 24th 2023
//

#include <pitches.h>  // Imported library that contains required notes, etc. for song

const int buzzer = 6;  // Sets buzzer to the buzzer pin
const int button2 = 4;  // Sets push-button to the button pin

// Notes in the melody:
int melody[] =
{
  NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_G5, NOTE_C5, NOTE_D5,
  NOTE_E5,
  NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5,
  NOTE_F5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_D5, NOTE_D5, NOTE_E5,
  NOTE_D5, NOTE_G5
};

// Note durations: 4 = quarter note, 8 = eighth note, etc - aka tempo: 
int noteDurations[] = 
{
  8, 8, 4,
  8, 8, 4,
  8, 8, 8, 8,
  2,
  8, 8, 8, 8,
  8, 8, 8, 16, 16,
  8, 8, 8, 8,
  4, 4
};

void setup() 
{
  Serial.begin(9600);  // Opens Serial Communication, sets data rate to 9600 bps
  pinMode(button, INPUT_PULLUP); // Defines button as an input
}

void loop() 
{
  int buttonState = digitalRead(button);  // Reads new state of button
  if (buttonState == LOW) 
  {
    Serial.println("The button has been pressed");
    buzzer1();  // Calls the buzzer1 function below
  }
}

void buzzer1()
{
  // Iterate over notes of melody
  int size = sizeof(noteDurations) / sizeof(int);
  for (int thisNote = 0; thisNote < size; thisNote++) 
  {
    // This is to calculate the note duration, take one second divided by the note type
    // e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(buzzer, melody[thisNote], noteDuration);  // Generates a square wave of the specified frequency on a pin

    // To distinguish the notes, set a minimum time before playing next
    int pauseBetweenNotes = noteDuration * 1.30;  // The note's duration + 30%
    delay(pauseBetweenNotes);  // Delays the next note by however much pauseBetweenNotes is
    noTone(buzzer);  // After all notes are played tone stops
  }
}
