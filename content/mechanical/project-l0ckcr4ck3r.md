---
title: Project l0ckcr4ck3r
date: 2022-08-30T05:06:17.710Z
description: A fully autonomous Lock Cracking Robot
---
By MingWei Yeoh

This is **not** for the faint of heart. This thing takes long and its hard to get right. Only for the advanced and over achievers.

**insert gif of the robot doing thing**

# **About the Project**

This robot is a true creation of the idea many years ago brought on by Samy Kamkar's [robot ](https://samy.pl/combobreaker/)that "utilized" his [algorithm ](https://www.youtube.com/watch?v=09UgmwtL12c&ab_channel=samykamkar)for cracking these combination locks. 

> I say utilized in quotes because I read through all the documentation that he included with the robot, and not only does he never demonstrate the robot actually "feeling" the lock for it's exploits but the robot's source code appears to be a simply brute forcing algorithm, which would take **FOREVER.**



<!--StartFragment-->

![Master Lock 1500D, Preset Combination Padlock, 1-7/8 in. Wide, Black Dial](https://i5.walmartimages.com/asr/3c5ce2c7-0496-4d75-8dad-ce0944061b1f.0dc4627adae0b1df42f6cac6db78eafa.jpeg?odnHeight=612&odnWidth=612&odnBg=FFFFFF)

<!--EndFragment-->

## Specifications

This robot uses a TMC2208 super silent trinamic stepper driver w/ AS5600 mag encoder on the back to turn the lock dial and "feel" for the lock's geometries. A servo with analog output detects when a successful attempt was made to open the lock. The entire process works on the majority of locks that aren't old and usually ~30 seconds. Also added functionality which includes a GUI which is an oled + rotarary encoder for user input.



# Background information

This robot takes advantage of Samy Kamkar's exploit. I reccomend watching this [video](https://www.youtube.com/watch?v=27rE5ZvWLU0&t=647s&ab_channel=HelpfulLockPicker) if you are actually going to build this. You absolutely need to understand what the robot is trying to do under the hood or else there's no way you can debug anything.