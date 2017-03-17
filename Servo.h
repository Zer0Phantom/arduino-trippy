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


