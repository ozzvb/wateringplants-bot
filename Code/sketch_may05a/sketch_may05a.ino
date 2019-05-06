///////////////////////////////////////////////////////////////////////////
//             _           _             _         _           _       _   
//   _ _ _ ___| |_ ___ ___|_|___ ___ ___| |___ ___| |_ ___ ___| |_ ___| |_ 
//  | | | | .'|  _| -_|  _| |   | . | . | | .'|   |  _|_ -|___| . | . |  _|
//  |_____|__,|_| |___|_| |_|_|_|_  |  _|_|__,|_|_|_| |___|   |___|___|_|  
//                              |___|_|                                    
//                                                            Version 0.0.1
//  
//                            Osvaldo Venegas B. <osvaldovenegas@gmail.com>
//  
//  =======================================================================
//  
//  Copyright (C) [2019] [Osvaldo Venegas B.]
//  
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//  
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//  
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <https://www.gnu.org/licenses/>.
//  
//  =======================================================================
///////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////
//LIBRARIES
#include <pitches.h>
///////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////
//VARIABLES
const int redLed   = 13;
const int redGreen = 12;
const int redBlue  = 11;
const int buzzer   = 10;
const int lightSen = A0;
///////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////
//START STATUS
void setup() {
  diviceStatus(1);
}
///////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////
//LOOP STATUS
void loop() {

}
///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////
//FUNCIONS


//
boolean ligthStatus(){
   int analogValue = analogRead(lightSen);
  if(analogValue < 50){            
    return false;
  }
  else if(analogValue >= 50 && analogValue <= 100){
    return true;
  }
  else{
    return true;
  }
}

void diviceStatus(int code){
  
  if ( code == 3)  {
    digitalWrite(redLed, HIGH);
    digitalWrite(redGreen, LOW);
    digitalWrite(redBlue, LOW);
    playAlarm();
  } else if ( code == 2 ) {
    digitalWrite(redLed, LOW);
    digitalWrite(redGreen, LOW);
    digitalWrite(redBlue, HIGH);
    playSong();
  } else if ( code == 1 ) {  
    digitalWrite(redLed, LOW);
    digitalWrite(redGreen, HIGH);
    digitalWrite(redBlue, LOW);
    noTone(buzzer); 
  } else {
    digitalWrite(redLed, HIGH);
    digitalWrite(redGreen, HIGH);
    digitalWrite(redBlue, HIGH);
    noTone(buzzer);   
  }
}

void playSong() {
  int melody[] = { NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_F4, NOTE_E4, NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_G4, NOTE_F4, NOTE_C4, NOTE_C4, NOTE_C5, NOTE_A4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_AS4, NOTE_AS4, NOTE_A4, NOTE_F4, NOTE_G4, NOTE_F4 };
  int noteDurations[] = { 8, 8, 4, 4, 4, 2, 8, 8, 4, 4, 4, 2, 8, 8, 4, 4, 4, 4, 4, 8, 8, 4, 4, 4, 2 };
  int countTones = 25;
  for (int iTone = 0 ; iTone < countTones ; iTone++) { 
    int noteDuration = 1130/noteDurations[iTone];
    tone (buzzer, melody[iTone], noteDuration);
    int pause = noteDuration * 2;
    delay (pause);
    noTone(buzzer); 
  }
  noTone(buzzer);
}

void playAlarm() {
  int melody[] = { NOTE_C4, NOTE_C4 };
  int noteDurations[] = { 4, 4 };
  int countTones = 2;
  for (int iTone = 0 ; iTone < countTones ; iTone++) { 
    int noteDuration = 1130/noteDurations[iTone];
    tone (buzzer, melody[iTone], noteDuration);
    int pause = noteDuration * 7;
    delay (pause);
    noTone(buzzer); 
  }
  noTone(buzzer);
}
///////////////////////////////////////////////////////////////////////////
