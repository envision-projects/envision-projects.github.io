---
title: BLYNK Wifi Tutorial
date: 2022-09-06T21:26:59.477Z
description: "Blynk IOT for home automation "
---
This is a tutorial for using BLYNK, an online service that is perfect for controlling IOT devices like the NodeMCU. This can give you full control of the microcontroller's GPIO pins regardless of where you are as long as you and the microcontroller are connected to the internet.

# Materials 

* [NodeMCU ](https://www.amazon.com/HiLetgo-Internet-Development-Wireless-Micropython/dp/B081CSJV2V/ref=sr_1_1_sspa?crid=1WQRMTWIB7OAO&keywords=nodemcu&qid=1662704836&sprefix=nodemc%2Caps%2C147&sr=8-1-spons&psc=1)
* LED
* Push Button

# Test Circuit 

We are going to make a simple test circuit to make sure the fundamentals are working 

![](/images/mvimg_20220908_232924.jpg)

It is a pushbutton attached between GND and D6 and an LED attached to D5

# Signing up 

Go to the [blynk website](https://blynk.io/) and make an account

Download the Blynk IOT app onto your phone and log in with your credentials 

# Making a new Project in Blynk software

## Create new template

1. On the mobile app, click on the wrench in the top right corner
2. Click on the three horizontal bars -> Add template
3. Name it whatever "envision tutorial"
4. Navigate back to the home page

## Creating a new device 

1. Click on the three horizontal bars in the main menu -> Add New device
2. Add a device manually
3. Select the envision tutorial template
4. Click on the wrench icon while inside of the widget menu to edit the GUI. Add a Button and a labeled display. 

# Uploading to ESP8266

## Getting your credentials 

Because BLYNK does not know what microcontroller you want to talk to, you need to assign the microcontroller a certain ID and authetnication token. To find this follow these steps: 

1. Go to blynk cloud on your computer
2. Navigate to your device that you want to find information on 
3. Click on Device Info and copy the section highlighted below

![](/images/screenshot-2022-09-08-234003.png)

Paste code into Arduino IDE editor. Be sure to install the required libraries. (FastLED and Blynk)

```
/*************************************************************

  You’ll need:
   - Blynk IoT app (download from App Store or Google Play)
   - ESP8266 board
   - Decide how to connect to Blynk
     (USB, Ethernet, Wi-Fi, Bluetooth, ...)

  There is a bunch of great example sketches included to show you how to get
  started. Think of them as LEGO bricks  and combine them as you wish.
  For example, take the Ethernet Shield sketch and combine it with the
  Servo example, or choose a USB sketch and add a code from SendData
  example.
 *************************************************************/

// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
// See the Device Info tab, or Template settings
#define BLYNK_TEMPLATE_ID ??
#define BLYNK_DEVICE_NAME ??
#define BLYNK_AUTH_TOKEN ??

// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "FastLED.h"

char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "wifi name";
char pass[] = "password";

const int LEDpin = D5;
const int buttonPin = D6;

void setup()
{
  // Debug console
  Serial.begin(115200);
  pinMode(BUILTIN_LED, OUTPUT);
  pinMode(LEDpin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  digitalWrite(BUILTIN_LED, LOW);
  Blynk.begin(auth, ssid, pass);  
  digitalWrite(BUILTIN_LED, HIGH);
}

BLYNK_WRITE(V1) // <- Pin that you would like to read from 
{
  // any code you place here will execute when the virtual pin value changes
  Serial.println("Blynk.Cloud is writing something to V1");
  int virtual_pin_value = param.asInt();
  if (virtual_pin_value)
    digitalWrite(LEDpin, HIGH);
  else
    digitalWrite(LEDpin, LOW);
}

void loop()
{
  Blynk.run();
  EVERY_N_MILLISECONDS(100) {
    if (!digitalRead(buttonPin))
      Blynk.virtualWrite(V9, "Button Pressed!");
    else
      Blynk.virtualWrite(V9, "Button Not Pressed!");
  }
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
}

```

Paste in your credentials that you copied at the top of the code. Also be sure to fill in your wifi name and password so that your NodeMCU will actually connect to the internet. 

If all goes well, you will see something like this in your Serial monitor to confirm that the microcontroller successfully connected to the internet!

![](/images/screenshot-2022-09-08-235847.png)





# Use cases

Wifi controlled garage door opener! 

What we've created is a very powerful remote that does not require any bluetooth connectivity or anything like that