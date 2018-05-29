#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 1;    // variable to store the servo position
char a = 'G';

void setup() {
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  pinMode(8, OUTPUT);
  digitalWrite(8, HIGH);
  myservo.attach(10);  // attaches the servo on pin 9 to the servo object
  myservo.write(pos);
}

void loop() {
  
  if(Serial.available()){
     Serial.print("i'm in\n");
     pos = Serial.parseInt();
     Serial.print(pos);
     myservo.write(pos);
  }
}
