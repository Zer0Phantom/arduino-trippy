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
#include <Arduino.h>
#include "Servo.h"
#include "Movement.h"

class Engine{

private:
  Motor * motor_l = new Motor(ENGINE_BRAKE_PIN_LEFT, ENGINE_DIRECTION_PIN_LEFT, ENGINE_SPEED_PIN_LEFT, false);
  Motor *  motor_r = new Motor(ENGINE_BRAKE_PIN_RIGHT, ENGINE_DIRECTION_PIN_RIGHT, ENGINE_SPEED_PIN_RIGHT, true);
  Movement * movementArray[15];
  int moveCnt=0;

public:
  Engine(){

  }

  void drive(boolean forward, int speed_, int time) {
    turn(forward, 100, 100, speed_, time);
  }

  void engageBrakes(boolean brake_l, boolean brake_r, int time){
    motor_l->brake(brake_l);
    motor_r->brake(brake_r);
    delay(time);
  }

  void uTurnRight(){
    turn(true, 0, -1, 0, 0);
  }

  void uTurnLeft(){
    turn(true, -1, 0, 0, 0);
  }

  void turn(boolean forward, int powerLeft, int powerRight, int speed_, int time){
    if(moveCnt == 15){
      engageBrakes(true, true, 5000);
      moveCnt=0;
      for(int i = 14; i >= 0; i--){
        turn(!movementArray[i]->forward, movementArray[i]->powerLeft, movementArray[i]->powerRight, movementArray[i]->speed_, time);
      }
    }

    if(powerLeft == -1){
      motor_l->drive(false, GEAR_TWO);
      motor_r->drive(true, GEAR_TWO);
      delay(1000);
    }
    else if(powerRight == -1){
      motor_l->drive(true, GEAR_TWO);
      motor_r->drive(false, GEAR_TWO);
      delay(1000);
    } 
    else{
      motor_l->drive(forward, (speed_*powerLeft)/100);
      motor_r->drive(forward, (speed_*powerRight)/100);
      delay(time);
    }
    movementArray[moveCnt]=new Movement(forward, powerLeft, powerRight, speed_, time);
    moveCnt++;
  }
};










