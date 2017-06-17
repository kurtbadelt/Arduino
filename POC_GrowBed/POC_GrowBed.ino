#include <DHT11.h>
int sensorLuz =0;
int sensorTempH=2;
DHT11 sensorDHT(sensorTempH);


void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);

}

void leerSensores(){
  int nivelLuz = analogRead(sensorLuz);
  int error;
  float temperatura;
  float humedad;
  error = sensorDHT.read(humedad, temperatura);
  imprimirLecturas(nivelLuz,error,temperatura,humedad);
  delay(1000);
}

void imprimirLecturas(int luz, int error, float temp, float hum){
if(error==0){ 
             Serial.print("->Temperatura: ");
             Serial.print(temp);
             Serial.print(" ->Humedad: ");
             Serial.print(hum);
             Serial.print(" ->Nivel de Luz: ");
             Serial.print(luz);
             Serial.println();
  }
else{ 
             Serial.println();
             Serial.print("Error Num :");
             Serial.print(error);
             Serial.println();  
}

}

void loop() {

leerSensores();
           

}
