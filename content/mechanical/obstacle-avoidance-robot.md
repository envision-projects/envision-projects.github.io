---
title: Obstacle Avoidance Robot
date: 2022-08-09T20:54:50.949Z
description: By Blake Iwaisako
---
<!--StartFragment-->

# Obstacle Avoidance Robot

EnVision Maker Studio

## Description:

Build a rover vehicle that drives straight until it encounters an object that it must detect and drive away from (Like a small Roomba!). This project can be made using a microcontroller of your choice, in this example I will use an Arduino Uno combined with an Adafruit motor shield. This document will also be covering the basics of ultrasonic sensors as it is used for detecting objects within a specified distance. 

## Process:

1. Design Chassis in Solidworks to be 3D printed

   * Create assembly complete with housing for all electronic components
2. Learn how to drive the motors and use the sweeping ultrasonic function
3. Assemble and test robot

   * Fine-tune motors to drive in a straight line

Typical Final Assembly of Robot (just to get an idea of where you’re headed):

![](/images/finalproduct.jpg)

Designing the chassis in SolidWorks:

Depending on the type of drive system you want (2-wheel or 4-wheel drive), create a new SolidWorks part that will house your motor, micro servo, Arduino Uno, Adafruit Motor Shield, and battery pack.

Here are some examples that are not finished but may give you some ideas:

**2-wheel continuous servo chassis (basic)**

![](/images/badchassis1.jpg)

![](/images/badchassis1-2.jpg)

**2-wheel larger chassis with battery storage**

![](/images/badchassis2-2.jpg)

![](/images/badchassis2.jpg)

## Arduino and Adafruit Motor Shield:

Refer to the official [website](https://learn.adafruit.com/adafruit-motor-shield-v2-for-arduino/install-headers) for more detailed information

* Ensure you have the Arduino [IDE](https://www.arduino.cc/en/software) installed
* In the IDE make sure you also install the [library](https://learn.adafruit.com/adafruit-motor-shield-v2-for-arduino/install-software) (Link to V2 library)

This is everything you will need to include in this project at the top of the Sketch:

```
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
#include <Servo.h>
```

## Driving the Motors

For this project, you have to learn to drive servo motors and/or dc motors. Luckily the Adafruit Motor shield makes it very simple to code because of the installed Arduino library. The below diagram shows the locations where you will connect your dc motors. 

The direction of the motors will depend on the orientation of the wires connected to the motor shield.

**Note**: if you are using continuous rotation servo motors for this project be aware that the motor shield only has slots for two servos in the top left.

![](/images/afms.png)

The code below shows how to initialize each motor you're using including the ultrasonic sweep servo. You can place this code block before the void setup. 

```
Adafruit_MotorShield AFMS = Adafruit_MotorShield();  //Initializes Motor Shield

Adafruit_DCMotor *RFrontMotor = AFMS.getMotor(4);  //Each number corresponds to Motor Shield
Adafruit_DCMotor *RBackMotor = AFMS.getMotor(3);   //refer to diagram above
Adafruit_DCMotor *LBackMotor = AFMS.getMotor(2);
Adafruit_DCMotor *LFrontMotor = AFMS.getMotor(1);

Servo sweepServo;
```

In the setup block, you will want to set the default speed of the motors and attach the servo to a pin (9 or 10).  The 'run' function described below is also how you will drive the dc motors (RELEASE, FORWARD, and BACKWARD). Servo 1 corresponds to pin value 9 and Servo 2 corresponds to pin value 10. 

```
void setup()
{
  AFMS.begin();
  RFMotor->setSpeed(motorSpeed);        //Set motor speed value (70 to 90 should work)
  LFMotor->setSpeed(motorSpeed); 
  RBMotor->setSpeed(motorSpeed);
  LBMotor->setSpeed(motorSpeed);

  RFMotor->run(RELEASE);                //Release all motors before void loop
  LFMotor->run(RELEASE);
  RBMotor->run(RELEASE);
  LBMotor->run(RELEASE);

  sweepServo.attach(10);
}
```

## Ultrasonic Sensor

Ultrasonic sensors emit sound waves at a very high frequency that humans cannot hear. These sound waves bounce off of objects and return to the sensor where a distance can be calculated based on the time it took the sound wave to return to the sensor. 

For a bit more information about ultrasonic sensors and how to implement them with Arduino check out this [article](https://www.arrow.com/en/research-and-events/articles/ultrasonic-sensors-how-they-work-and-how-to-use-them-with-arduino).

## Sweep Function

The ultimate goal of the ultrasonic sensor sweep function is to first detect an object in front of the robot and then determine the best direction for the robot to proceed forward in. Thus when an object is detected within the safe space of the robot:

![](/images/roverradius.jpg)

## Sweep Function Testing

Use this section to test out how to code the ultrasonic sensor and implement it with the arduino and microservo. The annotated code below shows which pins to connect to on the board (ensure the vcc pin is connected to 5V) as well as how each block works.

```
// Blake Iwaisako
// 11 August 2022

#include <Servo.h>

Servo sweepServo;

const int trig = 12;  // Trig pin 
const int echo = 13;  // Echo pin
int pos = 0;          // Initial position integer
long dur;             // Initialize long variables: duration of ultrasonic pulse 
long tocm;            // microseconds to cm variable
bool returningToZero; // Create boolean for returning to zero

void setup() {
  Serial.begin(9600);        // Connect to serial monitor
  pinMode(echo, INPUT);      // echo pin corresponds to "echo" on Ultrasonic Sensor
  pinMode(trig, OUTPUT);     // "trig" pin on sensor
  sweepServo.attach(9);
  sweepServo.write(0);
}

bool objectDetected(long tocm)    // Create boolean to detect object 
{
  if (tocm < 20)     // Any objects within 20 cm will be noticed
  {
    return true;
  } else {
    return false;
  }
}

void loop()
{
  digitalWrite(trig, LOW);    // Momentarily turns off trigger
  delayMicroseconds(2);       
  digitalWrite(trig, HIGH);   // Turn on trigger to send a pulse for 
  delayMicroseconds(10);      // 10 microseconds
  digitalWrite(trig, LOW);    // Turn off trigger 
  dur = pulseIn(echo, HIGH);      // Records ultrasonic pulse via the echo pin
  tocm = microsecondsToCentimeters(dur);    // Determine in cm distance of object based on pulse duration
  if (objectDetected(tocm))       // If variable tocm is within 20 cm threshold
  {
    Serial.print("Object detected. Object's distance: ");   // This block prints out the distance of the detected object
    Serial.print(tocm);                                     // and the angle of the servo in which the object was found
    Serial.print(". Servo's angle: ");                      // this stops the servo from sweeping as long as the object is seen
    Serial.println(pos);
  } else {
    if (pos < 180 && returningToZero == false)    // This block rotates the servo in intervals of 10cm back and forth
    {
      sweepServo.write(pos);
      pos += 10;
      Serial.print("Searching for object. Servo's angle: ");
      Serial.println(pos);
      if (pos == 180)                   // When the servo reaches the maximum angle 180 it returns to zero
        returningToZero = true;
    } else if (returningToZero == true) {
      pos -= 10;
      Serial.print("Searching for object. Servo's angle: ");
      Serial.println(pos);
      sweepServo.write(pos);
      if (pos == 0)                    // When the servo reaches minimum angle it returns to zero
        returningToZero = false;    
    }
  }
  delay(200);
}

long microsecondsToCentimeters(long microseconds)   // Converter for microseconds to cm
{
  return microseconds / 29.155 / 2;
}
```



<!--EndFragment-->