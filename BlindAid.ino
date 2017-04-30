#include <Servo.h>
Servo servo;

int usTrig = 3;
int usEcho = 4;
int duration = 0;
int distanceCM = 0;

int scaledServoValue = 0;
void setup() 
{                
servo.attach(9);
pinMode(usTrig, OUTPUT);
pinMode(usEcho, INPUT);
}

void loop() 
{
 digitalWrite(usTrig, LOW);
 delayMicroseconds(5);
 digitalWrite(usTrig, HIGH);
 delayMicroseconds(10);
 digitalWrite(usTrig, LOW);
 
 duration = pulseIn(usEcho, HIGH);
 
 distanceCM = (duration/2) / 29.1;
 
 scaledServoValue = map(distanceCM, 3, 400, 150, 40);
 
 servo.write(scaledServoValue);
}
