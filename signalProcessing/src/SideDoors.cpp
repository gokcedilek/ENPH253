#include "SideDoors.h"

SideDoors::SideDoors(int leftDoorServo, int rightDoorServo):
    left_door(leftDoorServo), right_door(rightDoorServo)
{
    left_door_servo.attach(left_door);
    right_door_servo.attach(right_door);
    // right_door_servo.write(20); //start with doors closed
    // left_door_servo.write(160); //start with doors closed
    // delay(200);
}
void SideDoors::leftDoorWrite(int angle){
    left_door_servo.write(180-angle);
}

void SideDoors::rightDoorWrite(int angle){
    right_door_servo.write(angle);
}

void SideDoors::doorsWrite(int angle){
    right_door_servo.write(angle);
    delay(300);
    left_door_servo.write(180-angle);
}

void SideDoors::doorsClose(){ // close left first
  left_door_servo.write(180);
  delay(200);
  right_door_servo.write(0);
}

void SideDoors::doorsTogether(){ // close left first
  right_door_servo.write(47);
  left_door_servo.write(180-55);
}

//for collecting, 110 and 150 
void SideDoors::doorsOpenT(){ // left door smaller
  right_door_servo.write(150);
  delay(300);
  left_door_servo.write(180-85);
}

void SideDoors::doorsOpenM(){ // right door smaller
  right_door_servo.write(85);
  delay(300);
  left_door_servo.write(180-150);
}

int SideDoors::getLeftAngle(){
    return left_door_servo.read();
}

int SideDoors::getRightAngle(){
    return right_door_servo.read();
}