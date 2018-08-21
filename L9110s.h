/*
  L9110s / L298n Library

  V1.0 Oct.5.2017 by FalconXCLi
*/

#ifndef L9110s_H
#define  L9110s_H

#include "Arduino.h"

class L9110s{
  public:
    L9110s();
    void motor(int Mot_N, int cmd, int speed);
    void forward(int spd);
    void backward(int spd);
    void right(int spd);
    void left(int spd);
    void STOP();
  private:
    int XIX;
    int YIY;
};

#endif
