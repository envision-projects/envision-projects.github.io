---

title: PCB Slip Ring Project

date: 2022-07-20T00:15:38.963Z

description: A USB-C LED Light slip ring

---


# About the Project
We will be creating a pcb slip ring that lights up 2 LED lights with a USB C Connector!

Slip rings are devices that allow electrical contacts through rotating bodies. 
	![[slipring.gif|350]]

![[cadslipring.gif]]
Usually you would buy things like this, so the question remains, why reinvent the slip ring if it already exists? 

My excuse was that they're expensive. Over 200$ if you need one with a through hole in the center :( 


![[Pasted image 20220730140802.png]]

Slip rings are a good way to practice PCB and CAD design. And they kinda cool too 

## Challenges
### Kicad
We will be making this with KiCAD, a PCB making software. This will be a very heavy KiCAD tutorial. Later we will be ordering and assembling our PCB
![[Pasted image 20220731135313.png]]

### CAD
Very minimal CAD in this lesson. There are only 2 parts that will be needed to be designed.
### Code
No Code. 

# Materials 

#### PCB Making
- Mouser account
- JLCPCB Account
#### Mechanical
- [Snap ring pliers](https://www.amazon.com/VISE-GRIP-Convertible-Pliers-2-Inch-2078900/dp/B000JNRR0Y/ref=sr_1_2?crid=FLW6DFP490OX&keywords=irwin+c+clips+pliers&qid=1659216395&sprefix=irwin+c+clips+pliers%2Caps%2C220&sr=8-2)
- [Retaining Rings](https://www.mcmaster.com/90341A103/) 
- [1/4" Ball Bearing](https://www.amazon.com/uxcell-FR188-2RS-Flange-Double-Bearings/dp/B082PPK1L5/ref=sr_1_3?crid=QFNXBVFB30VX&keywords=1%2F4%22+flanged+bearing&qid=1659216654&sprefix=1%2F4+flanged+bearin%2Caps%2C137&sr=8-3)
- [M4 Grub Screws](https://www.amazon.com/uxcell-50Pcs-Socket-Screws-Headless/dp/B01N76NKU6/ref=sr_1_11?crid=MTNXL2QJU032&keywords=m4+grub+screw+black&qid=1658603365&sprefix=m4+grub+screw+blac%2Caps%2C119&sr=8-11)
- Assorted M3 Bolts

# How PCB Design works 
![[Pasted image 20220731150317.png]]


There are 4 main categories for designing a pcb 
- Symbol ![[Pasted image 20220731152202.png|500]]
	- A depiction of a component. Symbols are what you see in a Schematic
- Footprint ![[Pasted image 20220731152311.png|300]]
	- A depiction of a component for a PCB. They are what you see on a PCB
- Schematic ![[Pasted image 20220731152433.png|500]]
	- Pictures a collection of symbols and to where they connect to
- PCB ![[Pasted image 20220731152459.png|500]]
	- Derivated from a schematic
	- Pictures where the components are placed and the traces for each wire

>[!NOTE]
>The symbol and the footprint are both associated with an individual component. For instance, a Resistor has a symbol **and** a footprint associated with it 


# Setting up KiCAD
- Install [KiCAD](https://www.kicad.org/) (free and open sourced!)
- Create a new project 
- The first thing