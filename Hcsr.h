/*Copyright (C) 2017  Georg Baumann, Berlin

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
   */
#include<Arduino.h>

class Hcsr{

public:
  Hcsr(){
    pinMode(HCSR_TRIGGER, OUTPUT);
    pinMode(HCSR_ECHO, INPUT);
    digitalWrite(HCSR_TRIGGER, LOW);

  }

  long getDistance() {
    //Wait for old echo signals to be gone
    delayMicroseconds(60);

    //Trigger the 8 cycle bursts of 40kHz
    digitalWrite(HCSR_TRIGGER, HIGH);
    delayMicroseconds(10);
    digitalWrite(HCSR_TRIGGER, LOW);

    //Calculate and return distance
    return (pulseIn(HCSR_ECHO, HIGH) / 58L);
  }

};



