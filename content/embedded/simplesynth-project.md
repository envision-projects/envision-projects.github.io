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

## **PART 1: PCB/Schematic Creation**

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

## **PART 2: PCB Creation**

This is the first part of the project where you get to be creative. I won't go into step-by-step detail describing this part of the project once we get the parts into the PCB, but rather talk about some best practices and general considerations. The rest will be up to the user to decide the aesthetics of their board.

1. While in the schematic document, press d, then u. (For Design, Update PCB Document)
2. In the pop-up dialogue, validate the changes, then execute the changes. Close the windows.
3. Now go to the PCB document. If you properly created all your nets and schematic symbols, you should now see all of your components laid out in a row next to a blank slate. It should look something like this:

   ![](/images/updatepcb.png)

   We now need to determine what our PCB will look like. Before we even decide how large our board will be, we need to get a general idea of what our component placement will be. Drag the components into the black area of the page to place them on the PCB area. Keep in mind that the switches should be close to their associated resistors. You also want to place the MUX chip between the switches and the Teensy. Something like this: 

   ![](/images/ss_pcb1.png)
4. Now connect all the nets with wires. I typically use 9mil traces for signals, and 15 - 21mil traces for power connections.
5. Before we determine our board size, we want to make sure everything will (at least for now) fit. Remember that the audio shield will be on the Teensy, and that it is significantly wider than its parent board. So that we get an idea of its size, I have created an outline for it on the Top Overlay layer, using the line tool. The Audio board is approximately 3.9mm x 3.9mm and isn't seated in the middle of the Teensy, but rather is a bit off center: 

   ![](/images/audioshielddim.png)
6. Now we know the general size of our board (but keep in mind that we'll be adding more components as we go so leave some space). Create a polygon pour around your components. A simple rectangle is fine. Add the polygon to the GND net. 
7. On layer Mechanical 15, create a box around your polygon pour using the line tool.
8. While still on layer Mechanical 15, press e, s, y, then d, s, s (Edit, Select, All on Layer, Design, Board Shape, Define Board Shape).
9. Next we want to create mounting holes for our board. This isn't absolutely necessary, but it's a good habit to get into (trust me). Create a via that is 4mm with a 3mm hole. Copy and paste this so there's one in each corner. We should now have something like this: 

   ![](/images/ss_pcb2.png)

### Next Steps -------

**Adding Controls and Effects**

Now we have a board that connects our 13 keys to the Teensy through a multiplexer. By using a multiplexer, we saved pins on the Teensy because all 13 keys are now routed into one pin. We are using 4 pins on the Teensy to control the multiplexer, for a total of 5 pins (which is less than 13 = more pins available on the Teensy). Why do we want more pins? Because we want to control aspects of the sound with things like potentiometers (pots). We also want to be able to change oscillator waveforms manually, and therefore need a button or two or three. Now is a good time to decide which effects and controls we want, and the types of physical hardware that will control them. 

We're going to have 3 oscillators to generate our waveforms, and we want to cycle through available waveshapes, so we need 3 buttons. We will also want to mix the volumes of the oscillators, so we'll need 3 pots. We're going to have a filter, so we'll need controls for frequency and resolution, and a way to switch between low-pass, high-pass, and band-pass filters. That's two more pots and a button. Then we want to add a delay effect, which typically includes controls for time, feedback, and mix; 3 more pots. Lastly, we will add note envelope controls, or attack, decay, sustain, and release (ADSR) for four more pots. Thus we have a total of 12 pots and 4 buttons. Let's go!

1. Back in our SimpleSynth schematic, we need to add potentiometers.

{{< tip >}}




1. We don't need a part-specific symbol or footprint, as we just need solder connections for the wires that will connect to the components. Another approach would be to mount these components directly to the board, but that is a slightly more involved process that necessitates a good deal more up-front planning. In order to keep things simple and flexible, we're just going to use wires to connect parts to the board.




{{< /tip >}}

I just made a very basic three-pin symbol and a footprint with standard 4mm x 3mm holes, 2mm spacing.

![](/images/pot.png)

![](/images/potfoot.png)

2. Once you've made your symbol and footprint, place them in the schematic. I placed mine in such a way that they are grouped together according to their function. Add net labels to denote the component's function.

![](/images/controls.png)

3. Once you've placed and labelled your pots and switches, add corresponding net labels to the Teensy. Best practice is to group similar functions together where possible. You should now have something akin to this:

![](/images/ss_schematic3.png)

4. Now we need to add our new parts to the PCB. Update the PCB from the schematic as we did before, and place the new components on the board. You will ( most likely ) need to move things around on your existing PCB, and possibly extend it. 

   {{< tip >}}


   As you layout your board, you'll often find yourself making changes that facilitate easier routing. One of the things I did was to reorder the last 5 pins on the MUX so that I wouldn't have to cross too many wires while routing.


   {{< /tip >}}

   ![](/images/rerouting.png)
5. Route all your traces. 
6. Lastly, we're going to add some filtering capacitors to the potentiometers. This will greatly reduce the amount of noise in our circuit and allow for cleaner, more stable readings on our analog inputs. Choose a 0805 capacitor from the Manufacturer Part Search, and change the value to "0.1uF" in its comment.
7. Copy and paste the capacitor so that there is one connected to the 3.3v pin on every potentiometer. Connect the other leg of the capacitor to GND. Don't forget to annotate the schematic so the caps have numbered designators. Now it should look something like this:

   ![](/images/ss_caps.png)
8. Update your PCB document.
9. Place all the caps to their associated pots.
10. Route traces between the caps and pots. 
11. Finishing up: You can now customize your board further by adding text, labels, and things like that. It's a good idea to arrange the component designators so they face the same way and are legible.

{{< tip >}}
Best Practices: It's generally a good idea to place "stitching vias" around your board to connect the top and bottom GND planes. You don't need a lot of them on a board without too many complicated signals, but they help with signal stability.
{{< /tip >}}



And we're done with the circuit board portion of the project! You should now have something that looks like this: 

![]()

4.

<!--EndFragment-->