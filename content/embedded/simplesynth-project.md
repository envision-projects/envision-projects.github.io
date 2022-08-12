---
title: SimpleSynth Project
date: 2022-08-12T03:10:54.038Z
description: A Teensy 4.1-based synthesizer
---
<!--StartFragment-->

The SimpleSynth is a Teensy-based audio synthesizer. We will be building an expansion board for the Teensy, as well as an enclosure for the boards and controls (switches, buttons, potentiometers, etc…) and then programming the synthesizer using the Arduino IDE and the Audio System Design Tool for the Teensy Audio Library. While the final product represented here is fully functional, it is also very expandable, and users are encouraged to explore ways of doing so by adding various effects, controls, displays, etc…

Our Microcontroller of choice for this project is the Teensy 4.1:

 <https://www.pjrc.com/store/teensy41.html>

…which we will use with the Teensy Audio Board:

** <https://www.pjrc.com/store/teensy3_audio.html>**

![](/images/teensy4.1.png)

![](/images/teensyaudioboard.png)

{{< tip >}}






(A small plug for Teensy - the Teensy series of ARM-based microcontrollers is AWESOME and very powerful and easy to use. There is also a great community of Teensy users, led by the main developer, PJRC: https://www.pjrc.com/ There is also an incredibly useful and helpful forum for troubleshooting and general problem solving help: https://forum.pjrc.com/ )






{{< /tip >}}

The final synthesizer will have the following:

* Full octave ( C - C ) keyboard
* 3 oscillators of variable waveshapes
* Digital filter with parameter controls
* Digital delay with parameter controls

In order to build the synthesizer,

1. We will create and design our circuit board in Altium Designer
2. We will design our enclosure using Adobe Illustrator and Makercase.com
3. We will source and purchase parts from Digikey.com
4. We will program the synthesizer using the Teesny Audio System Design Tool, the Teensy Audio Library, and Arduino IDE

**PART 1: PCB/Schematic Creation**

1. Create a new project in Altium and call it SimpleSynth
2. Add a new schematic document to the project, followed by a new PCB document, both named SimpleSynth
3. The primary component of our circuit board will be the Teensy 4.1, so we need to either create our own schematic symbol and footprint, or download one from SnapEDA.com: 
4. [Teensy4.1 Design Files](https://www.snapeda.com/search/?q=Teensy+4.1&SEARCH=Search&sort=&resistance=&tolerance=&search-type=parts) ( I created my own schematic and footprint, so if you download them, yours may look different )
5. The next component we’ll need is the Texas Instruments CD74HC4067M, which is a 16-channel Multiplexer/demultiplexer. ( The MUX/DeMUX chip is what we’ll use for the extra digital inputs we need for the 12 keys on the keyboard )
6. Unlike the Teensy, we can find this chip by using the Manufacturer Part Search in Altium. Just paste the part number in the search dialog and choose the first part that comes up. ( verify that this is the SMD version of the chip and not the through hole version )
7. Now we need an LED and a resistor which will serve as our power indicator. Use the Manufacturer Part Search to find “LED 0805” and “resistor 0805” and place both components. Change the resistor’s comment to “560R” (560 Ohms)
8. Add a GND port to all GND pins and pin 2 of the LED.
9. Connect a Power Port to VCC and 3.3v pins, as well as pin 1 of the resistor. Also connect it to the E pin of the MUX chip.
10. Connect Teensy pins D36, D35, D34, D33 to S0, S1, S2, S3 respectively on the MUX.

**You should now have approximately this:**

![](/images/ss_schematic1.png)

11. Now we need to add the switches that we’ll use for our keys. Use the MPS to find “SW-SPST” and place 13 of them.
12. Copy and paste the resistor. Change the value to 10k and then paste 12 more. Connect one to each switch.
13. Connect the open end of the switches to another 3.3v power port, and connect the open pin of the resistors to a GND port.

![](/images/ss_switches.png)

14. Now we should annotate our schematic, meaning, assign every component its own unique designator, which we will need to refer to in our PCB. To do this, press t a a. You will see this dialogue:

    ![](/images/annotattion.png)

    Press "Update Changes List", then press "OK", Press "Accept Changes." When the net dialogue opens, press "Execute Changes." Once finished, you can close those the annotation windows.
15. Now we need to create our Nets: the Nets will connect the switches to the MUX inputs, and we need one per note on our keyboard. Connect wires to the conjunction of the switches and resistors:

    ![](/images/switchesnets.png)

    and then add the same nets to the MUX:

    ![](/images/muxnets.png)
16. You should now have something that looks like this: 

    ![](/images/ss_scematic2.png)

    And Now we're done with the schematic. This is a very simple schematic; we don't need to add a lot of components because the Teensy handles all of our power conditioning, USB connection, and clocking. All we've really done is enable easy connections between our keys, the multiplexer, and the Teensy. Next we create the PCB layout.

**PART 2: PCB Creation**

This is the first part of the project where you get to be creative. I won't go into step-by-step detail describing this part of the project once we get the parts into the PCB, but rather talk about some best practices and general considerations. The rest will be up to the user to decide the aesthetics of their board.

1. While in the schematic document, press d, then u. (For Design, Update PCB Document)
2. In the pop-up dialogue, validate the changes, then execute the changes. Close the windows.
3. Now go to the PCB document. If you properly created all your nets and schematic symbols, you should now see all of your components laid out in a row next to a blank slate. It should look something like this:

   ![](/images/updatepcb.png)

   We now need to determine what our PCB will look like. Before we even decide how large our board will be, we need to get a general idea of what our component placement will be. Drag the components into the black area of the page to place them on the PCB area. Keep in mind that the switches should be close to their associated resistors. You also want to place the MUX chip between the switches and the Teensy. 

<!--EndFragment-->