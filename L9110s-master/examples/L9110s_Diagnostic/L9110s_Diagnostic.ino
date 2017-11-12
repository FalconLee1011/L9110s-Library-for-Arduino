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
