/*
  L9110s / L298n Library
  Call L9110s before calling other functions

  V1.0 Oct.5.2017 by FalconXCLi
*/

#include "Arduino.h"
#include "L9110s.h"

L9110s::L9110s(){
  pinMode(XIX, OUTPUT);
  pinMode(YIY, OUTPUT);
}

void L9110s::motor(int Mot_N, int cmd, int speed){

  switch(Mot_N){
    case 1: //select motor A
      XIX = 9;
      YIY = 5;
      break;
    case 2: //select motor B
      XIX = 10;
      YIY = 6;
      break;
    default:
      break;
  }

  switch(cmd){
    case 1:
      analogWrite(XIX, speed);
      analogWrite(YIY, 0);
      break;
    case 2:
      analogWrite(XIX, 0);
      analogWrite(YIY, speed);
      break;
    case 3: //stop
      analogWrite(XIX, 0);
      analogWrite(YIY, 0);
      break;
    default:
      break;
  }
}

void L9110s::forward(int spd){
  motor(1, 1, spd);
  motor(2, 2, spd);
}

void L9110s::backward(int spd){
  motor(1, 2, spd);
  motor(2, 1, spd);
}

void L9110s::right(int spd){
  motor(1, 1, spd);
  motor(2, 1, spd);
}
void L9110s::left(int spd){
  motor(1, 2, spd);
  motor(2, 2, spd);
}

void L9110s::STOP(){
  motor(1, 3, 0);
  motor(2, 3, 0);
}
