int PIN_LED_BACK_FORWARD;


String msg;

#define RXp2 16
#define TXp2 17

void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, RXp2, TXp2);
}

void loop() {
  if (Serial2.available()) {
    msg = String(Serial2.readString());
    Serial.println("Mensagem: " + msg);
    if (msg == "A") {
      digitalWrite(2, HIGH);
    } else {
      digitalWrite(2, LOW);
    }
  }
}
