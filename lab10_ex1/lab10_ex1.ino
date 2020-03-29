#define MOTOR_D1 12
#define MOTOR_D2 13
#define MOTOR_PWM 6

void setVelocity(int v) {
  if(v > 0 && v < 256){
    digitalWrite(MOTOR_D1,HIGH);
    digitalWrite(MOTOR_D2,LOW);
    analogWrite(MOTOR_PWM,v);
    delay(1000);
  }
  if(v < 0 && v > -256){
    v = v*(-1);
    digitalWrite(MOTOR_D1,LOW);
    digitalWrite(MOTOR_D2,HIGH);
    analogWrite(MOTOR_PWM,v);
    delay(1000);
  }
  else{
    digitalWrite(MOTOR_D1,LOW);
    digitalWrite(MOTOR_D2,LOW);
  }
}

void setup() {
  pinMode(MOTOR_D1,OUTPUT);
  pinMode(MOTOR_D2,OUTPUT);
  pinMode(MOTOR_PWM,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  setVelocity(255);
  setVelocity(-255);
  setVelocity(0);
}
