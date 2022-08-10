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

**Note**: if you are using continuous rotation servo motors for this project be aware that the motor shield only has slots for two servos.

![](/images/afms.png)

```
Adafruit_MotorShield AFMS = Adafruit_MotorShield();  //Initializes Motor Shield

Adafruit_DCMotor *RFrontMotor = AFMS.getMotor(4);  //Each number corresponds to Motor Shield
Adafruit_DCMotor *RBackMotor = AFMS.getMotor(3);   //refer to diagram above
Adafruit_DCMotor *LBackMotor = AFMS.getMotor(2);
Adafruit_DCMotor *LFrontMotor = AFMS.getMotor(1);
```

Helpful brief [article](https://www.arrow.com/en/research-and-events/articles/ultrasonic-sensors-how-they-work-and-how-to-use-them-with-arduino) describing how ultrasonic sensors work with arduino.

<!--EndFragment-->