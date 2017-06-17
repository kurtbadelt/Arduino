//Code for the QRE1113 Analog board
//Outputs via the serial terminal - Lower numbers mean more reflected

int sensor = 0;



void setup(){
  Serial.begin(9600);
}


void loop(){

  int valor = analogRead(sensor);
  Serial.println(valor);
delay(2);
}
