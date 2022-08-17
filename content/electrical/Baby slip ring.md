---

title: 	 Slip Ring Project

date: 2022-07-20T00:15:38.963Z

description: A USB-C LED Light slip ring

---


# About the Project
We will be creating a pcb slip ring that lights up 2 LED lights with a USB C Connector!

Slip rings are devices that allow electrical contacts through rotating bodies. 

{{< figure src="/images/babyslipring/slipring.gif" width="350">}}

![](/images/babyslipring/cadslipring.gif)

Usually you would simply buy a slip ring, so the question remains, why reinvent the slip ring if it already exists? 

My excuse was that they're expensive. Most especially ones with a through hole in the center :(
![](/images/babyslipring/20220730140802.png)

Slip rings are a good way to practice PCB and CAD design. And they kinda cool too!! 

## Challenges
### Kicad
We will be making this with KiCAD, a PCB making software. This will be a good intermediate level KiCAD tutorial. Later we will be ordering and assembling our PCB with some SMD components.
![](/images/babyslipring/20220731135313.png)

### CAD
Very minimal CAD in this lesson. There are only 2 parts that will be needed to be designed.
### Code
No Code. 

# Materials 

#### PCB Making
- Mouser account
- JLCPCB Account
- 5mm breadboard LEDs
- [Solder Paste](https://www.amazon.com/Solder-Bi57-6-No-Clean-Lead-Free-Temperature/dp/B0195V1QEI/ref=sr_1_1_sspa?crid=335A42XX0N0E9&keywords=solder+paste&qid=1660081351&sprefix=so%2Caps%2C276&sr=8-1-spons&psc=1)
#### Mechanical
- [Snap ring pliers](https://www.amazon.com/VISE-GRIP-Convertible-Pliers-2-Inch-2078900/dp/B000JNRR0Y/ref=sr_1_2?crid=FLW6DFP490OX&keywords=irwin+c+clips+pliers&qid=1659216395&sprefix=irwin+c+clips+pliers%2Caps%2C220&sr=8-2)
- [Retaining Rings](https://www.mcmaster.com/90341A103/) 
- [1/4" Ball Bearing](https://www.amazon.com/uxcell-FR188-2RS-Flange-Double-Bearings/dp/B082PPK1L5/ref=sr_1_3?crid=QFNXBVFB30VX&keywords=1%2F4%22+flanged+bearing&qid=1659216654&sprefix=1%2F4+flanged+bearin%2Caps%2C137&sr=8-3)
- [M4 Grub Screws](https://www.amazon.com/uxcell-50Pcs-Socket-Screws-Headless/dp/B01N76NKU6/ref=sr_1_11?crid=MTNXL2QJU032&keywords=m4+grub+screw+black&qid=1658603365&sprefix=m4+grub+screw+blac%2Caps%2C119&sr=8-11)
- 1/4" Shaft
- Assorted M3 Bolts
## The Plan
Use USB-C (because it is the future) as a power-input device to power on an LED. This LED will be able to spin indefinitely and still be powered on because it will be on a slip-ring. 

**There will be two boards that we make:**

### Ring side
- USB C Female end 
- Current limiting resistor for the LEDs
- CC Resistors 
- Shell Resistor
- Exposed copper rings
- Two mounting holes 
- One large through hole straight through the center
![](/images/babyslipring/20220804221310.png)

### Contact side
- Female dupont pins for the 5mm LEDs
- Spring contacts that will establish an electrical connection with the other pcb
![](/images/babyslipring/20220804221657.png)

### Power through USB C
To get 5V from USB C, it is not as simple as just using the VCC lines. Although just using the VCC line for Type A -> USB C cables, this does not work for USB C -> USB C cables or "smart" USB C power supplies. 

USB C needs a way to acknowledge what type of device is downstream and what voltage to supply at what current. This is where the CC data lines off of the USB C port come in to play. ![](/images/babyslipring/20220808161707.png)

In order to "tell" our power supply what voltage / current we need. Simply connect two 5.1kΩ pulldown resistors to both CC1 and CC2.

You'll also notice that there is a SHELL_GND. These are the legs connected to the USB C port. Instead of wiring these directly to GND, they should go through a resistor so that there isn't a ginormous short in the case of a loose power wire. Since we are already using 5.1kΩ resistors, we'll just use a resistor to limit the current. 

# Setting up KiCAD
Create a new project in KiCAD. You can name it "Baby slip ring"

## Importing Components
Because at the time I am writing this, this USB C is in stock and super cheap. Therefore we will be using this [one](https://www.mouser.com/ProductDetail/GCT/USB4105-GF-A?qs=KUoIvG%2F9IlY%2FMLlBMpStpA%3D%3D).  Unfortunately, not everything that you want to use will already be pre-imported into KiCAD for you. Therefore you must be familiar with importing things (unless you want to make everything yourself).

![](/images/babyslipring/20220804222250.png)

### Downloading Files 
1) To import this you want to scroll down to where it says you can find the Models and click on the link to SnapEDA. 
	- I like SnapEDA because they are very consistent with providing good quality symbols, footprints, and models.
![](/images/babyslipring/20220804222322.png)

2) Click on Download symbol and footprint
3) Select KiCAD 6.0
4) Unzip the installed folder and place it inside of your project folder 
### Importing Footprints
1) Click on Manage footprint libraries under the Preferences menu of KiCAD's main menu ![](/images/babyslipring/20220804225753.png)
2) Click on the Project specific libraries tab at the top of your screen
3) Click on the plus button in the bottom left hand corner of the window.
4) Name the new entry a good description like "USB C" and then link the correct Path to the library by clicking on the Folder icon 

![](/images/babyslipring/20220804225951.png)

5) Now click on "Migrate libraries" in the bottom right corner of the screen and click "OK"
6) Open the imported footprint in the Footprint Editor to verify that it was successfully imported 

### Importing Schematics
1) Click on Manage symbol libraries under the Preferences menu of KiCAD's main menu 
2) Click on the Project specific libraries tab at the top of your screen
3) Hit plus button in bottom left corner
4) Name the new entry (Purple circle)
5) Click on the library logo and select the path to the USB C's .lib file 
6) Click Migrate Libraries in the bottom right hand corner of your screen 
7) Press OK
8) Now open the file in the symbol editor and verify that it is correct
9) Press E whilst still in the symbol editor to open the properties menu 
10) Change the footprint path to be updated and correct by clicking on the little 3 vertical bars menu under "Footprint"

![](/images/babyslipring/20220804231359.png)

11) Under the Datasheet entry, copy/paste in the link to the product page. 


# Using KiCAD
## Making the Ring Side
#### Rings
First we are going to want to make a 2 pin symbol for the Rings.
1) Open up the symbol editor and create a new symbol, simply titled "2 Wire Ring"
2) Draw a simple box with 2 pins. One will be power and the other will be ground Power will have a designator of one and GND will have designator 2.![](/images/babyslipring/20220807170917.png)

Next we should make the footprint for our symbol.

The end result should look something like the image below

![](/images/babyslipring/20220807210854.png)

1) Open up the footprint editor
2) Make a circular pad that is 10.16mm from the origin. The pad must should be 3mm in diameter with no through hole 

![](/images/babyslipring/20220807205906.png)

3) Now right click on the pad and click on "Edit pad as graphical shape" (Ctrl+E) is the shortcut. 
4) While in this menu, any shape you draw will be a pad. Make a circular ring with the center point at the origin and the end point on the circle. Change it's thickness to be 3MM 

![](/images/babyslipring/20220807211806.png)

5) Repeat the steps except with a ring that is 15.24mm from the center and having designator of 2. 
6) Now click on both of the rings and press "F" on your keyboard. This switches it to the bottom copper layer 
7) Readjust the rings so that they are centered on the footprint editor again, if neccessary
8) Ensure that your footprint looks something like this: 

![](/images/babyslipring/20220807210854.png)

Now go back to your 2 wire ring symbol and press "E" to edit the properties. Link the footprint to the one that you just made in the last step.


### Finding the 5.1kΩ resistors 
We will need to find exactly what resistors we are going to **buy** since we are going to use [Power through USB C](#Power%20through%20USB%20C)
1) Go to [Mouser](https://www.mouser.com/)
2) Navigate to Passive components -> Resistors -> SMD Resistors/Chip Resistors 
3) Now use the filters to find the correct resistor that we want.  
- Criterias: 
	- Panasonic (since they're a good brand)
	- 5.1kΩ
	- 0402 or 0603 size
4) Hit "Apply Filters" when done
5) Now click on the first part that comes up and that is in stock. Save the link to the product  page for later.

### Finding the 470Ω resistors 
Follow the directions for the [Finding the 5 1kΩ resistors](#Finding%20the%205%201kΩ%20resistors) except do it for 470Ω resistors. This is our current limiting resistor for the 5mm LED

**change it to be more simple**

### Making the Schematic  
Ensure that you have properly installed the [symbol and footprint library](#Importing%20Components) for our USB C
1) Open the project schematic 
2) Drag in the USB C, 2 Wire Ring, and 2 generic Resistor symbol 
3) Click on one of the Resistors and press "E" to edit it's properties. 
4) 
	1) Change the value to 5.1k
	2) Change the footprint to a SMD Resistor either 0402 or 0603 in size (whatever you chose) 
	3) Paste in the link to the product page for the Datasheet row
5) Do the same for the other Resistor, except it is the 470Ω variant
6) Copy/Paste in two more 5.1k resistors.
7) Follow the schematic below 

![](/images/babyslipring/20220808170709.png)

### Making the PCB
Press "U" on keyboard to import everything into a PCB. Annotate the board if not already done so. 

1) Make two cocentric circles on the edge cuts layer to define our board outline. One should be 7.64mm in radius and the other 28.74mm in radius.
2) Ensured that the Rings are cocentric with the board outline.
3) Make USB C Port stick out directly to the right of the center of the circle (orange arrow) . I would reccomend overhanging the USB C port off the edge of the board (red arrow) a bit to ensure that a cable would be able to plug into it. 

![](/images/babyslipring/20220808175414.png)

4) Click on the "Add a footprint" button and find the "MountingHole_3mm". 
5) Place two mounting holes directly above and directly below the center of the slip ring. Each hole should be 22.86mm from the center of the ring.
6) Place the passive components closely around the USB C port.
7) Route all the traces. 
8) Press Alt+3 and verify that it looks something like this: 

![](/images/babyslipring/20220808180719.png) 

![](/images/babyslipring/20220808180744.png) 

## Making the Contact Side 
Create a new project titled "Contact Side"

### SMD Contact Footprint
We will be using these spring [contacts](https://www.mouser.com/ProductDetail/Harwin/S7061-42R?qs=1s%252BlIcjv25vHEKMBFMytKA%3D%3D). The datasheet says that they are rated for sliding and have a height of 5.7mm. Both of which are important for the mechanical aspect of this slip ring. 

Now we will be making the footprint to hold these contacts.
1) Click on the above link to the spring contacts and open the datasheet.
2) Create a new footprint within the Contact Side project
3) Follow the "RECOMMENDED PCB LAYOUT" to create two rectangular pads. 
4) Press "F" on both of your pads to move them to the bottom copper layer. 
5) One of them should be 10.16mm (designator 1) and the other 15.24mm (designator 2) from the center 

![](/images/babyslipring/20220809154506.png)

Create a copy of the 2 Wire Ring symbol that you made in the previous step. Except that this one will be for the 2 Spring Contacts.

Now go back to your newly copied smybol and press "E" to edit the properties. Link the footprint to the one that you just made in the last step.

### Making the Schematic
1) Create a new schematic 
2) Draw in the 2 Spring Contact symbol that you made in the previous step
3) Also import in two generic LEDs.
4) Edit the properties of both of the LEDs
5) Set the footprint of the LEDs to simply just be a 1x2 dupont pin 

![](/images/babyslipring/20220809161610.png)

6) Connect your schematic's traces like so 

![](/images/babyslipring/20220809161637.png)


### Making the PCB
1) Copy up to step 1 in the previous section's [Making the PCB](#Making%20the%20PCB)
2) Ensure that the origin of your Spring contacts are cocentric with the board outline. 
3) Again, click on the "Add a footprint" button and find the "MountingHole_3mm". Place two mounting holes directly above and directly below the center of the slip ring. Each hole should be 22.86mm from the center of the ring.
4) Put the LED Duponts 12.7mm to the right of the origin and 10.16mm down 

![](/images/babyslipring/20220809162439.png)

5) Complete the same but mirrored about the y axis 
6) Wire up the PCB
7) Add text on the Front Silkscreen layer indicating the positive and negative end of the LED

![](/images/babyslipring/20220809162634.png)

# Ordering
This is the final step. Make sure that you have made these PCBs correctly and ran the DRC check or else when these pcb's come and they're incorrect it willl be a sad day.

## Exporting machining files for JLCPCB
1) With the PCB open, press Plot (Printer icon in top left)

![](/images/babyslipring/20220809162910.png)

2) Under output directory create a new folder in the project folder named "exports" (this will make exporting easier). Then select that folder you just created as your output directory.
3) Generate drill files (bottom right). Then hit the Generate drill file again on the window that just pops up
4) Close and hit "Plot"
5) Now compress to zip file on the exports folder 
6) Now do the same but for the other PCB

## Ordering from JLC's Website
1) Go to [JLCPCB](https://jlcpcb.com/)
2) Upload the **Ring side zip** file to JLCPCB
3) Select the PCB color that you want (Black is usually the best color) 
4) Because this has small SMD components that you aren't going to be able to solder by hand, we are going to need to order the stencil. 
5) Scroll down to the bottom of the order page and enable the stencil option 

![](/images/babyslipring/20220809164701.png)

6) Repeat the same step except for the **Contact side zip** file. Know that you do not need to order the stencil as well with the Contact side board.

## Ordering from Mouser
Now we need to order our electrical components from Mouser. As a good rule of thumb, I always order **double the quantity** of any passive component I may need. Reasoning being that if you fuck up or drop them, they are so small that they are probably gone forever. 

Remember that you can simply click on the link that you assigned to each component under the "Datasheet" column. 

**Order list:** 
- 2x USB Cs
- 6x 5.1kΩ Resistors
- 2x 470Ω Resistors
- 4x [SMD Spring Contacts](https://www.mouser.com/ProductDetail/Harwin/S7061-42R?qs=1s%252BlIcjv25vHEKMBFMytKA%3D%3D)

## Ordering from Amazon
Make sure that you have all the mechanical components that is required to assemble the PCB, since the actual PCB takes about 1-2 weeks to arrive.


# 3D Printing
Print out the required files for the assembly of the actual slip ring. (Power Input and Output side parts)

[Onshape](https://cad.onshape.com/documents/7e4d5f0707a25351e8d13112/w/9d0378d822ee5adaee731d07/e/08f298a3772dbd6067a75a64?renderMode=0&uiState=62f2f84e395ff224f64a4894)


# Assembly 
## USB C Side 
Watch from 2:15 - 3:53 of this [video](https://www.youtube.com/watch?v=DYrucIWig24&ab_channel=GreatScott%21)
The video demonstrates the technique that we'll be using for the side of the PCB with a USB C  connector . 
1) We will stick our desired PCB to the table with some tape
2) We can lay some of our extra pcbs around to make it an even surface for us to place our stencil on 
3) We align our stencil so that it matches with the pads on our pcb
4) Stick it down with tape
5) Spread out the paste
6) Carefully put on the components with really fine tweezers
7) Now instead of using a hot air gun like in Great Scott's video, we will simply be using the PCB at Envision to melt our PCBs

## Contact Side
1) Hand solder the spring contacts onto the board. It doesn't matter which way they are facing
2) Solder female header pins on the opposite side of where the spring contacts are


## Final assembly 
Use the [CAD Model](https://cad.onshape.com/documents/7e4d5f0707a25351e8d13112/w/9d0378d822ee5adaee731d07/e/08f298a3772dbd6067a75a64?renderMode=0&uiState=62f2f84e395ff224f64a4894) to see where fasteners and such need to go.

1) Attach each ring to its respective 3D printed mount with M3 bolts 
2) Insert 1/4" flanged bearings into the top and bottom hole of the spring contact side 
3) Insert a relatively short 1/4" axle into the bearings
4) Add Snap rings on either side
5) Thread on the grub screw into the hole on the ring side
6) Insert shaft from the Spring contact side into the hole for in the ring side 
7) Adjust amount of contact to be just the right amount of rub without too much noise
8) Tighten the grub screw, locking the shaft when satisifed
9) Insert 5mm LEDs, making sure to get the polarity correct

