/*
Projeto Girassol Eletronico
Marlon Prudente
Geovana Franco
*/
#include <Servo.h>
//Pino analógico em que o sensor está conectado.
int sensor0 = 0;
int sensor1 = 1;
int sensor2 = 2;
int pos = 0;
Servo myservo;


//variável usada para ler o valor do sensor em tempo real.
int valorSensorE = 0; 
int valorSensorC = 0; 
int valorSensorD = 0; 

//Método setup, executado uma vez ao ligar o Arduino.
void setup(){
  //Ativando o serial monitor que exibirá os 
  //valores lidos no sensor.
  myservo.attach(9);
  Serial.begin(9600);
}
//Método loop, executado enquanto o Arduino estiver ligado.
void loop(){
  
  //Lendo o valor do sensor.
  int valorSensorE = analogRead(sensor0);
  int valorSensorC = analogRead(sensor1);
  int valorSensorD = analogRead(sensor2);
  
  //Exibindo o valor do sensor no serial monitor.
  Serial.println("Sensor E:  ");
  Serial.println(valorSensorE);
    Serial.println("\nSensor C:  ");
  Serial.println(valorSensorC);
    Serial.println("\nSensor D:  ");
  Serial.println(valorSensorD);
  
  if(valorSensorE < valorSensorC )
  {
       pos = pos + 5;
       myservo.write(pos);
  }
  else if(valorSensorD < valorSensorC )
  {
    pos = pos - 5;
    myservo.write(pos);
  }
  else
  {
    //myservo.write(0);
  }
  
  delay(1000); 
}
