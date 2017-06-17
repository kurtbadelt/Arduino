nt pinMotorL1=2;
int pinMotorL2=3;
int pinMotorR1=8;
int pinMotorR2=9;
int pinEnableL = 4;
int pinEnableR = 5;
int valPWM = 175;

void setup()
{
// begin the serial communication
Serial.begin(9600);
pinMode(pinMotorL1, OUTPUT);
pinMode(pinMotorL2, OUTPUT);
pinMode(pinMotorR1, OUTPUT);
pinMode(pinMotorR2, OUTPUT);
pinMode(pinEnableL, OUTPUT);
pinMode(pinEnableR, OUTPUT);
}

void ForwardR(){
digitalWrite(pinEnableR,valPWM);
digitalWrite(pinMotorR1,HIGH);
digitalWrite(pinMotorR2,LOW);
}
void ForwardL(){
digitalWrite(pinEnableL,valPWM);
digitalWrite(pinMotorL1,HIGH);
digitalWrite(pinMotorL2,LOW);

}
void BackwardR(){
digitalWrite(pinEnableR,valPWM);
digitalWrite(pinMotorR1,LOW);
digitalWrite(pinMotorR2,HIGH);

}
void BackwardL(){
digitalWrite(pinEnableL,valPWM);
digitalWrite(pinMotorL1,LOW);
digitalWrite(pinMotorL2,HIGH);
}
void StopR(){
digitalWrite(pinEnableR,valPWM);
digitalWrite(pinMotorR1,HIGH);
digitalWrite(pinMotorR2,HIGH);

}
void StopL(){
digitalWrite(pinEnableL,valPWM);
digitalWrite(pinMotorL1,HIGH);
digitalWrite(pinMotorL2,HIGH);
}

void StopAll(){
StopR();
StopL();
}

void goForward(){
ForwardR();
ForwardL();
}

void goBackward(){
BackwardR();
BackwardL();
}

void TurnR(){
ForwardL();
BackwardR();
}
void TurnL(){
ForwardR();
BackwardL();
}

void move(byte val){
if(val==0){
// Serial.println("Caso 0-Adelante");

goForward();
delay(1000);
StopAll();

}else
if(val==1){
// Serial.println("Caso 1-Atras");

goBackward();
delay(1000);
StopAll();
}else
if(val==2){
// Serial.println("Caso 2-Derecha");

TurnR();
delay(1000);
StopAll();

}else
if(val==3){
//Serial.println("Caso 3-Izquierda");

TurnL();
delay(1000);
StopAll();

}
else{
//Serial.println("no valido ninguno");
goForward();
delay(1000);
StopAll();
}
}

void loop()
{
float ojoDerecho = analogRead(1);
float ojoIzquierdo = analogRead(0);

//adelante
move(0);
//Derecha
if(ojoDerecho > ojoIzquierdo){
move(2);
}
//Izquierda
else if(ojoIzquierdo > ojoDerecho){
move(3);
}

}
