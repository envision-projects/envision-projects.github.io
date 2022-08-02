---
title: SolidWorks Motion Study
date: 2022-08-02T18:31:23.086Z
description: By Blake
---
<!--StartFragment-->



## **1.1 Introduction:**

Motion studies are graphical simulations of motion for assembly models. You can use Solidworks mates in an assembly to restrict the motion of components in an assembly when you model motion. Motion studies in Solidworks do not change the properties of an assembly model. Instead, if changes are made to the assembly after the creation of the motion study, the software will automatically update the study and reveal any possible conflicts. 



## 1.2 MotionManager:

The MotionManager is where you can find all of the core Solidworks tools used for motion analysis: Animation, Basic Motion, and Motion Analysis. 



![](https://lh4.googleusercontent.com/B_tOZ1mXRWKGkEsfC0lDkMerwxz8xh0eXL8Fx0S52Rj5Wto_2nAxCi5q9kjRaXPY8q7pEGuqC7NYFzXcXshqIlQ7PWogPZygadbosWcB96eu2VR9tnhp9tZwmfxfHlEZnK5xOQZh9gaXfO0ri2uS9x4)



This toolbar is by default found at the bottom of the screen, however, if you do not see anything there you may have to enable the add-in in the settings. To do this go to the top of the screen and click on the settings icon and click “Add-ins” from the pull-down menu.



![](https://lh4.googleusercontent.com/FWDbD5BX13-mmiLDppFTPy7eL5EzNN7qZMg9xuc04KS3jol9yJEuZi1wylGyHE5Kyuxwp3kGi21xVYk5vTFo4JWI8LLoHgDBlu3DyEzLIRgxeXDSMsfVs7WHy0-uzysnVu-DYIXJ2Tp0tr_r0dRP53g)



From the “Add-ins” menu ensure that “SOLIDWORKS Motion” and “SOLIDWORKS Simulation” are checked before clicking on “OK”.



![](https://lh3.googleusercontent.com/6J7UXxsxDteeUfmjKFXMuX3kTvL3-w5DF1vk1jkVfZk3B9BrIkAukaLs8BFUgCtmwWU3aW-QB5-06q_PamOY0xZDOGhDJY14OhmfXicx0tMuhSqN_aoq9cvE7tPG0jI8sB8NImm20RDCblwqjas9csc)



Animation



## **2.1 Animation Wizard:**

The Animation Wizard is a quick and easy way to create simple animations of the current assembly. This does not include the movement of parts defined by mates, rather it generates a simple rotation of the entire assembly based on the current camera position.

![](https://lh4.googleusercontent.com/WzzMrmiTVNS-wK9As6xo_SpcIyqLpkhNz4jWmAwioyakKhIocdZOIz1D2Xsld73NrYjKtIaRBek1zgDlCfl6iSf4DLhpBwnKMLBUQeo7D4BTkjPp2fRowaUX43pHAsbIV4LsfBc-gyD8i9EbPZIKuvY)



In the first pop-up window select “Rotate Model” and click Next.

![](https://lh6.googleusercontent.com/ALISIjaAQuMfBU3pIeMQIrKtddt_B6Aqt3WpuLVYphP2Lf2Iux8jR6_NXLSwKyVnIPbxnhGyYY0HyLrdt75d7YtOlxszSfc55at26RMjB5aPBn1erkVAFA-9wGqWZFkGkXlJtywq3xQ19oesvuV5ecw)



The second pop-up window will ask you which direction to rate in, how many rotations, and which original axis you would like to rotate about (typically choose Y-axis).



![](https://lh4.googleusercontent.com/xF_vBMjXLW3lFdb8EqJvV56LTssKEp2ZtEKhDRVKK65RY69hi5E6vVWNk8LqBi-ImPCVCKWEJiAwTxDBSf54NxEOOfi7Wgd92iDW7wqZJjMWdSW-YYKBjxvxTK3BduMQu0GAELi11KjbLnpP0ZAl3fs)



The last pop-up menu will ask you when to begin the rotation and how long the rotation will last.



![](https://lh5.googleusercontent.com/MTjR6ndncj7-XRTHF_YW9ArI2LbxNTpzMqsCkjmmu2HmJtVMqPsFoIn0ZwgvnQKYSpeecTjfhaN-_wrZyuyek3dUIxy5jJj5Dn68qCTkZC8-w_0bcxBjCMYv-wo1OcyDqN-tNjBDRq_kzyIshEsWljo)



The Animation Wizard then generates camera keyframes marked as diamonds in the MotionManager. Before starting the animation, ensure the grey bar is at the “0 sec” mark. Clicking the play button will start the animation.



![](https://lh4.googleusercontent.com/xv1Cr2YbhnbKeRKkQgN-Uq9i7GtKyHte17sYmQtWIAbJz3SYye6u0HV73HYFZAQCzKHDcEhoWO_JxmfQBSgiuMXOHz_JH9kSRVQu3pUWFb_PhlRdXvqYK9Q_ZQqOpVsXXMMc2GfNNKlITgNfyMGMHP8)



## 2.2 More on Camera Keyframes:



Instead of using the Animation Wizard to make keyframes, we can make our own camera keyframes based on our views in the Solidworks assembly window. First find a view in your Assembly window that you want to begin your animation on. Next locate and right-click on the first keyframe next to “Orientation and Camera Views”. Click on “Replace Key”, this changes the first camera view of the animation to be yor preffered starting view. Until you replace this key again, everytime you start the animation from the beginning it will return to this camera view. 

![](https://lh4.googleusercontent.com/PYruSGbq2oyYhvt_wCOROlOak22EouDLPgFBAVAdZcZ3vMHUq1W6d8-J8NRxNESZKwOLChXdYkB5_Op-aABuCz37NGqEAuqgD_uidwwegWWw4cEav33sknC17TKtPMQagZRnyovCraREQhaY9Bz5PBg)



***Bounce Animation:***

The easiest way to make camera keyframes is by click-holding onto the first keyframe and dragging it along the time line. This makes a copy of the original camera view but that can be changed by clicking “Replace Key”. First create two copies of the first keyframe and place them along the timeline like so: 

![](https://lh4.googleusercontent.com/1QU2SkRNvc1en1pC8EnLNHeeQTHAnKom8Kw1C48WeiVJLe4hk1mAnDJnKqsm5_aJfg4Y_InNcYejGJ3DWfvLjYZlQnPG28j4rrbVOM5VdpDvF6r2vpS7XuIA6D6GzzR7ldrYCvfpsfpucULZihIz_rk)



To create the Bounce animation, move the grey bar to be right on top of the middle keyframe. Next move the assembly to a second position that is different from the first. Finally right click on the middle keyframe and select “Replace Key”. Note: this process can be done with any keyframe you create on the camera timeline.



![](https://lh6.googleusercontent.com/_6JQ8mPm1ziOdxtFmZz42pl1rPwFhTfiT2wlfC2UpEfDx46PqIkc323fi6xv5WSnYKuXoVYun-rwAEqaIDaaW_GL5xnnsJFa6BBBbSPwu49_gigpuTons_8OrKIu04umq2Jvbm9XSNe5_RnRwOdBBvw)



This will create a Bounce animation where the camera moves from Position 1 to Position 2 and then back to Position 1. You can also move around the keyframes to change the speed of the Bounce Animation to how you see fit.



## 2.3 Motors:

Motors can be used to manipulate a component for a certain amount of time as defined by a mate. In this tutorial you will animate a rotation along an axis but be aware that you can also create a linear oscilation along an edge/axis as well. 

![](https://lh5.googleusercontent.com/Pz4R8I3a5KVwpsWNYxhiJqQ3wU1J0Q4VVEMogAoznCXwb1F6EaWnmlKlKr5m3B-VebyNwlrNQK8UEypdADsLJKySRMeFRHzBfj-mW1By5vgFjBtPJ41iUyQlozD2hzERvGa2bNVx7-Lx2Uidj2FPOPA)



***Basic Motion***

Basic Motion is different from Animation as it takes into account the mass, inertia, and gravity to calculate motion. Animation simply uses interpolation to create  



## 3.1 Motors:



<!--EndFragment-->