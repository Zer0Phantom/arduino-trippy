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

