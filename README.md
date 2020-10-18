# R3-Training-Task-1
##### R3 Robotics Training Task 1, Software Module
The goal of this task was to program 2 motors to an Arduino using the L293D motor controller. Along with using a potentiometer to control
the motors speed with PWM (Pulse Width Modulation). 
#### L293D Pin Layout: 
![alt text](https://github.com/VincentP05/R3-Training-Task-1/blob/main/L293D_Layout.png "IC pinlayout")

### TINKERCAD DOCUMENTS:
[TINERCAD](https://www.tinkercad.com/things/dY2yLzBlQaX "TINKERCAD page")

My Design:
![alt text](https://github.com/VincentP05/R3-Training-Task-1/blob/main/R3SoftwareModule.png "IC pinlayout")

Overview:
First off, I completed the wiring as specified in the documents, which included connecting the L293D to the two motors and the Arduino pins to the L293D pins. 
Along with connecting the potentiometer to the arduino to control the PWM delivered to the motors. Lastly, the dip switch was also connected to the Arduino, in order
to control the modes of the motors. As for the code, initially all the ouputs were initialized to their respective pins. Then in the set up, the pinmodes were declared accordingly 
to the documents. For the potentiometer, a function was created to constantly read the analog pwm values, the value was scaled from 0 to 1023 to 0 to 255. Lastly, a series of 
if, else if, and else statements were created in order to change the modes of the motors, depending on which switches were HIGH or LOW on the dip switch. 
