Room Access Monitoring:

We live in tough times as the Coronavirus pandemic is still very much a problem, practicing social distancing and staying away from others is especially important. However, this is difficult to do in enclosed and crowded areas. As the Federal Government has implemented a limit on the number of people entering an enclosed area, it is quite difficult to count the number of people entering or leaving a shopping mall manually.

We are designing a system of Room Access monitoring to keep track of the number of people in a room or building by increasing a counter when people enter and decreasing the counter when people leave. Once the number of people in an area surpasses the maximum number of people allowed (which can be set by the user), an alarm will go off until the number of people is within bounds again.

This can prevent buildings and rooms from being over crowded, which can help to limit the virus's spread by making social distancing easier to practice.

This project is based on a pair of laser transmitters KY-008 which fires laser on two LDR sensors LM 393 non stop. When there is no obstacle in front of LDR there is a specific resistance output given by LDR which is read by the controller. When an obstacle comes in the way the output resistance of LDR changes which is a signal that someone entered or left the room. The system is capable of detecting visitors from both directions.

This Arduino based Bidirectional Visitor Counter can calculate the number of individuals entering the project room, shopping center, office, entrance works. We can also use it at the gates of parking areas and other public places. This project calculates the total number of individuals entering through the gate and also the total number of individuals leaving through the same gate. At the same time, it calculates the total number of individuals currently in the room.  The total number of Persons inside the Room is displayed on the Liquid Crystal Display (LCD) module. The microcontroller does the above job: it receives the signals from the sensors, and these signals operate under the control of software which is stored in the ROM of Arduino.


This circuit is divided in three parts: sensor, controller and counter display. The sensor would observe an interruption and provide an input to the controller which would run the counter in up/down mode depending upon the selector setting. The same count is displayed on a liquid crystal display through the controller.

ELECTRIC COMPONENTS REQUIRED:

                             1. Arduino Uno Microcontroller, ATMEGA328P-PU X 1 (With USB Wire)
                             2. Laser Module KY008  X 2
                             3. i2c LCD (Arranged)
                             4. BreadBoard X 2
                             5. Male to Female Wires + Male to Male Wires 
                             6. LDR Module LM393 X 2
                             7. Buzzer 
                             
                             
 Circuit Diagram:
![Project Fritzig_final_File_bb](https://user-images.githubusercontent.com/78413592/125916968-ea9c1a14-bb85-4cf7-9299-7f7014ec32d4.png)




Algorithm / Working:

![Algorithem](https://user-images.githubusercontent.com/78413592/121541188-5be13600-ca07-11eb-80cc-25b1563eca58.png)




LDR 1 is attached at Front side of door and LDR 2 at the back side
Situation 1 Person Enters:
LDR 1 triggers first then after a brief interval LDR 2 triggers
	Microcontroller will take it as person entering so it adds 1 to the counter
Situation 2 Person Leaves:
LDR 2 triggers first then after a brief interval LDR 1 triggers
	Microcontroller will take it as person leaving so it subtracts 1 from the counter
The Counter value is updated at real time
LED Screen shows the counter
There is a loop that checks the counter and if the value increases the predefined value it raises a flag and the microcontroller activates the buzzer until the counter value reaches the defined value.

Final Build:
![Project_Final](https://user-images.githubusercontent.com/78413592/125916801-2fc9632e-6dd1-46ac-9fd5-bd0046cd0583.jpg)


Youtube Link For FInal Presentation:
https://youtu.be/LZewqXrxwp0




