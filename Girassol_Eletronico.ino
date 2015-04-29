#include <Servo.h>

void setup();
void loop();
void moveL();
void moveR();
void reset();
Servo myservo;
unsigned long time;
unsigned long timetest;
int val = 0;
int down = 255;
int up = 0;
int pos = 90;

int InL = 0;
int InC = 1;
int InR = 2;

int BaseL = 0;
int BaseC = 0;
int BaseR = 0;

int OutL = 0;
int OutC = 0;
int OutR = 0;

int difL = 0;
int difR = 0;


void setup()
{
  Serial.begin(9600);
  //pinMode(InL, INPUT);
  //pinMode(InC, INPUT);
  //pinMode(InR, INPUT);

  BaseL = analogRead(InL);
  BaseC = analogRead(InC);
  BaseR = analogRead(InR);

  myservo.attach(9);
  myservo.write(pos);

  //time = millis();
}

void loop()
{

  OutL = analogRead(InL) - BaseL+511;
  Serial.println(OutL);
  OutC = analogRead(InC) - BaseC+511;
  Serial.println(OutC);
  OutR = analogRead(InR) - BaseR+511;
  Serial.println(OutR);

 difL = OutC - OutL;
 difR = OutC - OutR;

  if (OutL < OutC && difL > difR)
  {
   moveL();
  }
  if (OutR < OutC && difR > difL)
  {
   moveR();
  }
  Serial.println(".....");
  delay(25);
  timetest = millis() - time;
  //if (timetest > 20000)
  //{
   // reset();
  //}
}

void moveL()
{
  difL = OutC - OutL;
  if (difL > 4)
  {
    pos = pos + 1 ;
    myservo.write(pos);
    difL= OutC - OutL;
    if(difL < 4)
    {
      reset();
    }
    if(pos == 0)
    {
      for(pos = 0; pos < 90; pos++)
      {
        myservo.write(pos);
        delay(25);
      }
    }
    Serial.println("Moving Left");
    Serial.println("New position: " + (pos));
    delay(55);
  }
  return;
}

void moveR()
{
  difR = OutC - OutR;
  if (difR > 4)
  {
    pos = pos - 1 ;
    myservo.write(pos);
    difR = OutC - OutR;
    if(difR < 4)
    {
      reset();
    }
    if(pos == 0)
    {
      for(pos = 180; pos > 90; pos--)
      {
        myservo.write(pos);
        delay(25);
      }
    }
    Serial.println("Moving Right");
    Serial.println("New position: ");
    Serial.println(pos);
    delay(5);
  }
  return;
}


void reset()
{
   BaseL = analogRead(InL);
   BaseC = analogRead(InC);
   BaseR = analogRead(InR);
   time = millis();
}




/*int main(void)
{
	init();

	setup();

	for (;;)
		loop();

	return 0;
}*/


