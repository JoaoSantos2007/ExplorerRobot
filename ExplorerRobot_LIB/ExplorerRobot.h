#ifndef ExplorerRobot_h
#define ExplorerRobot_h

#include <Arduino.h>

class ExplorerRobot
{
  public:
    ExplorerRobot(int motor1A, int motor1B, int motor1V, int motor2A, int motor2B, int motor2V);
    void go_forward(int speed_car);
    void go_back(int speed_car);
    void stop_car();
    void turn_right_forward(int speed_car);
    void turn_left_forward(int speed_car);
    void turn_right_back(int speed_car);
    void turn_left_back(int speed_car);
  private:
    int pin_Motor1A;
    int pin_Motor1B;
    int pin_Motor1V;
    int pin_Motor2A;
    int pin_Motor2B;
    int pin_Motor2V;

};

#endif
