# Smart-home-with-Footstep-power-gen
This project aims at illustrating how energy can be conserved in homes by using footstep power generation by the usage of piezo electric sensors. It also implements user remote access and status view of a smart home in a simulated environment. 

![image](https://user-images.githubusercontent.com/70501926/123086840-84beed80-d441-11eb-87d3-d57636718b9f.png)
![image](https://user-images.githubusercontent.com/70501926/123086771-740e7780-d441-11eb-8d19-86fd97152f21.png)

## Features
- Piezoelectric floors generate many microwatts up to many watts per
step, depending on space, number of people and piezoelectric
sensitivity.
- Each step pressed on the sensors produces approximately 3.8V per
sensor.
- They require very low Soldering temperature.
- Piezo sensors are ideal in anti-tamper and industrial health monitoring
applications.
- Transportation and packaging processes greatly improve the reliability
and robustness of the piezo ceramics.
- It can save energy consumption and direct the surplus energy towards
other activities that require power.
- Reducing electricity bill for the consumers and help reach lower price
category of electricity consumption
- Communicate with appliances in home with a remote that can also
display status/safety of the home
## Software components
• Proteus simulation tool
• Arduino IDE
• Virtual serial Ports Emulator
• Visual Studio with .NET wpf platform
## Simulation components
• Piezo sensor
• Temperature sensor
• Gas sensor
• Flame sensor
• LEDs, LCD display, Serial Monitor
• Arduino UNO
• COMPIM
• Motor
## Expected outcomes
• Control appliances remotely through serial communication
• Get any alert from sensor and manage the home accordingly
## Results
Proteus simulation tool has the hardware appliances connected to Arduino and
Arduino to COMPIM. COMPIM facilitates serial data to and fro serial ports COM
1 and COM 2. The voltage produced in the piezo sensors are directly
proportional to the number of steps taken in till that time. The more the voltage,
faster the Motor rotates.
Other components such as sensors activate whenever there is environmental
event change happening in home. Gas sensor detects presence of any leaked
gas to prevent accidents. Flame sensor detects if there is any fire caused
accidentally anywhere in home. Temperature sensor reads temperature in
Celsius and displays value in LCD display.
Virtual serial port driver is essential to act as a bridge between the ports COM 1 and 2.
![image](https://user-images.githubusercontent.com/70501926/123086898-9607fa00-d441-11eb-92ae-2c38919ce23e.png)
