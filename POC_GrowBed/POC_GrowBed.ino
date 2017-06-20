  #include <DHT11.h>

  
  int sensorLuz =0;
  int sensorTempH=2;
  DHT11 sensorDHT(sensorTempH);
  const long baudRate=115200;
  const long interval = 3000;
  unsigned long previousMillis = 0;
 
  
  
  
  
  void setup() {
    // put your setup code here, to run once:
     Serial.begin(baudRate);
     
  
  }
  
  void leerSensores(){
    unsigned long currentMillis = millis();

    if(currentMillis - previousMillis >= interval) {
    
      previousMillis = currentMillis; 
      int nivelLuz = analogRead(sensorLuz);
      int error;
      float temperatura;
      float humedad;
      error = sensorDHT.read(humedad, temperatura);
      imprimirLecturas(nivelLuz,error,temperatura,humedad);
    
    }


    
  }
  
  void imprimirLecturas(int luz, int error, float temp, float hum){
  if(error==0){ 
               Serial.print("Temperatura|");
               Serial.print(temp);
               Serial.print("|Humedad|");
               Serial.print(hum);
               Serial.print("|Nivel de Luz|");
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
