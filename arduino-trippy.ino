/***********************************************************************************************************
 * LICENSE                                                                                                 *
 * Dieses Material steht unter der Creative-Commons-Lizenz                                                 *
 * Namensnennung - Nicht kommerziell - Keine Bearbeitungen 4.0 International.                              *
 * Um eine Kopie dieser Lizenz zu sehen, besuchen Sie http://creativecommons.org/licenses/by-nc-nd/4.0/.   *
 ***********************************************************************************************************/
//Board Pins
#define PIN_1 1
#define PIN_2 2
#define ENGINE_SPEED_PIN_LEFT 3
#define PIN_4 4
#define PIN_5 5
#define HCSR_TRIGGER 6
#define HCSR_ECHO 7
#define ENGINE_BRAKE_PIN_RIGHT 8
#define ENGINE_BRAKE_PIN_LEFT 9
#define PIN_10 10
#define ENGINE_SPEED_PIN_RIGHT 11
#define ENGINE_DIRECTION_PIN_LEFT 12
#define ENGINE_DIRECTION_PIN_RIGHT 13

//Motor Gears
#define GEAR_ONE 128
#define GEAR_TWO 190
#define GEAR_THREE 255

#include "Engine.h"
#include "Hcsr.h"


//Aggregat inklusive Motoren
Engine * engine = new Engine();

//HC_SR04 - Ultra Sonic
Hcsr * hcsr = new Hcsr();

void setup() {
  //Seed random noise
  randomSeed(analogRead(1));

  for(int i = 1; i < 10; i++){
    engine->engageBrakes(true, true, 2000/i);
    engine->engageBrakes(false, false, 1000/i);
  }
  hcsr->getDistance();
}

void loop() {
  //drive randomly and evade obstacles (mono-eyed)
    randomRun();
}












