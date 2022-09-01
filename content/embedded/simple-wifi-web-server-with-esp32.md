---
title: "IR Beam Breaker with a Simple WiFi Web Server (ESP32) "
date: 2022-08-29T21:24:15.480Z
description: By Blake Iwaisako
---
## Description

The IR beam break system can be used for many applications including security and data collecting. Whenever a person or object is detected (when the IR beam is broken) the instance will be logged on the ESP32 alongside the time the instance took place. The ESP32 will also be capable of sending you emails whenever a beam break occurs or after a certain period of time. By connecting to the server via IP address, a second party can see the full log of instances recorded In this project, we will learn how to use IR beam break sensors, create a webserver using the ESP32, attain the current time from an NTP server, and send email notifications using SMTP.



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

## WiFi Web Server

A WiFi web server on the ESP32 creates an IP address allowing you to access the board's client from a browser connected to the same network. 

Go through the entirety of [this tutorial](https://randomnerdtutorials.com/esp32-web-server-arduino-ide/) to understand how to create a WiFi server on the ESP32 and edit a webpage using HTML. The tutorial shows you how to control GPIO pins 26 and 27 via a web server that can be accessed using an IP address. 

 I have created an edited version of the code to control a servo motor using a library by Kevin Harrington called `ESP32Servo.h`. It will be important to learn how the code works so become familiar with the WiFi Client coding procedure. 

```
/*********
  Rui Santos
  Complete project details at http://randomnerdtutorials.com
*********/
// Edited By Blake Iwaisako to control a Servo motor 
// Include ESP32 Servo Library by Kevin Harrington
// Load Wi-Fi library

#include <WiFi.h>
#include <ESP32Servo.h>

// Replace with your network credentials
const char* ssid = "replace with your ssid";
const char* password = "replace with your password";

// Set web server port number to 80
WiFiServer server(80);
Servo myservo;

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
  myservo.attach(26);
  myservo.write(130);
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

void loop() {
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
              output26State = "closed";
              myservo.write(60);
            } else if (header.indexOf("GET /26/off") >= 0) {
              Serial.println("GPIO 26 off");
              output26State = "open";
              myservo.write(130);
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
            client.println(".button2 {background-color: #416664;}</style></head>");

            // Web Page Heading
            client.println("<body><h1>GPIO 26 & 27</h1>");

            // Display current state, and ON/OFF buttons for GPIO 26
            client.println("<p>GPIO 26 - State " + output26State + "</p>");
            // If the output26State is off, it displays the ON button
            if (output26State == "open") {
              client.println("<p><a href=\"/26/on\"><button class=\"button\">Close</button></a></p>");
            } else {
              client.println("<p><a href=\"/26/off\"><button class=\"button button2\">Open</button></a></p>");
            }

            // Display current state, and ON/OFF buttons for GPIO 27
            client.println("<p>GPIO 27 - State " + output27State + "</p>");
            // If the output27State is off, it displays the ON button
            if (output27State == "off") {
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



## IR Beam Break

Full tutorial [here](https://learn.adafruit.com/ir-breakbeam-sensors/arduino).

This code is bare bones but you can use it to understand how the IR beam break sensor works and how you can integrate parts of it with the WiFi web server. This code simply shows whether or not the IR beam is broken and when it does break a connected LED will blink. 

```
// from Adafruit edited by Blake Iwaisako

#define LEDPIN 27
#define SENSORPIN 14

int sensorState = 0;
int lastState = 0;

void setup() {
  pinMode(LEDPIN, OUTPUT);
  pinMode(SENSORPIN, INPUT);
  digitalWrite(SENSORPIN, HIGH);
  Serial.begin(115200);

}

void loop() {
  sensorState = digitalRead(SENSORPIN);
  if (sensorState && !lastState){
    Serial.print("Unbroken");
  }

  if (!sensorState && lastState) {
    Serial.print("Broken");
    digitalWrite(LEDPIN, HIGH);
    delay(100);
    digitalWrite(LEDPIN, LOW);
  }
  lastState = sensorState;
}
```



## NTP Server

Full tutorial [here](https://randomnerdtutorials.com/esp32-ntp-client-date-time-arduino-ide/)

Network Time Protocol is used to sync your computers to the current time using the internet. An ESP32 with WiFi capabilities can access this and attain the current time. To do this you will NEED to download and install a separate library called `NTPClient.h` which can be found in the full tutorial. 

Below I have pasted a slightly edited version of the code found on the full tutorial:

{{< tip >}}
For PST set the time offset value to -25200.
{{< /tip >}}

```
/*********
  Rui Santos
  Complete project details at https://randomnerdtutorials.com
  Based on the NTP Client library example
*********/

#include <WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

// Replace with your network credentials
const char* ssid     = "REPLACE_WITH_YOUR_SSID";
const char* password = "REPLACE_WITH_YOUR_PASSWORD";

// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

// Variables to save date and time
String formattedDate;
String dayStamp;
String timeStamp;

void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);
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

// Initialize a NTPClient to get time
  timeClient.begin();
  // Set offset time in seconds to adjust for your timezone, for example:
  // GMT +1 = 3600
  // GMT +8 = 28800
  // GMT -1 = -3600
  // GMT 0 = 0
  timeClient.setTimeOffset(-18000);
}
void loop() {
  while(!timeClient.update()) {
    timeClient.forceUpdate();
  }
  // The formattedDate comes with the following format:
  // 2018-05-28T16:00:13Z
  // We need to extract date and time
  formattedDate = timeClient.getFormattedDate();
  Serial.println(formattedDate);

  // Extract date
  int splitT = formattedDate.indexOf("T");
  dayStamp = formattedDate.substring(0, splitT);
  Serial.print("DATE: ");
  Serial.println(dayStamp);
  // Extract time
  timeStamp = formattedDate.substring(splitT+1, formattedDate.length()-1);
  Serial.print("HOUR: ");
  Serial.println(timeStamp);
  delay(1000);
}
```



## SMTP Server

Full tutorial [here](https://randomnerdtutorials.com/esp32-send-email-smtp-server-arduino-ide/#:~:text=In%20the%20Select%20app%20field,or%20ESP8266%20to%20send%20emails.)

Simple Mail Transfer Protocol is used by mail servers such as Gmail, Outlook, Yahoo, etc. to send and receive emails. 

{{< tip "warning" >}}
You will encounter a problem if you use your UCSD email since it requires a second login (SSO)
{{< /tip >}}



## Putting it All Together