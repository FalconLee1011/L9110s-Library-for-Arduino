#include <L9110s.h>

L9110s car;

void setup() {

}

void loop() {
  car.forward(255);
  delay(500);
  car.STOP();
  delay(150);
  car.backward(255);
  delay(500);
  car.STOP();
  delay(150);
}
