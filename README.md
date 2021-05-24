# -Arduino-Room-Access-Monitoring
Room Access Monitoring:

We live in tough times as the Coronavirus pandemic is still very much a problem, practicing social distancing and staying away from others is especially important. However, this is difficult to do in enclosed and crowded areas. As the Federal Government has implemented a limit on the number of people entering an enclosed area, it is quite difficult to count the number of people entering or leaving a shopping mall manually.

We are designing a system of Room Access monitoring to keep track of the number of people in a room or building by increasing a counter when people enter and decreasing the counter when people leave. Once the number of people in an area surpasses the maximum number of people allowed (which can be set by the user), an alarm will go off until the number of people is within bounds again.

This can prevent buildings and rooms from being over crowded, which can help to limit the virus's spread by making social distancing easier to practice.

This project is based on a pair of IR (infrared) proximity sensors that detect an obstruction when there is an interrupt. The system is capable of detecting visitors from both directions.

This Arduino based Bidirectional Visitor Counter can calculate the number of individuals entering the project room, shopping center, office, entrance works. we can also use it at the gates of parking areas and other public places. This project calculates the total number of individuals entering through the gate and also the total number of individuals leaving through the same gate. At the same time, it calculates the total number of individuals currently in the room.  The total number of Persons inside the Room is displayed on the Liquid Crystal Display (LCD) module. The microcontroller does the above job: it receives the signals from the sensors, and these signals operate under the control of software which is stored in the ROM of Arduino.


This circuit is divided in three parts: sensor, controller and counter display. The sensor would observe an interruption and provide an input to the controller which would run the counter in up/down mode depending upon the selector setting. The same count is displayed on a liquid crystal display through the controller.

ELECTRIC COMPONENTS REQUIRED:

                             1. Arduino Uno Microcontroller, ATMEGA328P-PU
                             2. IR Module X 2
                             3. LCD, 16X2
                             4. Bread Board
                             5. Male to Female Wires + Male to Male Wires 
                             6. Arduino Programming Wire and Power Supply
                             7. Buzzer 

Circuit Diagram:

![Schemetic](https://user-images.githubusercontent.com/78413592/119345788-a9387600-bc99-11eb-9731-9765212cbdb9.jpg)



 

Algorithm / Working:

![Entry Cartoon 2](https://user-images.githubusercontent.com/78413592/119345887-c4a38100-bc99-11eb-8651-996a510a59ad.PNG)

 


Sensor 1 is attached at Front side of door and Sensor 2 at the back side

Situation 1 Person Enters:

Sensor 1 triggers first then after a brief interval Sensor 2 triggers

Microcontroller will take it as person entering so it adds 1 to the counter
    
Situation 2 Person Leaves:

Sensor 2 triggers first then after a brief interval Sensor 1 triggers

Microcontroller will take it as person leaving so it subtracts 1 from the counter
    
The Counter value is updated at real time

LED Screen shows the counter

There is an loop that's checks the counter and if the value increases the predefined value it raises a flag and microcontroller activates the buzzer until the counter value reaches the defined value.







Group Members:

Adeel Ahmed

Ali Faizaan 

