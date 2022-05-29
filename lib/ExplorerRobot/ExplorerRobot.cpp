#include "ExplorerRobot.h"
#include <Arduino.h>

ExplorerRobot::ExplorerRobot(int motor1A, int motor1B, int motor1V, int motor2A, int motor2B, int motor2V) {
  pinMode(motor1A, OUTPUT);
  pinMode(motor1B, OUTPUT);
  pinMode(motor1V, OUTPUT);
  pinMode(motor2A, OUTPUT);
  pinMode(motor2B, OUTPUT);
  pinMode(motor2V, OUTPUT);
  pin_Motor1A = motor1A;
  pin_Motor1B = motor1B;
  pin_Motor1V = motor1V;
  pin_Motor2A = motor2A;
  pin_Motor2B = motor2B;
  pin_Motor2V = motor2V;
}

void ExplorerRobot::go_forward(int speed_car) {
  //Motor 1
  analogWrite(pin_Motor1V, speed_car);
  digitalWrite(pin_Motor1A, HIGH);
  digitalWrite(pin_Motor1B, LOW);

  //Motor 2
  analogWrite(pin_Motor2V, speed_car);
  digitalWrite(pin_Motor2A, HIGH);
  digitalWrite(pin_Motor2B, LOW);

}

void ExplorerRobot::go_back(int speed_car) {
  //Motor 1
  analogWrite(pin_Motor1V, speed_car);
  digitalWrite(pin_Motor1A, LOW);
  digitalWrite(pin_Motor1B, HIGH);

  //Motor 2
  analogWrite(pin_Motor2V, speed_car);
  digitalWrite(pin_Motor2A, LOW);
  digitalWrite(pin_Motor2B, HIGH);
}

void ExplorerRobot::stop_car() {
  //Motor 1
  digitalWrite(pin_Motor1A, LOW);
  digitalWrite(pin_Motor1B, LOW);

  //Motor 2
  digitalWrite(pin_Motor2A, LOW);
  digitalWrite(pin_Motor2B, LOW);
}

void ExplorerRobot::turn_right_forward(int speed_car){
  //Motor 1
  analogWrite(pin_Motor1V, speed_car);
  digitalWrite(pin_Motor1A, HIGH);
  digitalWrite(pin_Motor1B, LOW);

  //Motor 2
  digitalWrite(pin_Motor2A, LOW);
  digitalWrite(pin_Motor2B, LOW);
}

void ExplorerRobot::turn_left_forward(int speed_car){
  //Motor1
  digitalWrite(pin_Motor1A, LOW);
  digitalWrite(pin_Motor1B, LOW);

  //Motor2
  analogWrite(pin_Motor2V, speed_car);
  digitalWrite(pin_Motor2A, HIGH);
  digitalWrite(pin_Motor2B, LOW);
}

void ExplorerRobot::turn_right_back(int speed_car){
  //Motor1
  analogWrite(pin_Motor1V, speed_car);
  digitalWrite(pin_Motor1A, LOW);
  digitalWrite(pin_Motor1B, HIGH);

  //Motor2
  digitalWrite(pin_Motor2A, LOW);
  digitalWrite(pin_Motor2B, LOW);
}

void ExplorerRobot::turn_left_back(int speed_car){
  //Motor1
  digitalWrite(pin_Motor1A, LOW);
  digitalWrite(pin_Motor1B, LOW);

  //Motor2
  analogWrite(pin_Motor2V, speed_car);
  digitalWrite(pin_Motor2A, LOW);
  digitalWrite(pin_Motor2B, HIGH);
}

//void control(int speed_car,String command) {
//  switch(command){
//    case "go_forward"{
//      go foward(speed_car);
//      break;
//    }
//    case "turn_right_absolute_forward"{
//      turn_right_absolute_forward(speed_car);
//      break;
//    }
//    case "turn_left_absolute_forward": turn_left_absolute_forward(speed_car);
//  }
//}
