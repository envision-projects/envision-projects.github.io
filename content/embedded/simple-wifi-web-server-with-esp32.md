---
title: "IR Beam Breaker with a Simple WiFi Web Server (ESP32) "
date: 2022-08-29T21:24:15.480Z
description: By Blake Iwaisako
---
## Description

The IR beam break system can be used for many applications including security and data collecting. Whenever a person or object is detected (when the IR beam is broken) the instance will be logged on the ESP32 alongside the time the instance took place. By connecting to the server via IP address, a second party can see the full log of instances recorded In this project, we will learn how to use IR beam break sensors, create a webserver using the ESP32, and get the current time using an NTP server.



## IR Beam Break Sensors

An infrared beam break sensor has a very simple transmitter/receiver design. The transmitter is an infrared light that is invisible to the human eye making it ideal for low-profile security systems. The receiver detects infrared light and will output a signal if it is detected. 

These are Adafruit IR Beam Break Sensors that I will be using for this project.  

![](/images/2168_iso_orig_2021_05-scaled.jpg)

For this project, I will be using an ESP32 microcontroller. The ESP32 is an amazing module that comes with integrated WiFi capabilities and can be programmed using the Arduino IDE. 

For this demonstration we will be using the ESP32 Wrover Module shown here:

![](/images/esp32.jpg)

## Installing the ESP32 Library on Arduino IDE

Follow this [step-by-step](https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/) guide to install the ESP32 library. You only need to install the library as the rest of the tutorial goes about testing the ESP32's WiFi capabilities, however, feel free to try this out. Just make sure you select the correct board from the "Board" menu. 

Here is the link to the library that you paste into the "Additional Board Manager URLs" field. 

```
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
```