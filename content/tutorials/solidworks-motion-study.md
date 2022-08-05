---
title: SolidWorks Motion Study
date: 2022-08-02T18:31:23.086Z
description: By Blake
---
<!--StartFragment-->

Solidworks Motion Study

EnVision Maker Studio



1.1 Introduction:

Motion studies are graphical simulations of motion for assembly models. You can use Solidworks mates in an assembly to restrict the motion of components in an assembly when you model motion. Motion studies in Solidworks do not change the properties of an assembly model. Instead, if changes are made to the assembly after the creation of the motion study, the software will automatically update the study and reveal any possible conflicts. 



1.2 MotionManager:

The MotionManager is where you can find all of the core Solidworks tools used for motion analysis: Animation, Basic Motion, and Motion Analysis. 



![](https://lh3.googleusercontent.com/HxenWpK1tI1FZ7f-tEAJsCWy6-1HpJcavYNtTfekjyqhUvKLpSiuUMASMX0c7qzd1aBQByrLtJK6f9BPXwd-2fxhXs77m87o-nvhDr7pcuGNls0-tOb89n0Pzy5R1fw9-67jqjO3vWbPewiIj00PTjw)



This toolbar is by default found at the bottom of the screen, however, if you do not see anything there you may have to enable the add-in in the settings. To do this go to the top of the screen and click on the settings icon and click “Add-ins” from the pull down menu.



![](https://lh6.googleusercontent.com/7nhx4RD8Q2N2GAuDEr5wpxMVjumTooz74zE8xavBuwyNcA9mzm55DEgf01gXhk5Zod4i_iFx2yrVeuhBm8iEfTJ-tzBcHSPEWDJtgEXEEB92TSjw4R76vt_m9H250Snx8JTOPq3Kbdqkugl3BD6S9RE)



From the “Add-ins” menu ensure that “SOLIDWORKS Motion” and “SOLIDWORKS Simulation” are checked before clicking on “OK”.



![](https://lh6.googleusercontent.com/O4T1uG2fNGNIenax-2YfDw26jI6rjycq6LEJo2cSqITg0_NvybpY9NBZw3_h81Oyha-T61XTlzl_QdfoEQHb-MgSJFMccK2R7kgvIlibhSkX2KkKHJoxiluU0NLDJPDv2mUXO2J4M-LETE8H1QeuT8Y)



Animation



2.1 Animation Wizard:

The Animation Wizard is a quick and easy way to create simple animations of the current assembly. This does not include the movement of parts defined by mates, rather it generates a simple rotation of the entire assembly based on the current camera position.

![](https://lh5.googleusercontent.com/zS_zOAtYYPM0hxG2fkH0RizIRILcce5IPYDuc0-hBICZkZuJ9q2A4X9pQeQZbipYDr6Fl0qU3TVI2Tsm9Q76jZhDVgaIYO-kfHtPuS9Us4dv0TMWQcwDhTkZZUgg-JrgTS-hj9lsmW6_dJ4TCFWut3Y)



In the first pop-up window select “Rotate Model” and click Next.

![](https://lh6.googleusercontent.com/kCBPkgkFR_kcL8irSEWb8BNO2ApvXv7YMj1l-RyLxTuNGbaTyjZ4xKjzsi0x4oqkg6uRK-95URyJu0QtjW44wuWrOIGhHEDnMbQTPZQ4eDl3Hb86zp9dCd0a_H65n_lX6ivGqbbqxucDSQlaorEaR78)



The second pop-up window will ask you which direction to rate in, how many rotations, and which original axis you would like to rotate about (typically choose Y-axis).



![](https://lh3.googleusercontent.com/JHcWeTpmREV5fD3fTG0puXtSuHOs-Gx5K2hqF5BG8UaZ6CgfgqUZWT-U5FlGFg04N5xj-5txC-OW7LcKxJIBOnQq1xXd4kYmgbopGYA958l-J5f5SVCuBegnZaS8rt486aIdzZUY5vP50tgvKRHWvkg)



The last pop-up menu will ask you when to begin the rotation and how long the rotation will last.



![](https://lh4.googleusercontent.com/M1ZI4FZ7_2OGf_sa3HN_SNfhxMak-qjMUMIIyt1WDQErkPK3vPL71ufJ4kqANS30_Sik_Pl9XjIcpe4HJb3Uk12kxR7h7MzuddrE2uwqbgON3Lsd27wbeXvo5B11xfSvRRhqam7HIfO5-zAP6TVbIpo)



The Animation Wizard then generates camera keyframes marked as diamonds in the MotionManager. Before starting the animation, ensure the grey bar is at the “0 sec” mark. Clicking the play button will start the animation.



![](https://lh6.googleusercontent.com/lLMifym2L1XrRjo4sMVQUXesJht92IFCOYBJhKDxjaCer2CObzX2Q3Hy--RJu4v8A6mTb2i3i5e9ygiR2GxWJSOCHsegxaEjjqxvKXpc1XTV-BtRh6AjuLcjC8kaH5gMSD9zB8D2VxdFMcbLJBQ1Oos)



2.2 More on Camera Keyframes:



Instead of using the Animation Wizard to make keyframes, we can make our own camera keyframes based on our views in the Solidworks assembly window. First find a view in your Assembly window that you want to begin your animation on. Next locate and right-click on the first keyframe next to “Orientation and Camera Views”. Click on “Replace Key”, this changes the first camera view of the animation to be yor preffered starting view. Until you replace this key again, everytime you start the animation from the beginning it will return to this camera view. 

![](https://lh3.googleusercontent.com/YKkKlFOp0e6z9aL9XKxZgdIvTzWKRMAH5_iCDgrQjjOvMX3O4YcNpPRGqAqOD-pPvbSgEKz66Egk3fZG-djKYZns0-YVgcrfb4YUstCbPi82sJhp5vvjWMlprFhVDGYgEGGmb4hFTtdqmnqXtAbZ960)



Bounce Animation:

The easiest way to make camera keyframes is by click-holding onto the first keyframe and dragging it along the time line. This makes a copy of the original camera view but that can be changed by clicking “Replace Key”. First create two copies of the first keyframe and place them along the timeline like so: 

![](https://lh4.googleusercontent.com/8yqRmfprG0PeiM36m1dFE6GdQrCY09JFTW7aymkNE2mpMTDUzsyMgbC3LNR9Gw6O38SSVNU3VDiVFQtI4Th7rFnXAvdeqLIQ31blq2QDFUWn0n1eDDsZZzlmzyDZN78AKz3yxyvH4_yZl_FI-DpmGxs)



To create the Bounce animation, move the grey bar to be right on top of the middle keyframe. Next move the assembly to a second position that is different from the first. Finally right click on the middle keyframe and select “Replace Key”. Note: this process can be done with any keyframe you create on the camera timeline.



![](https://lh5.googleusercontent.com/9mrCOsgBhyfWRPeRcI32qqH3JvAADfcT_rdEH5i8BwBTojKODQkbD-ehojAAD2yIXg77bHU4hNB-43Hh6xxf8YCnYgzcrasktyWcOpzJoToauqFnrPMXqI8CfIKu-rBHWUSW496CGfK3EKV1JhlODRg)



This will create a Bounce animation where the camera moves from Position 1 to Position 2 and then back to Position 1. You can also move around the keyframes to change the speed of the Bounce Animation to how you see fit.



2.3 Motors:

Motors can be used to manipulate a component for a certain amount of time as defined by a mate. In this tutorial you will animate a rotation along an axis but be aware that you can also create a linear oscilation along an edge/axis as well. 

![](https://lh5.googleusercontent.com/1v3UvnLKZ7hRjImCkV2K9aIGsOop2dlVrM8lInRfpiVY1qhsjXyd7D55WZJyO0npdNo5Q9diIN7cLYHQ78zW_wZM9Rx7SHxNTRCMQZYOLxR3GoF8p1mMWKWq7Na3FBpjHFUA415WoJQF6zDILBu9aYU)

Note: Create a new motion study quickly by right clicking your current “Motion Study” tab at the bottom of the screen and selecting “Create New Motion Study”

To create a Rotary Motor, first click on a circular edge to establish what direction and part that you want to move. The assembly mates will update based on the properties of the motor. Ensure that the motor you create has a red arrow indicating the direction of the motor which can be changed. 

![](https://lh4.googleusercontent.com/0Urck4MaqtIvoVk9xjUlIBaJd5HfT09HeXoOsgrfN90xvCFHrEPWn7MkGAswpz6O06svTSZIpdy6okrLv1_9mOHFr1dhZ6aquMX5fep1qIn9zpilC5k699uAUvDD-_nVb2c22q62I87Sbd9J-ICqrDY)

The motion box gives you many options to control the motor including distance, oscillation, segments, etc. For this specific example I will be using the Constant Speed option which will rotate the motor in one direction at 25 RPM. Clicking the graph at the bottom of the box allows you to more closely analyze the motion.

After clicking the green checkmark, you will see a new Motion Study element created on top of all the model features. To see the motor move click the play button and allow Motion Study to calculate the frames. 

Note: You can recalculate frames whenever in motion study by clicking the Calculator Icon:



![](https://lh3.googleusercontent.com/f29SLdRGMuG-roK4wgRXZol0Jq5sbiP5iFcQSrVNpYUDX7wtQek2HlCTc6KwbbV9T6lhA5LsNGBv8ycQHQWAZ_ZapXs8SOsEhAiWND5KGZXZSQYxuZEXQzlRDVr275beGohSjpN8PfvHjF3qNIFddDY)



Animation Framerate

Solidworks automatically sets the framerate of the animations to 8 FPS which creates a rather choppy viewing experience. Change this to a higher number in the animation settings menu 



![](https://lh5.googleusercontent.com/1v3UvnLKZ7hRjImCkV2K9aIGsOop2dlVrM8lInRfpiVY1qhsjXyd7D55WZJyO0npdNo5Q9diIN7cLYHQ78zW_wZM9Rx7SHxNTRCMQZYOLxR3GoF8p1mMWKWq7Na3FBpjHFUA415WoJQF6zDILBu9aYU)

Basic Motion

Basic Motion is different from Animation as it takes into account the mass, inertia, gravity, and contacts to calculate motion more accurately. Animation simply uses interpolation provided by keyframes whereas Basic Motion is capable of creating more complex real-world simulations. Change to “Basic Motion” in the Motion Manger bar at the bottom of the screen. 

![](https://lh6.googleusercontent.com/ARQ-fMSU-rBFcIOdVKCK2OeBkwsB5uIB0n1NCvjRYIoitRUKkUPoA0YzzdTgbK9h602hwt2TpOUvULFNdICKzEoOh6_uceyb5itv0ElnLHwR_e6zM6emarXuKnanClL4ZwG2t8EjEMlDmTOXK630H6w)

3.1 Gravity:

Gravity is a key tool to simulating motion in an assembly. Go to the right side of the Motion Manager bar and click on the falling apple symbol. 

![](https://lh6.googleusercontent.com/lJ-4cUSyGkConaVp6fM2U9Juhwb083zi1d_t_2iDqdBZTfj3wCQOoGczhMqE6uEcR9NOuGFPzNinR1zgrpMFl8Jzb7WTIMGRIpcOKnDmRiGw9yP9b7PvRxAKbq4lusXdulFsg1zRtXi7TegWTMfFFaM)



Next you have the option to choose the direction and magnitude of gravity in your assembly either based on a chosen edge/axis or one of the global axes. In this example we will choose the global Y-axis and ensure the green arrow is pointed down.

![](https://lh5.googleusercontent.com/gCrbKU-SFv3LNQNyqYsOihKTqAFbxKeU6kCd5RsAH8RsDXqEWFyw7ym8pC7F-I8_4jebciYBorJWM5bELqD_V5VEs0-ERQYoEfwyrZbpBJ-stRB1M_qL2N5gGcEQlxbtwt4Ped4pdss0TYsDqldMipI)

3.2 Contacts:

Defining contact points/surfaces in a Motion Study is crucial to simulating real-world interactions. In Basic Motion, this works well with smooth surfaces that do not have many complicated rough edges. This button is just left of the gravity button.

![](https://lh5.googleusercontent.com/jfUSLwbsSsPgAzvAj8rMEce-ejWSAj1wG5wGTtfyfdewTT2nvRQg4NLmhptFHVidCaxP59IH2nbWEbi5xoQSplnvB4_4phra9oBLBg5fH8S1YbOFs8MwXe793DJXHaHRrIVFDyrnM-9lMeHYnShcLMM)



Note: You can create contact groups which simulate interactions between different sets of objects. In this example, however, we will only be using one set of contacts. 

Clicking on parts will highlight the entire surface and create contacts. 

![](https://lh6.googleusercontent.com/3mIkm0KtCqdha-mrsGtcTnCugsejNlHBaTw6TgFqIUpmwrephZd1GDUQso4HMuTcuE1xDoPicTngXvcRa0vLX8whxl56E10Gd4PazJhWzyEI29qL2J2_RkmR9yJ5vvZ7_-meYkGJAVQDm4-j3rdEe0w)



Clicking on the Calculate button will run the simulation (Be sure to change the framerate to smooth out the animation)

 ![](https://lh6.googleusercontent.com/7HiCSY3uWGRrwj23idoeLB1fx4rxZeatXSREa1DFyUDz0bALSgFIQBvBVxqrKZamYtrOkU6iw7YpeNNRarMkNOo1LszMCNy-a5aL2RPapJjXlsfEGLW6ib5oUhWWJxUE77mxOLUONqofr35LmnppleY)



<!--EndFragment-->