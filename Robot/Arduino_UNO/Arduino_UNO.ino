#include <ExplorerRobot.h>
#include <Ultrasonic.h>
#include <DHT.h>

//Motor 1
int motor1V = 9;
int motor1A = 8;
int motor1B = 7;

//Motor 2
int motor2V = 10;
int motor2A = 4;
int motor2B = 2;

ExplorerRobot robot(motor1A, motor1B, motor1V, motor2A, motor2B, motor2V);

//Ultrasonic_front
#define pino_trigger_front A0
#define pino_echo_front A1
Ultrasonic ultrasonic1(pino_trigger_front, pino_echo_front);

//Ultrasonic_back
#define pino_trigger_back A2
#define pino_echo_back A3
Ultrasonic ultrasonic2(pino_trigger_back, pino_echo_back);

//DHT
#define DHTPIN A4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

//Variáveis Globais
bool Automatic = true;
int PIN_LUMINOSITY = A5;

//Distância da frente
float get_distance_front() {
  float cmMsec;
  long microsec = ultrasonic1.timing();
  cmMsec = ultrasonic1.convert(microsec, Ultrasonic::CM);
  return (cmMsec);
}

//Distância de tras
float get_distance_back() {
  float cmMsec;
  long microsec = ultrasonic2.timing();
  cmMsec = ultrasonic2.convert(microsec, Ultrasonic::CM);
  return (cmMsec);
}

float get_temp() {
  float temp = dht.readTemperature();
  if (isnan(temp)){
    return(0);
  }else{
    return(temp);
  }
}

float get_humidity(){
  float humidity = dht.readHumidity();
  if(isnan(humidity)){
    return(0);
  }else{
    return(humidity);
  }
}


void apply_rules(float cm_front, float cm_back) {
  if (cm_front <= 12) {
    robot.stop_car();
  } else if (cm_front <= 30) {
    robot.go_forward(100);
  } else if (cm_front > 30) {
    robot.go_forward(120);
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float cm_front = get_distance_front();
  float cm_back = get_distance_back();
  float temperaure = get_temp();
  float humidity = get_humidity();
  float luminosity = analogRead(PIN_LUMINOSITY);
  Serial.println("Distância 1: " + String(cm_front) + " | Distância 2:" + String(cm_back));
  if (Automatic == true) {
    apply_rules(cm_front, cm_back);
  }

  //  Serial.print('A');
  //  delay(2000);
  //  Serial.print('B');
  //  delay(2000);
}
