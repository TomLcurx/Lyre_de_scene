const int PIN_DIR_Hor 18;
const int PIN_PUL_Hor 19;
const int PIN_DIR_Ver 22;
const int PIN_PUL_Ver 23;


void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_DIR_Hor, OUTPUT);
  pinMode(PIN_PUL_Hor, OUTPUT);
  pinMode(PIN_DIR_Ver, OUTPUT);
  pinMode(PIN_PUL_Ver, OUTPUT);

  delayMicroseconds(5);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(PIN_DIR_Hor,LOW);
  digitalWrite(PIN_DIR_Ver,LOW);

  for(int i=0; i<max_pas; i++){
    digitalWrite(PIN_PUL_Hor,LOW);
    delayMicroseconds(10);
    digitalWrite(PIN_PUL_Hor,HIGH);
    delayMicroseconds(10);
  }

  delay(2000);

    for(int i=0; i<max_pas; i++){
    digitalWrite(PIN_PUL_Ver,LOW);
    delayMicroseconds(10);
    digitalWrite(PIN_PUL_Ver,HIGH);
    delayMicroseconds(10);
  }
  
  delay(2000);

}
