---
title: "Finite Element Analysis: SolidWorks"
date: 2022-08-05T18:57:03.950Z
description: By Blake
---
<!--StartFragment-->

Finite Element Analysis: SolidWorks![](https://lh6.googleusercontent.com/Ct3VL6LDNKnQhvjegw0sQmuxUqV_mYfgg-EHubFVf-iXn7RkImqvOXmjBGArlmShpXKXflonR85cKIBQjJYDs4i_AORbID-xD0tlNiZg5zThYYfAWToXL7JkB62ReIj9wWw9luQbfOVNsJtrVJvMjQU)





**1.1 Quick Introduction:**

Finite Element Analysis (FEA) is a powerful tool used by engineers to predict how parts and assemblies react to forces: heat, fluid flow, vibration, etc. Computer software such as SolidWorks, FEMAP, ANSYS, and Matlab use numerical analysis to create a general 3D mesh on the surface of the product and calculate stresses based on user-defined materials and forces. 



Note: Solidworks is not the most precise FEA software to use for engineering purposes, however, it is still accurate and is simple to use. Solidworks comes with a Simulation Advisor which is a helpful tool that walks you through the process. 



 

**1.2 Definitions and The Process:**

Definitions:

Finite Elements: Discrete amount of shapes used to calculate the deformation of a part. They are connected together at nodes and are typically triangle shaped in SolidWorks.



Mesh: The culmination of all connected finite elements of a part perfectly dispered over the surface area of the part. A good mesh can determine the accuracy of your FEA. 

  

Von Mises Stress: Used to predict yielding from external stresses. Typically represented by red colors in FEA, yielding stress can occur at several different locations on a part depending on the load magnitude, direction, and location. 

 

The process for FEA goes as follows;

1. Define the reason for the study. You could possibly be concerned with:
2. 1. Excessive compression/expansion/deformation
   2. Temperatures
   3. Loading cycles
3. Define the material being used
4. Create fixed geometries at certain locations
5. Apply loads at certain locations
6. Generate a mesh to your liking
7. Run study



**2.1 Creating a Static Study in SolidWorks**

The rest of this tutorial will be explained using the part shown below:

![](https://lh6.googleusercontent.com/qIp3qPAM-bYSduQQk0_ZK86y-MgtTpGFWt5G0zjlrIkXMIfHmZNgu7m2VhPb58lb5hkBXEiWKnFpqmzqkCUjWSoAJhBw0dP5lGPshnun4_XoVSWkPpRHhO4TJx1ebkyy8xOefw7H8QMAInfeCXhQx-I)



Start by going to the “Simulation” tab at the top of the screen and clicking “New Study”

![](https://lh4.googleusercontent.com/0GN2qjuOj4lCGATTZM61Ewnuwd_quA5pj2x67gmUV4YvbYklVjuzKo6aZli58wmbJfwCwvBL-S-kI1ga1EEMeBfHY-lI9hRDrb481sutOgCYUCwQ74bitMpUKrDpPw-nURULDJyY7CNzqfj-vWr0cEk)



In the Study menu ensure that you check the Static box under General Simulation and click the green checkmark. 

![](https://lh3.googleusercontent.com/b9Y2Xu9aA7dk9gWkKjMaiX_nutemr8ddq2X2068OClq-dFGdNLzBb9VMb4To8l5EimVI9CKQzu_90_ummgCapXs5lmwrRLRfmjEFIPxACc0Us1QswW7X_CJCfQZS0ggiwnnfFv-LQS76tSU31Lgt-fI)

**2.2 Applying Materials**



After you have made a new Study, click on Apply Material at the top of the screen. 

![](https://lh4.googleusercontent.com/zSi6U9aRwSlvVJFQMw7iM2uQNonMtzAJraayegJddAAil3_uXPkcx3TjP89H3pXCu_ZskB89CQ1U6WJTHhwvYCDWXY6wMauu53W9wYE_h8GQ6txMt6e_1CYO2TDGAFPFEgM9dIzqRwk6z_oPrc18j9k)



For this tutorial we will be using 1023 Carbon Steel. Be aware that most materials you will ever need to analyze will be in this material library, however, you can add your own material be clicking the “Add…” button. When you’re done click “Apply”, this may slightly change the appearance of the material. 

![](https://lh3.googleusercontent.com/C0ATIT9UEox8L_k3RD7ApQWVRff7Fl5Oe-T8z2fkVV9NRFSN89unKHkO1UTVeflGaOQbDUe9irVtKdii08MUgpSBDEFi7rY2MjnzMvgwIPDyjk6HcefPwiuWmUVRjQEVtTZ2_scP7G2px9RvFjSC5pU)



You can confirm this by checking the features menu on the right side of the screen

![](https://lh5.googleusercontent.com/DpwCWn2FNG0MVBT-8huKp3IAOX6bYQsgWSUSeb6eqlOqBZqH1NbtIJfZZOP9ffNUQmIyUM8R_UqioZwTcBywrK4LN03F71DAdgW8XUIyFdMK_Ia3x_3G0ThRONKF-Y1BCfCTxKvWmqrtjVIYRHvTNVg)



**2.3 Creating Fixed Geometries**

Fixed Geometries can be points, edges, or faces on a part that will not move in a specified direction. In order to run a FEA you need to have at lease one point of fixed geometry. To do this click on the “Fixtures Advisor” in the top bar and then select “Fixed Geometry”. 

![](https://lh6.googleusercontent.com/UiMdun5HsStAosRO-Myf50-WQN5Ysf5cd_PR1IlKwiba-Ppxlh-7M5yjh2cqh6bNU6_zTDMaq8ZOdDM3s1FsUf08QElh6Vy2rk-kaZyhTYCPntUBsME9OPuUAexN5gLrUFD4rYorISIy3MTngTFtbAQ)



In this instance, we will create a fixed geometry at the faces shown below, note that fixed geometries are denoted by green arrows in SolidWorks.

![](https://lh3.googleusercontent.com/r6TE91nUQPdtL5P35ZgTIIkOWwpFDEN2fuZK77DTocSUuEBs2zD5GBG3ies8DWoZoN12r6ziCV1WFY-tVhpvN_ltsHxWWtFmuRWsN1aow3elWim7cxYmE9iblQgCvEcJJXP1E2xOzW2hdd3XJEo92qQ)

**2.4 Applying External Forces**

External Forces can also be applied to points, edges, and faces on a part. Do this by going to the top bar and selecting “External Loads Advisor” and then clicking on “Force”.

![](https://lh4.googleusercontent.com/O8z0z9sXhJM18DoQT0Moxi9t1m3ss-cVazRIl6w1-baUtV4zDOYtnQ4SMaCKqVz7X4mYWV0YQwHBPj7VYLse2Ri8E16TyD4U4WVN52xKOVxgSMKB6eHuoL_wXT3ci-dHzRcoJ2eCaJuMXOIjoR61Ylo)



In this instance, we will apply loads at the two faces shown below (Solidworks automatically points forces in the direction normal to the face of the part).

![](https://lh3.googleusercontent.com/pLrFkERSKYXU9hVDvcSDz0LbkH1qkjxFvHQ6MeZF4AnXWIJcixFcAzkTDnTe-gEl9lJ6dmVMA1hZ1RkKBIelIQGn5OJ5KI-n-0AjWeH2h_0_6sEtTTA1UN_B8-431UlLQQoJ6UCb7mKfCQLJc6CreBc)



To change the direction of the force being applied, click the “Selected Direction” bubble and then select an axis or edge to bind it to. In this case it will be in the vertical direction (Y-axis) so I clicked on a nearby edge that was also in the vertical direction. 

![](https://lh6.googleusercontent.com/7S2QQY4lqrjnWeBPHLPNDR7ObN7WKYrWcDmS8CLHxe9SMT1q-dv-p1DON5vfah7LB34HVYyhTVH_BelWBXDlJLtGqWR09bTJbeEYXPHVoQrJp_ysELAkGQNVY3tDTxzfP7-SIT3GkbhpZCRzvwYRT8M)



Solidworks also defaults to 1N of force but in this study the part will be under 500 N. (Proceed by clicking the green check mark)

![](https://lh3.googleusercontent.com/zmB4Ya9mXiv30A24qThA_pt1hmnshSyi4U6KxUYsBDdKwhWpwe4E_XnbDu-geLFngaCSXl0i4-wBJ21FESYGrtZuJFzX6qUKeB0qeH_C4fsaQVRKu_qZ72cByeKGRZzqWc7p4G2iFjIVJF3SIRvteaM)

**2.5 Generating a Mesh**

Solidworks automatically creates a mesh before a Static study is run. However you may want to view and change the resolution of this mesh in order to generate more accurate results with your study. Do this by going to “Run This Study” and clicking on “Create Mesh”.

![](https://lh5.googleusercontent.com/1mbNBZUH7KrWIUawh4AbTgBLUefG7hnnLzEgGjSPqTt2876aSM-3d7T6L3rM_-m7eR-0Gxn3a8dc-kjDAbVnnpPkM3DH-NPSiUMqo-67WL5syBXcxJZqiuFC2GZ4LfKCe9q5goAmN_d7YsWCFagC9LU)



This opens up a window that gives you options on how you want to create your mesh. Mesh Density changes the size of individual triangles depending on how Coarse or Fine you want your elements to be. In this case, we want the finest possible mesh. 

![](https://lh3.googleusercontent.com/AaGNYJ5CuF2145DxM5MBsQ02lYAzTczljyOVaUsrGkHyVQh2LhGB0CnWU_qD4uvSmsNVIyHHidugoRJ_gEmRib5DS2ctdKVMLBy057WzmHvexTlhh26yqnwGQi3eQTKdebMvfAV-h9p0pQjl2qTlRew)



Mesh Parameters, when checked, allows you to manually input the maximum and minimum element sizes and gives you options for mesh curvatures. In this case we will just be using the “Standard mesh” option. 

![](https://lh5.googleusercontent.com/nFJM9Q7yhPFmesxRsEdjgTx4sLeXXz7EulEl-ZaFspmQW6KFR790_aWh3Kt1-Fa1AGIYc1bMZ_7Bf_QFOqWoQJlK-bcpscrEcRquA7BjOzaNlJcQ3qgMXNWsDOWsfl69jfLVFMETeCaGLXRGbjJeIAk)



Clicking the green check mark will tell Solidworks to create the modified mesh based on our new settings and parameters. The resulting mesh should look like this:

![](https://lh5.googleusercontent.com/AfkBjc2yr08lVYJXeoOuCwPGEsxuM4e1MS39VL2tdKBYO51CyeklfdXUYUSAhZYNIeGNKIbJ3USI8guW9ho6SGKKa2PpOScJyQzcRUbdcNkE86nSjPz0wtVC6chi8IN-pcqsJSLf5idIgR5pY7iXsy4)



**2.6 Running the Study and Post Analysis**

The final step in the process is to run the study by clicking “Run This Study” in the top bar. Allow Solidworks some time to generate the results. 

![](https://lh4.googleusercontent.com/7-GFRYYAf6S_MHABo2P5hweI2NFu3MjAfjNgr_6LTv5rPVL6GGXDnAzsHbo5Lwm1H8kTpBmKzECImv7g9StC7gtsFiUg7IQ7eSuu7Sa7MRQZd_X7ZgH9kbwPNXPbMZSQs02qGyZEbCPc3xq3eNAfMRA)



Your part should now be visually deformed and new results should pop up in the feature menu. Solidworks automatically gives results for vonMises Stress, Displacement, and Strain. 

![](https://lh3.googleusercontent.com/kAGFoE-xjdSJVY-aOATpq9q37TEkXPn8xa2FJZmUY8GxQ1Fax-5OG62HzojBiJxFWTrMpw5msg1kWFti0YtNBuN5Omol6H8VZCU0cb_iuzn23sh0Xl9Bgq5YJ7xaFFWBJrSqq7LlZJVZPEAHK3_lfZc) 



By right clicking on any of the results and clicking “Show”, Solidworks adds color to your part and highlights important areas of change. (This can also be done with a double-click)

![](https://lh6.googleusercontent.com/TifAUrk4MRu0ZWLHB-DedEsHLlTok6hXXs8myOMTK3dbw3N3l6MxZsZvZdCWfXhAoMBXSOvim8y9CYeCySRUE5x70mQ9NllFhTOhR-njza2PN5O9qbOB6OP93_msHq13x0on56PLC2F2X7D-ONv-qX4)

![](https://lh4.googleusercontent.com/vREj1Agx17s0Iz5o3BwGGTMuPaRyf6__XCTvs0xthXqS_pMeVfbPkdw9z_wLyq2GTN8B7ApZS-vA9OoROe5MHhX_RXtrTg33sgNagaL2ShP9LFmZjmJa9dAbpYoG0CnOZVI_5N9Ut_CaBIlH4XWRcE0)



Note: The top left corner of the viewing space shows a “Deformation scale” number. This value is multiplied by the true deformation amount so that it is easier to see a difference in the model. 



Another Note: According to the von Mises stress chart here, this part has a Yield Strength of 2.827e+08 \[N/m^2] and it looks like no sections of the part reach this limit (indicated in red) so, most likely, no yielding will occur under a load of 500 N based on this simple analysis.



***Deformation Scaling***

Changing the scale of deformation is simple. Right click wanted result and go to “Edit Definition”. In the Plot menu, head to the “Deformed shape” section, click “User Defined”, and input a deformation scale number below

![](https://lh5.googleusercontent.com/gvTytrKZdlE5ABJawtvgHR-sydHg8R1YvP1OIMhZErI34r1BxVkmbdry-clsg3eqabPilSvMKvLoTtezIPBAxaXiCLaFjaJum_d-Stf8dfWxuYlTzl_biABVZGp15lcOHuRwnAWUwSppiJI5U2SbiDw)



***Creating a Deformation Animation***

Sometimes it may be useful to see how your part will deform using a moving picture. To create an animation, right click on “Stress1” under “Results” and click on “Animate”.

![](https://lh6.googleusercontent.com/IpmolSCgX2XLcFmPBiQIxVbqBAt_AcQyUyq7cP6kFkAG2CtI-A0AIomcKMPl4mx3dYMts9tBqsy3CAK8_4M4Wt5KoyenLi94HmEZCu2KyV6rEYimiVFvBd0mxQ81SRHLByl_hL6y7JMctuHWqF5ux_E)

This automatically creates an animation with a default of 5 frames. To make the animation smoother, stop the playback and type in a larger amount like 30. This will take longer to calculate but you will have a much smoother result.

![](https://lh5.googleusercontent.com/VWKmDvMJDf8_36UlC1J6jZfSo7bQN_3qu21IlBKva88zg-NLwUSfqCvVPBURrV-v1juO6i_bClrwpudCIg7cVfwcflt5yiAQrPAvaB0OzGm0pIrT6YTpGCH26cPHVLLrFbSVxI8HYOjM8lYlF4dI28I)



<!--EndFragment-->