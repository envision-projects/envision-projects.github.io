---
title: "IR Beam Breaker with a Simple WiFi Web Server (ESP32) "
date: 2022-08-29T21:24:15.480Z
description: By Blake Iwaisako
---
An infrared beam break sensor can be used for many applications such as 





For this project, I will be using an ESP32 microcontroller. The ESP32 is an amazing module that comes with integrated WiFi capabilities and can be programmed using the Arduino IDE. 

For this demonstration we will be using the ESP32 Wrover Module shown here:

![](/images/esp32.jpg)

## Installing the ESP32 Library on Arduino IDE

Follow this [step-by-step](https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/) guide to install the ESP32 library. You only need to install the library as the rest of the tutorial goes about testing the ESP32's WiFi capabilities, however, feel free to try this out. Just make sure you select the correct board from the "Board" menu. 

Here is the link to the library that you paste into the "Additional Board Manager URLs" field. 

```
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
```