#include <AltSoftSerial.h>
AltSoftSerial sending;
#define echoPin1 2
#define trigPin1 3
#define echoPin2 10
#define trigPin2 11
#define relay1 7
#define relay2 6
#define relay3 5
#define relay4 4
long duration;
int distance;
int adp=1;
bool flag1=true;
bool flag2=false;
int incoming_value=0;
int n=3000;


void setup() {
   sending.begin(9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  digitalWrite(relay1,HIGH);
  digitalWrite(relay2,HIGH);
  digitalWrite(relay3,HIGH);
  digitalWrite(relay4,HIGH);

 
}

void loop() {

  while(adp)
  {
 if(Serial.available()>0)
  {
    incoming_value=Serial.read();
    Serial.print("incoming_value: ");
    Serial.print(incoming_value);
    Serial.print("\n");
    if(incoming_value=='1')
    {
      digitalWrite(13,HIGH);
      digitalWrite(relay1,LOW);
      delay(100);
      digitalWrite(relay2,LOW);
      delay(110);
      digitalWrite(relay3,LOW);
      delay(120);
      digitalWrite(relay4,LOW);
     
      }
     else if(incoming_value=='0')
     {
      digitalWrite(13,LOW);
      digitalWrite(relay1,HIGH);
      delay(100);
      digitalWrite(relay2,HIGH);
      delay(110);
      digitalWrite(relay3,HIGH);
      delay(120);
      digitalWrite(relay4,HIGH);
      }
      else if(incoming_value==50){
          n=5000;
          Serial.print("Delay added of 5 seconds ");
          }
      else if(incoming_value==51){
          n=10000;
          Serial.print("Delay added of 10 seconds ");
          }
      else if(incoming_value==52){
          n=20000;
          Serial.print("Delay added of 20 seconds ");
          }
    }
  long duration1=0;
  int distance1=0;
  long duration2=0;
  int distance2=0;
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
 
  duration1 = pulseIn(echoPin1, HIGH);
 
  distance1 = duration1 * 0.034 / 2;
 
  sending.print("Distance 1: ");
  sending.print(distance1);
  sending.println(" cm");


 
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
 
  duration2 = pulseIn(echoPin2, HIGH);
 
  distance2 = duration2 * 0.034 / 2;
 
  sending.print("Distance 2: ");
  sending.print(distance2);
  sending.println(" cm");
 
   
  if (distance1 <70)
  {
    while(distance1<70)
    {
      digitalWrite(relay1,LOW);
      delay(100);
      digitalWrite(relay2,LOW);
      delay(110);
      digitalWrite(relay3,LOW);
      delay(120);
      digitalWrite(relay4,LOW);

      //Measuring distance1 again
         
       digitalWrite(trigPin1, LOW);
       delayMicroseconds(2);
       digitalWrite(trigPin1, HIGH);
       delayMicroseconds(10);
       digitalWrite(trigPin1, LOW);
 
       duration1 = pulseIn(echoPin1, HIGH);
 
       distance1 = duration1 * 0.034 / 2;
       sending.print("Distance 1 in while loop: ");
       sending.print(distance1);
       sending.println(" cm");
       delay(5000);
 
    }
    //loop for checking entry and exit of human
   while(flag1!=false)
    {
       digitalWrite(relay1,LOW);
     
       digitalWrite(relay2,LOW);
     
       digitalWrite(relay3,LOW);
     
       digitalWrite(relay4,LOW);

       //distance1
       digitalWrite(trigPin1, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin1, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin1, LOW);
 
      duration1 = pulseIn(echoPin1, HIGH);
 
      distance1 = duration1 * 0.034 / 2;
 
//      sending.print("Still didn't passed the stairs!!Sensor 1 distance : ");
//      sending.print(distance1);
//      sending.println(" cm");
//      //distance2
       digitalWrite(trigPin2, LOW);
       delayMicroseconds(2);
       digitalWrite(trigPin2, HIGH);
       delayMicroseconds(10);
       digitalWrite(trigPin2, LOW);
 
       duration2 = pulseIn(echoPin2, HIGH);
 
       distance2 = duration2 * 0.034 / 2;
       sending.print("still, didn't passed the stairs!! Sensor 2 distance : ");
       sending.print(distance2);
       sending.println(" cm");
       if(distance2<70)
       {
        flag1=false;
        }
       else if(distance1<70)
       {
       // Serial.print("Switching off lights in 4 seconds...");
        delay(3000);
        digitalWrite(relay4,HIGH);
        delay(100);
        digitalWrite(relay3,HIGH);
        delay(110);
        digitalWrite(relay2,HIGH);
        delay(120);
        digitalWrite(relay1,HIGH);
        flag1=false;
        }
 
     
      }flag1=true;
      //adding delay via BT
//      incoming_value=Serial.read();
//      while(incoming_value==50||incoming_value==51||incoming_value==52)
      //{
//        else if(incoming_value==50){
//          delay(5000);
//          }
//         else if(incoming_value==51){
//          delay(10000);
//          }
//         else if(incoming_value==52){
//          delay(20000);
//          }
//         else
//         delay(3000);
//         Serial.print("Default delay");
//        
//        //}
//    Serial.print("Delay1 :");
//    Serial.print(n); 
    delay(n);
    digitalWrite(relay1,HIGH);
    delay(100);
    digitalWrite(relay2,HIGH);
    delay(110);
    digitalWrite(relay3,HIGH);
    delay(120);
    digitalWrite(relay4,HIGH);
   
    }
    // Ultrasonic sensor 2 distance

 else if (distance2 <70)
  {
    while(distance2<70)
    {
      digitalWrite(relay4,LOW);
      delay(100);
      digitalWrite(relay3,LOW);
      delay(110);
      digitalWrite(relay2,LOW);
      delay(120);
      digitalWrite(relay1,LOW);

      //Measuring distance2 again
         
       digitalWrite(trigPin2, LOW);
       delayMicroseconds(2);
       digitalWrite(trigPin2, HIGH);
       delayMicroseconds(10);
       digitalWrite(trigPin2, LOW);
 
       duration2 = pulseIn(echoPin2, HIGH);
 
       distance2 = duration2 * 0.034 / 2;
       sending.print("Distance 2 in while loop: ");
       sending.print(distance2);
       sending.println(" cm");
       delay(5000);
 
    }
   //loop for checking entry and exit of human(sensor 2)
   while(flag2!=false)
   {  
      digitalWrite(relay4,LOW);
     
      digitalWrite(relay3,LOW);
     
      digitalWrite(relay2,LOW);
     
      digitalWrite(relay1,LOW);
      //measuring distance 1
      digitalWrite(trigPin1, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin1, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin1, LOW);
 
      duration1 = pulseIn(echoPin1, HIGH);
 
      distance1 = duration1 * 0.034 / 2;
 
      sending.print("Still didn't passed the stairs!!Sensor 1 distance : ");
      sending.print(distance1);
      sending.println(" cm");

      //measuring distance 2
      digitalWrite(trigPin2, LOW);
       delayMicroseconds(2);
       digitalWrite(trigPin2, HIGH);
       delayMicroseconds(10);
       digitalWrite(trigPin2, LOW);
 
       duration2 = pulseIn(echoPin2, HIGH);
 
       distance2 = duration2 * 0.034 / 2;
//       sending.print("Distance 2 in while loop: ");
//       sending.print(distance2);
//       sending.println(" cm");
      if(distance1<70)
      {
        flag2=false;
        }
      else if(distance2<70)
       {
      //  Serial.print("Switching off lights in 4 seconds...");
        delay(4000);
        digitalWrite(relay1,HIGH);
        delay(100);
        digitalWrite(relay2,HIGH);
        delay(110);
        digitalWrite(relay3,HIGH);
        delay(120);
        digitalWrite(relay4,HIGH);
        flag2=false;;
        }
      else
      {
        continue;
        }

     
    }
    flag2=true;
//    Serial.print("Delay2 :");
//    Serial.print(n);
    delay(n);
    digitalWrite(relay4,HIGH);
    delay(100);
    digitalWrite(relay3,HIGH);
    delay(110);
    digitalWrite(relay2,HIGH);
    delay(120);
    digitalWrite(relay1,HIGH);
   
    }
}
}
