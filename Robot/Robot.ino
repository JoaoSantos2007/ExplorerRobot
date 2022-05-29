#include <ExplorerRobot.h>
#include <Ultrasonic.h>
#include <DHT.h>
#include <ArduinoJson.h>

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

//Distância de trás
float get_distance_back() {
  float cmMsec;
  long microsec = ultrasonic2.timing();
  cmMsec = ultrasonic2.convert(microsec, Ultrasonic::CM);
  return (cmMsec);
}

//Temperatura
float get_temp() {
  float temp = dht.readTemperature();
  if (isnan(temp)) {
    return (0);
  } else {
    return (temp);
  }
}

//Umidade
float get_humidity() {
  float humidity = dht.readHumidity();
  if (isnan(humidity)) {
    return (0);
  } else {
    return (humidity);
  }
}

//Apply rules
void apply_rules(float cm_front, float cm_back) {
  if (cm_front <= 12) {
    robot.stop_car();
  } else if (cm_front <= 30) {
    robot.go_forward(100);
  } else if (cm_front > 30) {
    robot.go_forward(120);
  }
}

void get_information() {
  StaticJsonDocument<256> doc;
  doc["cm_front"] = get_distance_front();
  doc["cm_back"] = get_distance_back();
  doc["temperature"] = get_temp();
  doc["humidity"] = get_humidity();
  doc["luminosity"] = analogRead(PIN_LUMINOSITY);
  char out[256];
  serializeJson(doc, out);
  Serial.println(out);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
}


void loop() {
  // put your main code here, to run repeatedly:

  //Central de Comunicação
  if (Serial.available()) {
    String msg = String(Serial.readString());
    Serial.println("msg: " + msg);
    if (msg[0] == '#') {
      if (msg.indexOf("_") != -1) {
        msg.remove(0, 1);
        int pos_anderline = msg.indexOf("_");
        int tamanho_msg = msg.length();
        String velocidade = "";
        for (int i = pos_anderline + 1; i < tamanho_msg; i++) {
          velocidade += msg[i];
        }
        msg.remove(pos_anderline, (tamanho_msg - pos_anderline));
        String command = msg;
        Serial.println("comando: " + command);
      }
    }
  }


  if (Automatic == true) {
    float cm_front = get_distance_front();
    float cm_back = get_distance_back();
    apply_rules(cm_front, cm_back);
  }else{
//    if command == 
  }

}
