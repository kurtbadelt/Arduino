const int sensorCentro = A0;
const int sensorIzq = A2;
const int sensorDer = A1;

int valorCentro = 0;
int valorIzq = 0;
int valorDer = 0;


void setup() {


  Serial.begin(9600);

}

/**
 * Centro, Derecha, Izquierda
 */
void comparar(int vc, int vd, int vi) {

  if ((vc > vd) && (vc > vi)) {
    //vc es el màs grande
    Serial.println("Centro");
  }

  else if ((vd > vc) && (vd > vi)) {
    // vd es el màs grande
    Serial.println("Derecha");
  }

  else if ((vi > vc) && (vi > vd)) {
    // vi es el màs grande
    Serial.println("Izquierda");
  }

  else {
    //todos son iguales
    Serial.print("SensorCentro = ");
    Serial.print(valorCentro);
    Serial.print("\t SensorIzquierda = ");
    Serial.print(valorIzq);
    Serial.print("\t SensorDerecha = ");
    Serial.print(valorDer);
    Serial.println("");


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


void loop() {


  valorCentro = lectura(sensorCentro);
  valorIzq = lectura(sensorIzq);
  valorDer = lectura(sensorDer);

  comparar(valorCentro, valorDer, valorIzq);





}
