---
title: Obstacle Avoidance Robot
date: 2022-08-09T20:54:50.949Z
description: By Blake Iwaisako
---
<!--StartFragment-->

Obstacle Avoidance Robot

EnVision Maker Studio

By Blake Iwaisako



Description:

Build a rover vehicle that drives straight until it encounters an object that it must detect and drive away from (Like a small roomba!). This project can be made using a microcontroller of your choice, in this example I will use an adruino uno combined with an adafruit motor shield. This document will also be covering the basics of ultrasonic sensors as it is used for detecting objects within a specified distance. 



Process:

1. Design Chassis in Solidworks to be 3D printed

   * Create assembly complete with housing for all electronic components
2. Learn how to drive the motors and use the sweeping ultrasonic function
3. Assemble and test robot

   * Fine tune motors to drive in a straight line



Typical Final Assembly of Robot (just to get an idea of where you’re headed):  

Designing the chassis in SolidWorks:

Depending on the type of drive system you want (2-wheel or 4 wheel drive), create a new SolidWorks part that will house you motor, microservo, Arduino Uno, Adafruit Motor Shield, and battery pack.



Here are some examples that are not finished but may give you some ideas:

2-wheel continuous servo chassis (basic)

![](https://lh3.googleusercontent.com/QUa5kcSGXqybcjlBATroENcibk0o9A5MHSOcygHN92iTsYzF6LXbTDvIWFDkR1GoOWACtlVsnmcWQE4e6vlh7ELdUntffnTNWY1mLymUsKuZmvT6AENYJqz1uxRo_ZBPr82uglqJNOTlQBkx2UEvmSw)![](https://lh5.googleusercontent.com/MtPdIPRBP9uiqS51unFyfMtUKHQxnBPrlJhJxbkbBji8Sa8UQ7uphCvfZ0QJtQzBmqrjTokrexZft2uAFVBzNG4-dzpMG4hOIArLF1roJWEPQlYjkG8mgrgpgFCppwSe4IhigHafEEYfbhO_Y9fgIYg)



2-wheel larger chassis with battery storage

![](https://lh6.googleusercontent.com/mCjprNsa5giAIavGmj7-M_Jra_CX9F-GpyWKmTP9HpAczZTNhpO5zFPuoRzzXxDAnDPZDzNzaR4o5mWsAiAXIZxVTUY6M0xxRQMe9SdM3SvLwP44VKeyVKBogLRyVLtdl4OCuY6sKs53bMax5gYY8RA)![](https://lh3.googleusercontent.com/FyQSoPgjV6PFhplUvuirSET-usJjmXPvcRgftJ0c29gm23RkDGDVMgGP-07xd9idX3O4ANhXhgaFh16qpzOs2mkHcVor29ED1cm1D1Lh0eDt22-2um_6HtvEnvxQ5yjS5qAXOCgQu_VCqiI7qvkpeaw)



Arduino and Adafruit Motor Shield:

Refer to the official [website](https://learn.adafruit.com/adafruit-motor-shield-v2-for-arduino/install-headers) for more detailed information

* Ensure you have the Arduino [IDE](https://www.arduino.cc/en/software) installed
* In the IDE make sure you also install the [library](https://learn.adafruit.com/adafruit-motor-shield-v2-for-arduino/install-software) (Link to V2 library)



This is everything you will need to include in this project at the top of the Sketch:

Q

\#include <Adafruit_MotorShield.h>

\#include "utility/Adafruit_MS_PWMServoDriver.h"

\#include <Servo.h>



Driving the Motors

For this project you have to learn to drive servo motors and/or dc motors. Luckily the Adafruit Motor shield makes it very simple to code because of the installed arduino library. The below diagram shows the locations of where you will connect your dc motors.

Note: if you are using continuous rotation servo motors for this project be aware that the motor shield only has slots for two servos.



![](https://lh6.googleusercontent.com/8HylD03WSCt404VnirUEsGrXIkWwfkVLUGEZ7_O64SoVuOkDe3eAdd-LtsU5_G9QxEReFuJQk_l_gK5dg8c67XLp6PTsaDuctiZN1xVmxe9k_6SOBkGWTazNOVZDwCvx3KQTZi6AJ1qYCj5VKIppGWk)



Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 



Adafruit_DCMotor *RFrontMotor = AFMS.getMotor(4);

Adafruit_DCMotor *RBackMotor = AFMS.getMotor(3);

Adafruit_DCMotor *LBackMotor = AFMS.getMotor(2);

Adafruit_DCMotor *LFrontMotor = AFMS.getMotor(1);



Helpful brief [article](https://www.arrow.com/en/research-and-events/articles/ultrasonic-sensors-how-they-work-and-how-to-use-them-with-arduino) describing how ultrasonic sensors work with arduino.



<!--EndFragment-->