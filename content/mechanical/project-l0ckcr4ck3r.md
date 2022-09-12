---
title: Project l0ckcr4ck3r
date: 2022-08-30T05:06:17.710Z
description: A fully Autonomous Lock Cracking Robot
---
By MingWei Yeoh

This is **not** for the faint of heart. This thing takes long and its hard to get right. Only for the advanced and over achievers.

PCB Files found [here](https://drive.google.com/drive/folders/1nlAPVdNwrT2d3gSRspbw5zdQGXfbqTga?usp=sharing).

Code found [here](https://github.com/Mew463/Project-l0ckcr4ck3r)

![](/images/ezgif.com-gif-maker-3-.gif)

**[Video](https://photos.app.goo.gl/QN5QXWd9ifFrNtgB6)**

# **About the Project**

This robot is a true creation of the idea many years ago brought on by Samy Kamkar's [robot ](https://samy.pl/combobreaker/)that "utilized" his [algorithm ](https://www.youtube.com/watch?v=09UgmwtL12c&ab_channel=samykamkar)for cracking these combination locks. The entire process works on the majority of locks that don't have much resistance on the dial and usually takes ~40 seconds. 

<!--StartFragment-->

![Master Lock 1500D, Preset Combination Padlock, 1-7/8 in. Wide, Black Dial](https://i5.walmartimages.com/asr/3c5ce2c7-0496-4d75-8dad-ce0944061b1f.0dc4627adae0b1df42f6cac6db78eafa.jpeg?odnHeight=612&odnWidth=612&odnBg=FFFFFF)

<!--EndFragment-->

## Specifications

The heart of the robot uses a TMC2208 super silent trinamic stepper driver w/ AS5600 mag encoder on the back to turn the lock dial and "feel" for the lock's geometries. A servo with analog output detects when a successful attempt was made to open the lock. Also added functionality which includes a GUI which is an oled + rotarary encoder for user input. The entire assembly is powered by a 12V USB C charger with a fan to cool down the stepper driver.

# Challenges

## PCB

Due to the sheer complexity of the mechanical aspect, you can just use the PCB files provided.

![](/images/screenshot-2022-08-30-111010.png)

## CAD

Will be doing the CAD from scratch! 

Mine ended up looking like this:

![](/images/l0ckcr4ck3r.png)

## Code

Due to the sheer complexity of the mechanical aspect and that my code is about 800 lines long, you can just use the code provided.

# Materials

## Mechanical

* [TMC2208 Stepper Driver](https://www.amazon.com/Printer-TMC2208-Screwdriver-Controller-Ramps1-4/dp/B082LSQWZF/ref=sr_1_3?crid=2DM8J6G3IDA8J&keywords=tmc2208&qid=1661839331&sprefix=tmc2208%2Caps%2C133&sr=8-3)
* [High torque servos](https://www.amazon.com/Youleke-Torque-Digital-Servo%EF%BC%8CWaterproof-Horn%EF%BC%88270%C2%B0%EF%BC%89/dp/B08739MGPL/ref=sr_1_11?crid=81HZZ5JLGLML&keywords=servo&qid=1661839358&sprefix=servo+%2Caps%2C248&sr=8-11)
* [Stepper motor](https://www.amazon.com/STEPPERONLINE-Bipolar-Stepper-22-6oz-Extruder/dp/B00PNEQ79Q/ref=sr_1_6?crid=1U1NH4LQTF0ZK&keywords=stepper+motor&qid=1661839383&sprefix=stepper+motor+%2Caps%2C139&sr=8-6)
* [AS5600 Magnetic Encoder](https://www.amazon.com/Magnetic-Encoder-Induction-Measurement-Precision/dp/B094F8H591/ref=sr_1_4?crid=M8OANSRLFX5C&keywords=as5600+encoder&qid=1661839450&sprefix=as5600+encod%2Caps%2C130&sr=8-4)
* Assorted M3 Bolts

## Electrical

* Arduino Nano
* 10uF Capacitor x2
* Diode 
* [5V Regulator](https://www.digikey.com/en/products/detail/stmicroelectronics/LD1085V50/669220?s=N4IgTCBcDaIDIBECMAGAHAVgGoZSAugL5A)
* [OLED Display](https://www.amazon.com/Self-Luminous-Display-Compatible-Arduino-Raspberry/dp/B09JWN8K99/ref=sr_1_2_sspa?crid=DM9HX86FS3Q5&keywords=oled+arduino&qid=1661839948&sprefix=oledarduino%2Caps%2C143&sr=8-2-spons&psc=1)
* [Rotary Encoder](https://www.amazon.com/Taiss-KY-040-Encoder-15%C3%9716-5-Arduino/dp/B07F26CT6B/ref=sr_1_4?keywords=rotary+encoder&qid=1661839976&sprefix=roataray%2Caps%2C139&sr=8-4)
* [Blower Fan](https://www.amazon.com/WINSINN-Bearings-Brushless-Cooling-40mm20mm/dp/B08R9JJZ5Z/ref=sr_1_8?crid=1UCHGY2B410VX&keywords=blower+fan+12v+40mm&qid=1661839541&sprefix=blower+fan+12v+40m%2Caps%2C119&sr=8-8)
* [USB C 12V ](https://www.amazon.com/MELIFE-Type-C-Voltage-Trigger-Module/dp/B0953G14Q2/ref=sr_1_3?crid=12XVP47XQI63X&keywords=usb+c+12v+trigger&qid=1662871099&sprefix=usb+c+12v+trigge%2Caps%2C227&sr=8-3)
* [Power Supply](https://www.amazon.com/ZMI-zPower-Turbo-Power-Adapter/dp/B07D64QLQ1/ref=sr_1_5?crid=3I0WTX44C53G1&keywords=usb+c+charger+pd&qid=1662871140&sprefix=usb+c+charger+%2Caps%2C244&sr=8-5)

# Background information

This robot takes advantage of Samy Kamkar's exploit. I reccomend watching this [video](https://www.youtube.com/watch?v=27rE5ZvWLU0&t=647s&ab_channel=HelpfulLockPicker) if you are actually going to build this. You absolutely need to understand what the robot is trying to do under the hood or else there's no way you can debug anything.

# The plan

First we are going to make the housing for the lock, sensor, and actuators. After that works, then we will make an enclosure for the electronics 

# Getting Started

This [document ](https://cad.onshape.com/documents/2de7a66597cc8eb251afdfa3/w/06d4fc68ebc18f9b44e9861d/e/d088818cff71281e0c0d79ce?renderMode=0&uiState=630e4bb71c174454be9985ae)includes all of the standard content needed. You can either work in Onshape (reccomended) or export the content to use in Solidworks

# CAD

## Motor -> Lock Dial

![](/images/l0ckcr4ck3r-1-.png)

Now it is your job to make pieces to hold the motor in place to the lock dial.

Make a part to hold the lock and the stepper motor in place. Ensure that the stepper motor's shaft is cocentric with the lock dial. 

Use the mounting points of the stepper motor to fasten it onto your main part. The lock can be friction fit to the part. 

The coupler from the stepper motor shaft to the lock dial has already been provided since it is hard to get the geometry right.

![](/images/l0ckcr4ck3r-3-.png)

After you have made all the parts, ensure that they work well in an assembly together.

## Motor Encoder

![](/images/l0ckcr4ck3r-2-.png)

Now you need to attach the AS5600 Magnetic encoder to the back of the stepper motor! Make a part that attaches to the back of the motor and then simply have the magnetic encoder screw into that part. 

## Shackle puller

Next, make a rack and pinion gear that attaches to the servo to pull up (as well as push in) on the shackle. Try to make a design similar to the gif below

![](/images/ezgif.com-gif-maker.gif)

## Electronics

Make an electronics enclosure that has space for the custom PCB, USB C input, and blower fan. Ensure that the blower fan is pointing directly at the stepper driver or else it may overheat. 

Make sure to have opening for the usb connections and secure all the components with M3 fasteners. 

Then make points to put the OLED display as well as the rotary encoder. 

![](/images/screenshot-2022-09-01-232428.png)

# Analog Output Servo modification

In order to determine whether the lock actually opened or not without an extra sensor, we are going to "hack" our servo and turn it into one with an analog feedback. 

To do this, you will need to unscrew the servo and solder a wire to the center potentiometer pin on the outside. You can also follow this video on [youtube](https://www.youtube.com/watch?v=XfZLtkr6dgU&ab_channel=CuriousMotor) to learn more about the process.

You may have to drill a hole in the casing of the servo in order to have the analog output wire come out of it. 

![](/images/screenshot-2022-09-10-232014.png)

# Electronics

Solder the correct electronic components to the PCB in accordance with the picture below. I would highly reccomend attaching the female dupont pins so that you can easily disconnect things.

Be sure to attach the Input pad to the USB C trigger module with the right polarity! 

![](/images/screenshot-2022-08-30-111010.png)

![](/images/mvimg_20220823_125722.jpg)

Afterwards, go ahead and wire the stepper motor and the magnetic encoder to their corresponding inputs. Also plug in the servo with it's analog output to the correct port. Be sure to glue the diametric magnet to its mount and glue the mount to the shaft of the stepper motor.

## Testing the stepper motor / magnetic encoder

Ensure that the stepper motor works by running a basic Stepper motor sketch. Remeber that the stepper motors are dead silent thanks to the TMC2208 silent stepper driver.

Now make sure that the AS5600 magnetic encoder is reading properly. Run a basic example sketch. It's value should change whenever you rotate the motor. 

## Testing the servo

Run servo_setup.ino. Try changing the position of the servo by typing a number value between 1000-2000.

# Calibration things

Should be done after all the mechanical aspects are finished!

## Servo values

Run servo_setup.ino. Try changing the position of the servo by typing a number value between 1000-2000.

Use this script to find the upper and lower bounds that the servo will need to move. 

Lower bound - Lock is fully open

Upper bound - Lock is fully closed (shackle fully pushed into the lock)

![](/images/servotinkering-2-.png)

## Calibrating magnet offset

Run a AS5600 sketch that runs the readAngle() command.

Set the lock dial to zero and read what the readAngle() command is outputting. Input that value into the offset variable for the combobreaker.ino file 

![](/images/screenshot-2022-09-12-001748.png)

## Checking readLockDial()

In combobreaker.ino run the readLockDial() function to determine whether you are correctly reading the current number that the lock is at. If it seems like the numbers are going in the opposite direction when you are rotating the dial, change the setDirection function. 

![](/images/screenshot-2022-09-11-184840.png)

## Lock -> Motor coupler

The two bolts that clamp the two motor coupler parts together should be **loose**. The combination locks have a big amount of play in them and are a little ovalized. The looseness in the system helps to prevent the dial from becoming overconstrained and binding up and certain points in the lock dial.