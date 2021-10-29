#include <ExplorerRobot.h>
#include <Ultrasonic.h>

//Motor 1
int motor1V = 9;
int motor1A = 8;
int motor1B = 7;

//Motor 2
int motor2V = 10;

int motor2A = 4;
int motor2B = 2;

ExplorerRobot robot(motor1A,motor1B,motor1V,motor2A,motor2B,motor2V);

#define pino_trigger A0
#define pino_echo A1

Ultrasonic ultrasonic(pino_trigger, pino_echo);

float distancia(){
  float cmMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  return(cmMsec);
}

void apply_rules(float cm){
  if(cm <= 12){
    robot.stop_car();
  }else if(cm <= 30){
    robot.go_forward(100);
  }else if(cm > 30){
    robot.go_forward(120);
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float cm = distancia();
  apply_rules(cm);
  Serial.write('A');
  delay(2000);
  Serial.write('a');
  delay(2000);
}
