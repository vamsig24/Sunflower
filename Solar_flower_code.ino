/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo

Servo myservo2;


int val = 0;    // variable to store the servo position
int LDRPin1 = A0; //Servo1 LDR
int LDRPin2 = A1; //Servo2 LDR

void setup() {
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(10);
//  myservo.write(90);
//  delay(100);
//  myservo2.write(90);
//  delay(100);

}

void loop() {
  int LDR1 = analogRead(LDRPin1);
  Serial.print("Right LDR ");
  Serial.println(LDR1);

  int LDR2 = analogRead(LDRPin2);
  Serial.print("Left LDR ");
  Serial.println(LDR2);

  int s1 = myservo.read();
  Serial.print("Servo pos ");
  Serial.println(s1);

  //MOVE 1st Servo
  if(LDR1 < 40 ) // If light on the right is low move towards 20 (left)
  {
    if(s1>60)
    {
      Serial.println("Moving left towards Sun");
      for( int i = s1; i>20;i--)
      {
      myservo.write(i);
      delay(10);
      }
    }
    else
    {
      Serial.println("Loading energy");
    }
  }
  else if(LDR1 > 40 )
  {
    if(s1<60)
    {
      Serial.println("Moving right towards Sun");
      for( int i = s1; i<90;i++)
      {
      myservo.write(i);
      delay(10);
      }
    }
    else
    {
      Serial.println("Loading energy");
    }
  }

 int s2 = myservo2.read();
  Serial.print("Servo pos ");
  Serial.println(s2);
  
  //MOVE 2nd Servo
    if(LDR2 < 600 ) // If light on the right is low move towards 20 (left)
  {
    if(s2>60)
    {
      Serial.println("Moving left towards Sun Servo2");
      for( int i = s2; i>20;i--)
      {
      myservo2.write(i);
      delay(10);
      }
    }
    else
    {
      Serial.println("Loading energy");
    }
  }
  else if(LDR2 > 600 )
  {
    if(s2<60)
    {
      Serial.println("Moving right towards Sun Servo2");
      for( int i = s2; i<120;i++)
      {
      myservo2.write(i);
      delay(10);
      }
    }
    else
    {
      Serial.println("Loading energy");
    }
  }
}
