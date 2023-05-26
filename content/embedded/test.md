---
title: CurtainMote
date: 2023-06-18T06:59:00.000Z
description: Looking for a way to add more convenience to your life? We've got
  just the thing! With our device, you'll be able to open and close your
  curtains with ease, without even leaving your seat.
---
## Details

T﻿he CurtainMote uses a WiFi web server hosted on an ESP32 microcontroller that connects to your home WiFi. The curtain-pulling mechanism uses a nearly invisible fishing line that runs along the length of the curtain rod in both directions, refer to the gif below:

![](/images/youtube-video-gif.gif)

https://www.electromaker.io/project/view/alexa-curtain-control-system-3d-printable-and-low-cost

T﻿his requires the use of a motor to pull the string forward and backward thus opening and closing your curtains.

## S﻿imilar Solutions (booooo)

![](/images/switchbot-curtain-hero.webp)

T﻿he SwitchBot ($99 retail) is a similar solution that works on all ring-based curtains and rods. It works by simply running along the rod and between the first and second curtain loops. 

## P﻿arts Needed

* E﻿SP32 or ESP8266 microcontroller (In this tutorial I used the ESP32)
* 1﻿2 Volt Power Supply
* B﻿raided Fishing Line ~30 lbs (used for pulling curtains)
* A﻿4988 stepper motor driver
* G﻿eared Stepper Motor
* 1﻿00 microF capacitor
* J﻿umper Wires
* Z﻿ip Ties

## G﻿etting started with the ESP32

F﻿or this project we will be programming the ESP32 microcontroller with the Arduino IDE. However, you must tell the IDE how to write to code to the ESP32 since it differs from a typical Arduino controller. First, you have to install the ESP32 library into the Arduino IDE. Follow [this one-minute video for the steps on how to do this.](https://www.youtube.com/watch?v=mBaS3YnqDaU)

Here is the link to the library that you paste into the "Additional Board Manager URLs" field.

```
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json

```

## A﻿ Simple WiFi Web Server (optional)

T﻿he Web Server project is simple and gets you familiar with the capabilities of the ESP32. A WiFi web server on the ESP32 creates an IP address that allows you to access the board's client from a browser connected to the same network. In this tutorial, we will use the web server to turn off/on two LEDs powered by GPIO 27 and 26.  

![](/images/esp32_web_server_schematic.webp)