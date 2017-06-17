/*
Reading an Infrared distance sensor
 SHARP 2Y0A21 and moving a Hitec Servo when something gets close
 */

#include <Servo.h>
               // the average
Servo servoOutput;
int ServoPin = 9;
int pos = 0;
int sensorPin = A0;
int sensorInput = 0;
int buzzPin = 13;
int avgDistance=1000;


void setup(){
  servoOutput.attach(ServoPin);
  Serial.begin(9600);
  pinMode(buzzPin,OUTPUT);
  

}

void moveServo(){

  for(pos = 0; pos <= 180; pos += 4)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 4 degree to pop out fast 
    servoOutput.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  delay(3000);                       // keep te monster out for 3 seconds 
  for(pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees back slow 
  {                                
    servoOutput.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 

}

float getDistance(int input){
  float volts = input*0.0048828125; 
  float distance = 65*pow(volts, -1.10);
  return distance;
}




void loop(){
digitalWrite(buzzPin,LOW);

  sensorInput = analogRead(sensorPin);
  servoOutput.write(pos); 

  float IRDistance = getDistance(sensorInput);
  
  Serial.println(IRDistance, DEC);

  if(IRDistance <100){  // turn on camera
    digitalWrite(buzzPin,HIGH);
    delay(10);
    if(IRDistance<70){ //shoot camera, move servo, sound 
      
      moveServo();  

    }
    else{
      digitalWrite(buzzPin,LOW);
      pos=0;
      servoOutput.write(pos); 
    }
  }

}

