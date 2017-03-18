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
void randomRun(){
  //observe direction and act accordingly
  long distance = hcsr->getDistance();
  if (distance <= 20L) {
    engine->drive(false, GEAR_ONE, 1000);
    if(random(0,2)==0){
      engine->uTurnLeft();
    }
    else{
      engine->uTurnRight();
    }
  }
  else {
    // agg->drive(true, GEAR_THREE);
    if(distance <= 85L){
      //Begin driving clear curve
      if(random(0,2)==0){
        engine->turn(true, 100, 0, GEAR_TWO, 1000);
      }
      else{
        engine->turn(true, 0, 100, GEAR_TWO, 1000);
      }
    }
    else if(distance >= 127L){
      engine->drive(true, GEAR_THREE, 1000);

    }
    else{
      engine->drive(true, distance*2, 1000);
    }
  }
}

