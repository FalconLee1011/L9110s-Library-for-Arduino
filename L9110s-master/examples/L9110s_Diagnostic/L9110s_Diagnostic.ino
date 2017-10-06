//L9110s_Diagnostic By FalconXCLi
#include <L9110s.h>

L9110s car; 

int XIX; //AIA = 9 AIB = 5
int YIY; //BIA = 10 BIB = 6
char input;

void setup(){
  Serial.begin(9600);
  pinMode(XIX, OUTPUT);
  pinMode(YIY, OUTPUT);
  Serial.println("L9110s_Diagnostic READY !\n");
  Serial.println("1 --> Forward, 2 --> Backward, 3 --> Left, 4 --> Right, 5 --> STOP, 6 --> Help");
}

void loop(){
  if(Serial.available() > 0){
    input = Serial.read();

    switch(input){
      case '1':
        car.forward(255);
        Serial.println("Forward");
        break;
      case '2':
        car.backward(255);
        Serial.println("Backward");
        break;
      case '3':
        car.left(255);
        Serial.println("Left");
        break;
      case '4':
        car.right(255);
        Serial.println("Right");
        break;
      case '5':
        car.STOP();
        Serial.println("Stopped");
        break;
      case '6':
        Serial.println("1 --> Forward, 2 --> Backward, 3 --> Left, 4 --> Right, 5 --> STOP, 6 --> Help");
      default:
        break;
    }
    delay(500);
  }
}

void motor(int Mot_N, int cmd, int speed){

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

void forward(int spd){
  motor(1, 1, spd);
  motor(2, 2, spd);
}

void backward(int spd){
  motor(1, 2, spd);
  motor(2, 1, spd);
}

void right(int spd){
  motor(1, 1, spd);
  motor(2, 1, spd);
}
void left(int spd){
  motor(1, 2, spd);
  motor(2, 2, spd);
}

void STOP(){
  motor(1, 3, 0);
  motor(2, 3, 0);
}
