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



