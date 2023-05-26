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

T﻿he Web Server project is simple and gets you familiar with the capabilities of the ESP32. A WiFi web server on the ESP32 creates an IP address that allows you to access the board's client from a browser connected to the same network. In this tutorial, we will use the web server to turn off/on two LEDs powered by GPIO 27 and 26. This is quick project is also helpful for showing you how to upload code to the ESP32. 

![](/images/esp32_web_server_schematic.webp)

Upload the following code to the ESP32 but with a few changes. You need to type in your SSID and Password for your home network, this will not work on protected networks like UCSD_PROTECTED or UCSD Guest since you need further verification. Using a hotspot on your phone is another option that works. 

```
/*********
  Rui Santos
  Complete project details at http://randomnerdtutorials.com  
*********/

// Load Wi-Fi library
#include <WiFi.h>

// Replace with your network credentials
const char* ssid = "REPLACE_WITH_YOUR_SSID";
const char* password = "REPLACE_WITH_YOUR_PASSWORD";

// Set web server port number to 80
WiFiServer server(80);

// Variable to store the HTTP request
String header;

// Auxiliar variables to store the current output state
String output26State = "off";
String output27State = "off";

// Assign output variables to GPIO pins
const int output26 = 26;
const int output27 = 27;

// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0; 
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;

void setup() {
  Serial.begin(115200);
  // Initialize the output variables as outputs
  pinMode(output26, OUTPUT);
  pinMode(output27, OUTPUT);
  // Set outputs to LOW
  digitalWrite(output26, LOW);
  digitalWrite(output27, LOW);

  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop(){
  WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {                             // If a new client connects,
    currentTime = millis();
    previousTime = currentTime;
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected() && currentTime - previousTime <= timeoutTime) {  // loop while the client's connected
      currentTime = millis();
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            
            // turns the GPIOs on and off
            if (header.indexOf("GET /26/on") >= 0) {
              Serial.println("GPIO 26 on");
              output26State = "on";
              digitalWrite(output26, HIGH);
            } else if (header.indexOf("GET /26/off") >= 0) {
              Serial.println("GPIO 26 off");
              output26State = "off";
              digitalWrite(output26, LOW);
            } else if (header.indexOf("GET /27/on") >= 0) {
              Serial.println("GPIO 27 on");
              output27State = "on";
              digitalWrite(output27, HIGH);
            } else if (header.indexOf("GET /27/off") >= 0) {
              Serial.println("GPIO 27 off");
              output27State = "off";
              digitalWrite(output27, LOW);
            }
            
            // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style the on/off buttons 
            // Feel free to change the background-color and font-size attributes to fit your preferences
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #4CAF50; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #555555;}</style></head>");
            
            // Web Page Heading
            client.println("<body><h1>ESP32 Web Server</h1>");
            
            // Display current state, and ON/OFF buttons for GPIO 26  
            client.println("<p>GPIO 26 - State " + output26State + "</p>");
            // If the output26State is off, it displays the ON button       
            if (output26State=="off") {
              client.println("<p><a href=\"/26/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/26/off\"><button class=\"button button2\">OFF</button></a></p>");
            } 
               
            // Display current state, and ON/OFF buttons for GPIO 27  
            client.println("<p>GPIO 27 - State " + output27State + "</p>");
            // If the output27State is off, it displays the ON button       
            if (output27State=="off") {
              client.println("<p><a href=\"/27/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/27/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
            client.println("</body></html>");
            
            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}
```

### U﻿ploading to the ESP32





























F﻿irst you will want to choose the correct board you will be uploading to. In my case I will be using the ESP32 Wrover Module.

![](/images/esp32-arduino.png)