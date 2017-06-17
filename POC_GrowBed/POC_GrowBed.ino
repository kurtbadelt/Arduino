#include <DHT11.h>
int sensorLuz =0;
int sensorTempH=2;
DHT11 sensorDHT(sensorTempH);


void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int nivelLuz = analogRead(sensorLuz);
  int error;
  float temperatura;
  float humedad;

         if((error = sensorDHT.read(humedad, temperatura)) == 0)    // Si devuelve 0 es que ha leido bien
          {
             Serial.print("Temperatura: ");
             Serial.print(temperatura);
             Serial.print(" /Humedad: ");
             Serial.print(humedad);
             Serial.print(" /Nivel de Luz: ");
             Serial.print(nivelLuz);
             Serial.println();
          }
       else
          {
             Serial.println();
             Serial.print("Error Num :");
             Serial.print(error);
             Serial.println();
          }
       delay(1000);            //Recordad que solo lee una vez por segundo

}
