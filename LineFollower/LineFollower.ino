const int pinMotorL1 = 13;
const int pinMotorL2 = 12;

const int pinMotorR1 = 8;
const int pinMotorR2 = 9;

const int pinEnableL = 11;
const int pinEnableR = 10;

const int sensorCentro = A0;
const int sensorIzq = A2;
const int sensorDer = A1;

int valorCentro = 0;
int valorIzq = 0;
int valorDer = 0;

int valPWM = 200;

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
  Serial.begin(9600);
}



/**
 * Centro, Derecha, Izquierda
 */
int comparar(int vc, int vd, int vi) {
  int salida = 0;

  if ((vi > 150) && (vc > 150) && (vd > 150)) {

    Serial.println("todos en negro");
    return 4;
  }

  if ((vc > vd) && (vc > vi)) {
    //vc es el màs grande
    Serial.print("Centro \t");
    Serial.print("SensorIzquierda = ");
    Serial.print(vi);
    Serial.print("\t SensorCentro = ");
    Serial.print(vc);
    Serial.print("\t SensorDerecha = ");
    Serial.print(vd);
    Serial.println("");
    if (vc > 150) {
      salida = 0;
    } else {
      salida = 0;
    }
    return salida;
  }

  else if ((vd > vc) && (vd > vi)) {
    // vd es el màs grande
    Serial.print("Derecha \t");
    Serial.print("SensorIzquierda = ");
    Serial.print(vi);
    Serial.print("\t SensorCentro = ");
    Serial.print(vc);
    Serial.print("\t SensorDerecha = ");
    Serial.print(vd);
    Serial.println("");
    if (vd > 150) {

      salida = 2;
    } else {
      salida = 0;
    }
    return  salida;
  }

  else if ((vi > vc) && (vi > vd)) {
    // vi es el màs grande
    Serial.print("Izquierda \t");
    Serial.print("SensorIzquierda = ");
    Serial.print(vi);
    Serial.print("\t SensorCentro = ");
    Serial.print(vc);
    Serial.print("\t SensorDerecha = ");
    Serial.print(vd);
    Serial.println("");
    if (vi > 150) {
      salida = 3;
    } else {
      salida = 0;
    }
    return salida;
  }



  else {
    //no hay un dominante
    salida = 0;

    Serial.print("SensorIzquierda = ");
    Serial.print(vi);
    Serial.print("\t SensorCentro = ");
    Serial.print(vc);
    Serial.print("\t SensorDerecha = ");
    Serial.print(vd);
    Serial.println("");
    return salida;


  }

}


int lectura(int sensor) {
  int temp1 = 0;
  int temp2 = 0;
  int temp3 = 0;
  int resultado = 0;

  temp1 = analogRead(sensor);
  delay(2);
  temp2 = analogRead(sensor);
  delay(2);
  temp2 = analogRead(sensor);

  resultado = (temp1 + temp2 + temp3) / 3;
  return resultado;
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

void move(int val) {
  if (val == 0) {
    Serial.print("Caso 0-Adelante  ");

    goForward();
    //  delay(500);
    //  StopAll();

  } else if (val == 1) {
    Serial.print("Caso 1-Atras  ");

    goBackward();
    //  delay(500);
    // StopAll();

  } else if (val == 2) {
    Serial.print("Caso 2-Derecha  ");

    TurnR();
    // delay(500);
    // StopAll();

  } else if (val == 3) {
    Serial.print("Caso 3-Izquierda ");

    TurnL();
    // delay(500);
    // StopAll();

  } else if (val == 4) {
    Serial.print("Alto");


    StopAll();

  }
  else {
    // Serial.print("  no valido ninguno");
    // goForward();
    // delay(500);
    StopAll();
  }
}

void loop()
{
  ///actions

  valorCentro = lectura(sensorCentro);
  valorIzq = lectura(sensorIzq);
  valorDer = lectura(sensorDer);

  int res = 0;
  res = comparar(valorCentro, valorDer, valorIzq);
  move(res);



}



