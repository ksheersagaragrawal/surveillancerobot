# surveillancerobot
This is a web application to control and monitor a STM based surveillance robot. We have used node mcu, sim28ml, temperature &amp; humidity sensor, proximity sensor, motor driver in this project. 

Surveillance robot is a high tech robot which can be deployed in unmanned spaces. It has no proximity constraints and runs on battery and internet connectivity. The team can operate the robot using just 4 keys - A,W,S,D from anywhere around the globe. We have used nodemcu that connects your laptop to robot wirelessley. Whatever key the controller presses gets posted on the node server. Node mcu reads that data in real time and converts it into directional commands with the help of stm microcontroller. 

We have sim 28 ml gps module that fetches real time location of the robot and publishes it on to the website. The accuracy of mapping is equaivalent to the highest resolution of the google maps. We also have temperature and humidy sensor that posts real time data on to the website. 

ESP 8266 camera module has been installed, that can be trained to discover objects. This data can be stored in a database for future reference.

A saftey feature - proximity sensor has been installed at the front of the robot. In case any unseen barrier falls in the way of the robot, the robot automatically stops and the controlling person can redirect the robot in another direction.

To view the website : https://ksheersagaragrawal.github.io/surveillancerobot/
 
Video Link: https://drive.google.com/file/d/1Q_dbKrY0PuHSxF_WIY76rdQhe_yMZcE0/view
