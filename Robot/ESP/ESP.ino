//Bibliotecas
#include "BluetoothSerial.h"
#include "IRrecv.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

uint16_t RECV_PIN = 4;

#define RX 16
#define TX 17

//Objetos Globais
BluetoothSerial SerialBT;

IRrecv irrecv(RECV_PIN);
decode_results results;

String msg;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial2.begin(9600, SERIAL_8N1, RX, TX);
  SerialBT.begin("Explorer Robot"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  // HABILITANDO SENSOR IR
  irrecv.enableIRIn();
  Serial.println("Sensor IR Habilitado");
}

void loop() {
  if (Serial2.available()) {
    msg = String(Serial2.readString());
    Serial.println("Mensagem: " + msg);
    SerialBT.println("Mensagem: " + msg);
  }
  if (irrecv.decode(&results)) {
    if (results.value >> 32)  // print() & println() can't handle printing long longs. (uint64_t)
      Serial.print((uint32_t) (results.value >> 32), HEX);  // print the first part of the message
    Serial.println((uint32_t) (results.value & 0xFFFFFFFF), HEX); // print the second part of the message
    irrecv.resume();  // Receive the next value
  }


  if (SerialBT.available()) {
    Serial.write(SerialBT.read());
    Serial2.write(SerialBT.read());
  }
  delay(100);
}
