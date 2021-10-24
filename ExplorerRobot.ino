#include <ExplorerRobot.h>
#include <Ultrasonic.h>

//Motor 1
int motor1V = ;
int motor1A = ;
int motor1B = ;

//Motor 2
int motor2V = ;
int motor2A = ;
int motor2B = ;

ExplorerRobot robot(motor1A,motor1B,motor1V,motor2A,motor2B,motor2V);

#define pino_trigger 4
#define pino_echo 5

Ultrasonic ultrasonic(pino_trigger, pino_echo);

float distancia(){
  float cmMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  return(cmMsec);
}

void apply_rules(cm){
  if(cm <= 12){
    robot.stop()
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
}
