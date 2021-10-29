int led_back_left = 2;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led_back_left,OUTPUT);
  //digitalWrite(led_back_left,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    char c = Serial.read();
    if(c=='A'){
      digitalWrite(led_back_left, HIGH);
    }
    if(c=='a'){
      digitalWrite(led_back_left, LOW);
    }
  }
}
