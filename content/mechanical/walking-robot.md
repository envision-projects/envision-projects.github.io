---
title: Walking Robot
date: 2022-08-12T19:16:44.064Z
description: By Blake Iwaisako
---
For this project you will design a robot that walks around using a 4-bar linkage for legs! You will be required to:

1. Design a working chassis to house all electronic components in SolidWorks.
2. Manufacture and/or source all parts needed (nuts, bolts, motors, microcontrollers, etc.).
3. Create a Motion Study in SolidWorks that theoretically proves your design will work as intended.
4. Assemble the robot and write code to make it run.



![](/images/ezgif.com-gif-maker-3-.gif)

## Brief on 4-bar Linkages

4-bar linkages are a very common mechanism used in mechanical engineering that consists of four rods connected by pins. These mechanisms convert rotational motion into a rocking motion which can be very useful in robotic arms, clamping mechanisms, animatronics etc. 

\*Gif from mecademie on YouTube\*

![](/images/frankyoungcaudata-size_restricted.gif)

When designing 4-bar linkages engineers play with different rod lengths in order to find an ideal output motion. One can calculate the exact range of motion when given each rod length. 

The simplest 4-bar linkage can be seen below, called a crank-rocker mechanism. Two of the pin joints are mounted in all directions, unable to move at all. The crank arm is the input rod that controls the entire system and is what's typically driven by a motor. The coupler arm simply connects the input crank to the output rocker arm but is crucial in determining the range of motion of the entire mechanism. The output rocker arm is always longer than or equal to the length of the crank arm. 

![](/images/explanation.png)



## Design a Chassis

You can design this robot with one or two continuous rotation motors. In this tutorial we will be following a robot that has two high torque continuous rotation servo motors. 

Without dimensions, here is an example of a working chassis:

{{< tip "warning" >}}
**This chassis does not show how to mount the microcontroller or the battery, that will be up to you to add!**
{{< /tip >}}



![](/images/chassis.png)