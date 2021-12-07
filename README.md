![image](Images/fekt_logo.png) <br/>
# WATER TANK CONTROLLER

### Team members

- **Gregor Karetka**   &nbsp;                             *id=221053*   &nbsp;&nbsp;    (Piri Piri Chicken masterchef)<br/> 
- **Martin Knob**   &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;               *id=221054*   &nbsp;&nbsp;    (Buga Buga dancer) <br/>
- **Filip Kocum**   &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;   *id=221055*   &nbsp;&nbsp;    (Angakok singer) <br/> 
- **Samuel Košík**   &nbsp;&nbsp;&nbsp;&nbsp;              *id=221056*   &nbsp;&nbsp;    (Ochre Dreadlocks follower )<br/> 



Link to this file in your GitHub repository:

[https://github.com/amwellius/DE2_Project_2021-22](https://github.com/amwellius/DE2_Project_2021-22)

### Table of contents

* [Project objectives](#objectives)
* [Hardware description](#hardware)
* [Libraries description](#libs)
* [Main application](#main)
* [Video](#video)
* [References](#references)

<a name="objectives"></a>

## Project objectives

This simple but useful application will help you to fully control your water tank (not only!) in the garden. Do you want to know how much water left? Do you want to replenish the tank? Or are you interested in controlling your own, independent application based on the volume left in the tank? <br/>
No problem! <br/>
With this **water tank controller** you will be able to:
- know current water level in centimeters, percentage and liters,
- see maximum volume of the tank,
- use relays to control DC fans, pump to replenish the tank, irrigation control, windows opening and more,
- prevent owerflowing the tank with extra sensor,
- see graphic representation of the water level.



<a name="hardware"></a>

## Hardware description

As main programming board is used **Arduino Uno**. For representing results was chosen **Nokia 5110 LCD display**, **Relay module** and **button** (optional). Main water level sensor is ultraonic **HC-SR04**. There is one extra sensor used as backup to prevent overflowing the tank or detecting filth (leaves, flowers, pollen, ...) in the tank. We have used **Capacitive Soil Moisture Sensor v1.2**. 

### Arduino Uno + breadboard 
[Datasheet](https://github.com/amwellius/DE2_Project_2021-22/blob/main/Datasheets%20%2B%20DOCs/ATMega_328P_datasheet.pdf)

&nbsp;
![all pic](Images/pic_all.png)
&nbsp;

Application uses a number of pins and 3.3 V and 5 V power supply. Schematic can be seen here [SCHEMATIC](https://github.com/amwellius/DE2_Project_2021-22/blob/main/schematic.pdf). 

### Nokia 5110 LCD display 
[Datasheet](https://github.com/amwellius/DE2_Project_2021-22/blob/main/Datasheets%20%2B%20DOCs/Nokia5110_datasheet.pdf)

&nbsp;
![NoKia or YesKia?](Images/pic_nokia.png)
&nbsp;

All output data is shown on Nokia LCD display. Library from internet has been edited in order to use with *Arduino Uno*. Display's resolution **84x48**  allows to display many useful data or **graphic representation** of water level as well. Drawn images were converted to byte arrays to simplify the usege in *Microchip Studio*. <br/>
Picture below shows possible states. <br/>
![water states](Images/water_states.png)

### Relay Module 
[Datasheet](https://components101.com/switches/5v-single-channel-relay-module-pinout-features-applications-working-datasheet)

&nbsp;
![figure](Images/relay_module.png)
&nbsp;

Usage of relay(s) is optional. **C code** has implemented section which triggers the relay module by pressing **button** connected to Arduio Uno. A capacitor inserted in cicruit helps to stabilize overoscillations generated by the button.

### UltraSonic sensor HC-SR04
[Datasheet](https://github.com/amwellius/DE2_Project_2021-22/blob/main/Datasheets%20%2B%20DOCs/HCSR04.pdf)

&nbsp;
![figure](Images/pic_ultrasonic.png)
&nbsp;

Main sensor for measuring the water level of the tank. After entering its dimensions the sensor is calibrated. Providing it with short 10us pulse will result in receiving 8 cycles of 40MHz signal. This will be given by *ECHO pin*, so received value will be the time the wave travelled to the water and back to the sensor. Final distance can be obtained by this equation: 

&nbsp;
![equation](Images/HCSR04_equation.gif)
&nbsp;

Where **t** is the received value on *ECHO pin* and *0.034* cames from the speed of sound *(340 m/s = 0.034 m/us)*. Sound wave travels from sensor to water, but from water to the sensor as well. That is why the result has to be devided by two. *Arduino Uno's* timers are used to measure width of received square signal. After calculation, distance in milimeters is returned. Its value is sent to other functions, so supplementary data can be sent to display on *Nokia LCD*.

### Capacitive Water Lever Sensor

[Datasheet](https://github.com/amwellius/DE2_Project_2021-22/blob/main/Datasheets%20%2B%20DOCs/water_level_sensor.pdf)

It is situated *a few* above main ultrasonic sensor. If ultrasonic fails, this option will prevent overflowing the water tank. Display will print **System overflow** message. Relay module can the programmed for specific behavior after getting to *overflow* stage, too (optional). <br/>
Sensor is connected to analog input pin, GND and Vcc=5 V. Its usage describes table below. <br/>
   
   | **Value** | **Results in** |
   | :-: | :-: |
   | <=850 | System working properly |
   | >850 | System malfunction! |


&nbsp;
![figure](Images/water_level_sensor.png)


<a name="libs"></a>

## Libraries description

Write your text here.

<a name="main"></a>

## Main application

![figure](Images/pic_ph_1.png)

The main purpose of this application is to automatize operation of regulating water level in specified tank. After knowing volume of tank, ultrasonic sensor connected to **Arduino UNO** board will measure the water level. LCD Nokia 5110 display shows water level in centimeters, percentage and max usable volume of the water-tank. Application uses one extra sensor to control the max volume. In normal conditions, sensor gives negative data of water level all time. It is situated few centimeters above the max bound of water (we do not want to fill the tank completely to prevent owerflow). If the water reaches this sensor, ultrasonic has occurred hassle and LCD shows problem ("Owerflow", "Error").

Our product has the ability to interact with relay modules for external usage. These can be used to replenish the tank, irrigation pump control, DC fans, windows opening, and others. 

### How to use
1. Mount *ultrasonic sensor* on the top of water tank. Sensor's reference **zero (100%)** is set to be 4 centimeters from the ultrasonic transceiver.
2. Mount *Capacitive sensor* about **1 centimeter** above max water height. (If ultrasonic fails, capacitive sensor will save it from drowning).
3. Insert dimensions of your water tank into C code. If maximum height of your tank is e.g. 100 cm, than insert only 96 cm, to prevent owerflow.
   ```c
   // Tank Volume
   //**Enter values in cm !
   #define TANK_X  ((uint32_t)50)
   #define TANK_Y  ((uint32_t)50)
   #define TANK_Z  ((uint32_t)100)
   ```
4. 
5. ds

<a name="video"></a>

## Video

Write your text here

<a name="references"></a>

## References

### Used materials:
   - Theoretical knowledge from Digital-Electronics-2, 2021 > [Link](https://moodle.vut.cz/course/view.php?id=242365)
   - Lab classes **DE2** > [Link](https://github.com/tomas-fryza/Digital-electronics-2)
   - Byte Arrays Generator > [Link](https://javl.github.io/image2cpp/)
   - online stuff > [Link](www.hereenterlink.hell)
   - online stuff > [Link](www.hereenterlink.hell)
   - online stuff > [Link](www.hereenterlink.hell)
   - LaTeX equation editor > [Link](https://www.codecogs.com/latex/eqneditor.php)
   
 
   ### Used programs and its links:
   - [MicroChip Studio](https://www.microchip.com/en-us/development-tools-tools-and-software/microchip-studio-for-avr-and-sam-devices)
   - [SimulIDE](https://www.simulide.com/p/home.html)
   - [GitHub](https://github.com/)
   - [GitHub Desktop](https://desktop.github.com/)
   - [Git Bash](https://git-scm.com/download/win)
   
________________________________________________________________________________
©2021, VUT FEKT, Brno, Czech Republic <br/>
Košík, Karetka, Kocum, Knob <br/>
**For Educational Purposes Only!**


