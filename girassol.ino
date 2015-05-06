#include <Servo.h>
int aE = 0, aC = 1, aD = 2; //entradas analógicas
int outE = 0, outC = 0, outD = 0; //leitura dos ldrs
int pos = 90; //posiçao inicial do servo
Servo myservo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(9);
  myservo.write(pos);
}

void loop() {
  // put your main code here, to run repeatedly:
    outE = analogRead(aE);
    outC = analogRead(aC);
    outD = analogRead(aD);
    Serial.println(outE);
    Serial.println(outC);
    Serial.println(outD);
    if(outC<outE && outC<outD){ //verifica se o central é o q tem mais luz
        parar();
    }else if((outE - outC) < (outD - outC)){ //verifica as diferenças de luz, com relação ao central
        mover_e();
    }else if((outE - outC) > (outD - outC)){
        mover_d();
    }else if((outE - outC) == (outD - outC)){
        parar();
    }
    delay(100);
}

void mover_d(){
    Serial.println("\nMovendo para direita");
    pos = pos - 1;
    if(pos < 45){
        parar();
        pos = 44;
    }else{
      myservo.write(pos);
    }
}

void mover_e(){
    Serial.println("\nMovendo para esquerda");
    pos = pos + 1;
    if(pos > 135){
        parar();
        pos = 136;
    }else{
      myservo.write(pos);
    }
}

void parar(){
    Serial.println("\nParando!");
}

