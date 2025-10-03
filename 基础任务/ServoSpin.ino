#include<Servo.h>
Servo myservo; 
int degree;

void setup() {
  // put your setup code here, to run once:
 myservo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
degree = 30;
myservo.write(degree);
delay(1000);  

degree = 45;
myservo.write(degree);
delay(1000);

degree = 90;
myservo.write(degree);
delay(1000);

degree = 135;
myservo.write(degree);
delay(1000); 
  
}
