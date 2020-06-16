#include <LiquidCrystal.h> //Load Liquid Crystal Library
LiquidCrystal LCD(13, 12, 5, 4, 3, 2);
int inches = 0;
int myInts = 0;
int Avg=0;
int cm = 0; 
int intCounter=0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);

  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);

  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);
  
  LCD.begin(16,2);
  LCD.setCursor(0,0);
  LCD.print("Target Distance:");
}

void SetOutput(int intTriggerPin, int EchoPin, char my_str1[])
{
  cm = 0.01723 * readUltrasonicDistance(intTriggerPin, EchoPin);  
  inches = (cm / 2.54);
  Serial.print(my_str1); 
  Serial.print(inches);  
  Serial.println("");
  
  //LCD.setCursor(0,1);
  //LCD.print("                ");
  //LCD.setCursor(0,1);
  //LCD.print(my_str1);
  //LCD.print(inches);
  
  myInts = myInts + inches;
  intCounter++;
  delay(1000);
}

void loop()
{
   SetOutput(6,7,"WT/SRT/77777-");
   SetOutput(8,9,"WT/SRT/99999-");
   //SetOutput(10,11,"WT/SRT/99999-");
  //SetOutput(6,7,"WT/SRT/66666-");
  //SetOutput(8,9,"WT/SRT/77777-");
  //SetOutput(11,11,"WT/SRT/99999-");
  Avg = myInts/intCounter;
  Serial.print("Avg ");
  Serial.println(Avg);
  
  LCD.setCursor(0,1);
  LCD.print("                ");
  LCD.setCursor(0,1);
  LCD.print("Avg ");
  LCD.print(Avg);
    
  myInts=0;
  intCounter=0;
    
}
