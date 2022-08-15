---
title: Exporting Gerbers - Altium
date: 2022-08-15T16:41:24.655Z
description: How to create fabrication files in Altium
---
Once we have a completed PCB layout, we need to order our PCBs. The fastest, cheapest, and most reliable manufacturing house we have found is [JLC PCB ](https://jlcpcb.com/) It typically costs $2 for 5 PCBs, + around $22 for shipping, and they usually take around 5 - 7 days to arrive once ordered. That's quite a deal. 

But how do we go from PCB design to the fabrication house? Each software is a little different. In Altium, go to File > Fabrication Outputs > Gerber Files.

In the dialogue that pops up, choose "Inches" "2.5"

![](/images/gerbers1.png)

Then select the Layers tab. On the "Plot Layers" pull down menu, select "All Used On" then hit OK.

![](/images/gerbers2.png)

You should see the gerber-ized representation of your design, like so:

![](/images/gerbers3.png)

Next we need to export the drill files. Go to File > Fabrication Outputs > NC Drill Files. Again, select "2.5 inches" and hit OK.

![](/images/gerbers4.png)

In the small dialogue that pops up, hit OK 

![](/images/gerbers6.png)

You should now see an image of all the holes on your PCB, as so: 

![](/images/gerbers5.png)

All of the files have been exported to your project folder to Project Outputs: