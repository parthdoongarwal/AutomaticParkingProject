/*** www.arduinopoint.com ***/
/*** Arduino with IR Sensor ***/
#include <Servo.h>
Servo myservo;  // create servo object to control a servo
int SensorPin = 11;
int spots = 0;
const int buzzer = 7 ; //buzzer to arduino pin 9
void setup() {
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output
  pinMode(SensorPin, INPUT);
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  int SensorValue = digitalRead(SensorPin);
  Serial.print("SensorPin Value: ");
  Serial.println(SensorValue);
   if (SensorValue==LOW){ // LOW MEANS Object Detected
   if(spots < 5){
    spots += 1;
    myservo.write(0);
    Serial.println("Detected");
    delay(2000);
   }else{
    tone(buzzer, 1000);
   }
  }
  else
  {
        myservo.write(80);
        Serial.println("Not Detected");

  }
  Serial.println(spots);
  delay(600);
}