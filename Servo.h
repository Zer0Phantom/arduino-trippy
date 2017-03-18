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
class Motor {
private:
  int pinSpeed;
  int pinBrake;
  int pinDirection;
  boolean rightEngine;

public:
  Motor(int _pinBrake, int _pinDirection, int _pinSpeed, boolean _rightEngine){
    this->pinSpeed = _pinSpeed;
    this->pinBrake = _pinBrake;
    this->pinDirection = _pinDirection;
    this->rightEngine = _rightEngine;

    //Setup MOTOR A Pins
    pinMode(this->pinBrake, OUTPUT);
    pinMode(this->pinDirection, OUTPUT);

  }

  void drive(boolean forward, int gear){
    //Forward and is right, etc...
    if(forward && this->rightEngine)digitalWrite(this->pinDirection, HIGH);
    if(!forward && this->rightEngine)digitalWrite(this->pinDirection, LOW);
    if(forward && !this->rightEngine)digitalWrite(this->pinDirection, LOW);
    if(!forward && !this->rightEngine)digitalWrite(this->pinDirection, HIGH);

    analogWrite(this->pinSpeed, gear);
    brake(false);

  }

  void brake(boolean _brake){
    if(_brake){
      digitalWrite(this->pinBrake, HIGH);
    }
    else{
      digitalWrite(this->pinBrake, LOW);
    }
  }

};


