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
#include </home/osvaldo/Desarrollo/GitHub/wateringplants-bot/wateringplants-bot/Code/sketch_may05a/pitches.h>
///////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////
//CONSTANTES
const int redLed   = 13;
const int redGreen = 12;
const int redBlue  = 11;
const int buzzer   = 10;
const int lightSen = A0;
const int humiditySen1 = A1;
const int humiditySen2 = A2;
const int humiditySen3 = A3;
const int humiditySen4 = A4;
const int humiditySen5 = A5;
///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
//VARIABLES
int secuence;
int humidity;
///////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////
//START STATUS
void setup() {
    Serial.begin(9600);
}
///////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////
//LOOP STATUS
void loop() {
  delay(600000);
    if ( checkHumiditySenson( humiditySen1 ) ){
      diviceStatus( 1 );
    }else{
      diviceStatus( 2 );
    }
 
  
  delay(600000);
    if ( checkHumiditySenson( humiditySen2 ) ){
      diviceStatus( 1 );
    }else{
      diviceStatus( 2 );
    }

  delay(600000);
    if ( checkHumiditySenson( humiditySen3 ) ){
      diviceStatus( 1 );
    }else{
      diviceStatus( 2 );
    }

  delay(600000);
    if ( checkHumiditySenson( humiditySen4 ) ){
      diviceStatus( 1 );
    }else{
      diviceStatus( 2 );
    }

  delay(600000);
    if ( checkHumiditySenson( humiditySen5 ) ){
      diviceStatus( 1 );
    }else{
      diviceStatus( 2 );
    }
    
}
///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////
//FUNCIONS


//
boolean checkHumiditySenson (int humiditySen){
  secuence = secuence + 1;
  humidity = analogRead(humiditySen);   //Read analog value 
  humidity = constrain(humidity,400,1023);  //Keep the ranges!
  humidity = map(humidity,400,1023,100,0);  //Map value : 400 will be 100 and 1023 will be 0
  Serial.print("Secuence: ");
  Serial.print( humiditySen );
  Serial.print( " - " );
  Serial.print( secuence );
  Serial.print("\n");
  Serial.print("Soil humidity: ");
  Serial.print(humidity);
  Serial.print("%");
  Serial.print("\n");
  if( humidity > 55 ){
    return  true;
  }else{
    return  false;
  }
}


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
    digitalWrite(redLed, LOW);
    digitalWrite(redGreen, LOW);
    digitalWrite(redBlue, HIGH);
    playAlarm();
  } else if ( code == 2 ) {
    digitalWrite(redLed, HIGH);
    digitalWrite(redGreen, LOW);
    digitalWrite(redBlue, LOW);
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
