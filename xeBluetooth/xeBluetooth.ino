#include <SoftwareSerial.h>
SoftwareSerial BTBlue(0, 1); // RX | TX
#define anaa 9 // x- endstop
#define in1 10 // y- endstop
#define in2 12 // spinen
#define in3 13 // spindir
#define in4 A3 // cooen
#define anab 11 // z- endstop
#define XSTEP 2 //Stepper Motor Step pin
#define YSTEP 3
#define ZSTEP 4
//#define ASTEP 12
#define XDIR 5 // Stepper motor Direction control pin
#define YDIR 6
#define ZDIR 7
//#define ADIR 13
#define ENABLE 8 // CNC Shield Enable P
byte dir1 = 0;
byte dir2 = 1;
byte BTData;
int speda, spedb;
long inix, iniy, iniz, gockep=80, kep;
byte arm, gap;
#define XMOTORACC 10000 // Acceleration and Max Speed values
#define XMOTORMAXSPEED 7000
#define YMOTORACC 10000
#define YMOTORMAXSPEED 7000
#define AMOTORACC 10000
#define AMOTORMAXSPEED 7000
#include <AccelStepper.h>
AccelStepper XMOTOR(1,XSTEP,XDIR);
AccelStepper YMOTOR(1,YSTEP,YDIR);
AccelStepper ZMOTOR(1,ZSTEP,ZDIR);
void setup(){
  
   pinMode(ENABLE,OUTPUT);
 digitalWrite(ENABLE,LOW);
pinMode(anaa, OUTPUT);
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(in3, OUTPUT);
pinMode(in4, OUTPUT);
pinMode(anab, OUTPUT);
   Serial.begin(9600);
  BTBlue.begin(9600);  //Default Baud for comm, it may be different for your Module. 
  Serial.println("The bluetooth gates are open.\n Connect to HC-05 from any other bluetooth device with 1234 as pairing key!.");
   XMOTOR.setMaxSpeed(2500.0);      // Set Max Speed of Stepper (Slower to get better accuracy)
 XMOTOR.setAcceleration(4000.0);  // Set Acceleration of Stepper
 YMOTOR.setMaxSpeed(2500.0);      // Set Max Speed of Stepper (Slower to get better accuracy)
 YMOTOR.setAcceleration(4000.0);  // Set Acceleration of Stepper
  ZMOTOR.setMaxSpeed(2500.0);      // Set Max Speed of Stepper (Slower to get better accuracy)
 ZMOTOR.setAcceleration(9500.0);  // Set Acceleration of Stepper
  arm=0; 
  inix=0; iniy=0;gap=0;
      digitalWrite(ENABLE,HIGH);

}
void loop() {

  if (BTBlue.available())
  BTData=BTBlue.read();
    Serial.write(BTData);

////////////////////////////////////////// code arm
if (BTData == 'X')
{
 arm=1; 
}
if (BTData == 'x')
{
 arm=0; 
}


if  (arm==1)
{
 digitalWrite(ENABLE,LOW);

////////////////////////////////////// tay kep
/*
    if(BTData == '0')
  {
     ZMOTOR.setMaxSpeed(5000.0);      // Set Max Speed of Stepper (Slower to get better accuracy)
 ZMOTOR.setAcceleration(3500.0);  // Set Acceleration of Stepper
    kep=gockep*0;
  ZMOTOR.runToNewPosition(kep);
  
//  ZMOTOR.run();
  }
    if(BTData == '1')
  {
     ZMOTOR.setMaxSpeed(5000.0);      // Set Max Speed of Stepper (Slower to get better accuracy)
 ZMOTOR.setAcceleration(3500.0);  // Set Acceleration of Stepper
    kep=gockep*1;
  ZMOTOR.runToNewPosition(kep);
//  ZMOTOR.run();
  }
      if(BTData == '2')
  {
     ZMOTOR.setMaxSpeed(5000.0);      // Set Max Speed of Stepper (Slower to get better accuracy)
 ZMOTOR.setAcceleration(3500.0);  // Set Acceleration of Stepper
     kep=gockep*2;
  ZMOTOR.runToNewPosition(kep);
//  ZMOTOR.run();
  }
      if(BTData == '3')
  {
     ZMOTOR.setMaxSpeed(5000.0);      // Set Max Speed of Stepper (Slower to get better accuracy)
 ZMOTOR.setAcceleration(3500.0);  // Set Acceleration of Stepper
     kep=gockep*3;
  ZMOTOR.runToNewPosition(kep);
//ZMOTOR.run();
  }
      if(BTData == '4')
  {
     ZMOTOR.setMaxSpeed(5000.0);      // Set Max Speed of Stepper (Slower to get better accuracy)
 ZMOTOR.setAcceleration(3500.0);  // Set Acceleration of Stepper
     kep=gockep*4;
  ZMOTOR.runToNewPosition(kep);
 //ZMOTOR.run();
  }
      if(BTData == '5')
  {
     ZMOTOR.setMaxSpeed(5000.0);      // Set Max Speed of Stepper (Slower to get better accuracy)
 ZMOTOR.setAcceleration(3500.0);  // Set Acceleration of Stepper
     kep=gockep*5;
  ZMOTOR.runToNewPosition(kep);
ZMOTOR.run();
  }
      if(BTData == '6')
  {
     ZMOTOR.setMaxSpeed(5000.0);      // Set Max Speed of Stepper (Slower to get better accuracy)
 ZMOTOR.setAcceleration(3500.0);  // Set Acceleration of Stepper
     kep=gockep*6;
  ZMOTOR.runToNewPosition(kep);
///ZMOTOR.run();
  }
      if(BTData == '7')
  {
     ZMOTOR.setMaxSpeed(5000.0);      // Set Max Speed of Stepper (Slower to get better accuracy)
 ZMOTOR.setAcceleration(3500.0);  // Set Acceleration of Stepper
     kep=gockep*7;
  ZMOTOR.runToNewPosition(kep);
 //ZMOTOR.run();
  }
      if(BTData == '8')
  {
     ZMOTOR.setMaxSpeed(5000.0);      // Set Max Speed of Stepper (Slower to get better accuracy)
 ZMOTOR.setAcceleration(3500.0);  // Set Acceleration of Stepper
     kep=gockep*8;
  ZMOTOR.runToNewPosition(kep);
//  ZMOTOR.run();
  }
      if(BTData == '9')
  {
     ZMOTOR.setMaxSpeed(5000.0);      // Set Max Speed of Stepper (Slower to get better accuracy)
 ZMOTOR.setAcceleration(3500.0);  // Set Acceleration of Stepper
     kep=gockep*9;
  ZMOTOR.runToNewPosition(kep);
 /// ZMOTOR.run();
  }
      if(BTData == 'q')
  {
     ZMOTOR.setMaxSpeed(5000.0);      // Set Max Speed of Stepper (Slower to get better accuracy)
 ZMOTOR.setAcceleration(3500.0);  // Set Acceleration of Stepper
     kep=gockep*10;
  ZMOTOR.runToNewPosition(kep);
 // ZMOTOR.run();
  }

*/
/*
if (BTData>=48 || BTData <=50) gap=1;
  if (BTData>=56 || BTData <=57  ) gap=2; else gap=0;
*/
if (BTData=='G')
{
   if (iniz<0) iniz=1;
      ZMOTOR.moveTo(iniz);
  iniz++;
 //  BTData=BTBlue.read();
  ZMOTOR.run();
}
if (BTData=='I')
{
   if (iniz>0) iniz=-1;
      ZMOTOR.moveTo(iniz);
  iniz--;
  // BTData=BTBlue.read();
  ZMOTOR.run();
}
  /////////////////////////////////////// code move x y
  if (BTData == 'B')
  {
   if (iniy<0) iniy=500;
      YMOTOR.moveTo(iniy);
  iniy++;
  YMOTOR.run();
  }
    if (BTData == 'F')
  {
   if (iniy>0) iniy=-500;
      YMOTOR.moveTo(iniy);
  iniy--;
 YMOTOR.run();
  }
    if (BTData == 'L')
  {
    if (inix<0) inix=1;
      XMOTOR.moveTo(inix);
  inix++;
  XMOTOR.run();
  }
      if (BTData == 'R')
  {
     if (inix>0) inix=-1;
      XMOTOR.moveTo(inix);
  inix--;
  XMOTOR.run();
  }
  
      /*  ZMOTOR.runToNewPosition(500);
        delay(1000);
         ZMOTOR.runToNewPosition(0);
        delay(1000);
 //iniz--;
 // ZMOTOR.run();*/
 //Serial.println(gap);
}

////////////////////////////////////////// code set speed
if (arm==0)
{
     digitalWrite(ENABLE,HIGH);
    if(BTData == '0')
  {
speda=0;
spedb=0;
  }
    if(BTData == '1')
  {
   
speda=25;
spedb=25;
  }
      if(BTData == '2')
  {
speda=51;
spedb=51;
  }
      if(BTData == '3')
  {
speda=76;
spedb=76;
  }
      if(BTData == '4')
  {
speda=102;
spedb=102;
  }
      if(BTData == '5')
  {
speda=127;
spedb=127;
  }
      if(BTData == '6')
  {
speda=153;
spedb=153;
  }
      if(BTData == '7')
  {
speda=178;
spedb=178;
  }
      if(BTData == '8')
  {
speda=204;
spedb=204;
  }
      if(BTData == '9')
  {
speda=229;
spedb=229;
  }
      if(BTData == 'q')
  {
speda=254;
spedb=254;
  }
  
  
 /////////// di chuyen
  if(BTData == 'F')
  {
      analogWrite(anaa, speda);
      analogWrite(anab, spedb);
    forward();
  }
    if(BTData == 'B')
  {
            analogWrite(anaa, speda);
      analogWrite(anab, spedb);
   backward();
  }
    if(BTData == 'L')
  {
            analogWrite(anaa, speda);
      analogWrite(anab, spedb);
   left();
  }
    if(BTData == 'R')
  {
            analogWrite(anaa, speda);
      analogWrite(anab, spedb);
right();
}
    if(BTData == 'G')
  {
            analogWrite(anaa, speda);
      analogWrite(anab, spedb/2);
   forward();
  // left();
   
  }
    if(BTData == 'I')
  {
            analogWrite(anaa, speda/3);
      analogWrite(anab, spedb);
      forward();
  // right();
  }
    if(BTData == 'H')
  {
            analogWrite(anaa, speda);
      analogWrite(anab, spedb/2);
    backward();
 //   left();
  }
    if(BTData == 'J')
  {
            analogWrite(anaa, speda/3);
      analogWrite(anab, spedb);
       backward();
  //  right();
  }
      if(BTData == 'S')
  {
            analogWrite(anaa, speda);
      analogWrite(anab, spedb);
Stop();
  }
}
  }
  ///////////////  chuong trinh con dieu khien xe
void forward()
{
digitalWrite(in1, dir2);
digitalWrite(in2, dir1);
digitalWrite(in3, dir2);
digitalWrite(in4, dir1);

}
void backward()
{
  digitalWrite(in1, dir1);
digitalWrite(in2, dir2);
digitalWrite(in3, dir1);
digitalWrite(in4, dir2);
}
void left()
{
  digitalWrite(in1, dir1);
digitalWrite(in2, dir1);
digitalWrite(in3, dir1);
digitalWrite(in4, dir2);
}
void right()
{
  digitalWrite(in1, dir1);
digitalWrite(in2, dir2);
digitalWrite(in3, dir1);
digitalWrite(in4, dir1);
}
void Stop()
{
  digitalWrite(in1, dir1);
digitalWrite(in2, dir1);
digitalWrite(in3, dir1);
digitalWrite(in4, dir1);
}
