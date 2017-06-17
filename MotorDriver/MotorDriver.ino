const int pinMotorL1 = 13;
const int pinMotorL2 = 12;

const int pinMotorR1 = 8;
const int pinMotorR2 = 9;

const int pinEnableL = 11;
const int pinEnableR = 10;

int valPWM = 150;

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

void ForwardR() {
  analogWrite(pinEnableR, valPWM);
  digitalWrite(pinMotorR1, HIGH);
  digitalWrite(pinMotorR2, LOW);
}
void ForwardL() {
  analogWrite(pinEnableL, valPWM);
  digitalWrite(pinMotorL1, HIGH);
  digitalWrite(pinMotorL2, LOW);

}
void BackwardR() {
  analogWrite(pinEnableR, valPWM);
  digitalWrite(pinMotorR1, LOW);
  digitalWrite(pinMotorR2, HIGH);

}
void BackwardL() {
  analogWrite(pinEnableL, valPWM);
  digitalWrite(pinMotorL1, LOW);
  digitalWrite(pinMotorL2, HIGH);
}
void StopR() {
  analogWrite(pinEnableR, valPWM);
  digitalWrite(pinMotorR1, HIGH);
  digitalWrite(pinMotorR2, HIGH);

}
void StopL() {
  analogWrite(pinEnableL, valPWM);
  digitalWrite(pinMotorL1, HIGH);
  digitalWrite(pinMotorL2, HIGH);
}

void StopAll() {
  StopR();
  StopL();
}

void goForward() {
  ForwardR();
  ForwardL();
}

void goBackward() {
  BackwardR();
  BackwardL();
}

void TurnR() {
  ForwardL();
  BackwardR();
}
void TurnL() {
  ForwardR();
  BackwardL();
}

void move(byte val) {
  if (val == 0) {
    // Serial.println("Caso 0-Adelante");

    goForward();
    delay(1000);
    StopAll();

  } else if (val == 1) {
    // Serial.println("Caso 1-Atras");

    goBackward();
    delay(1000);
    StopAll();
  } else if (val == 2) {
    // Serial.println("Caso 2-Derecha");

    TurnR();
    delay(1000);
    StopAll();

  } else if (val == 3) {
    //Serial.println("Caso 3-Izquierda");

    TurnL();
    delay(1000);
    StopAll();

  }
  else {
    //Serial.println("no valido ninguno");
    goForward();
    delay(1000);
    StopAll();
  }
}

void loop()
{

for(int i=0;i<10;i++){
  move(0);
  }

  for(int i=0;i<10;i++){
    move(1);
    }
  for(int i=0;i<10;i++){
    move(2);
    }
    for(int i=0;i<10;i++){
    move(3);
    }

}
