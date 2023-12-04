# IOT Surveillance Robot

## Description
IOT Surveillance Robot is a sentry rover designed for wide-range accessibility. It operates on the NodeMCU protocol, enabling seamless communication and control. 

## Hardware Components

- ESP8266 Camera Module
- ESP32 Node MCU
- STM32 Microcontroller
- Proximity Sensor
- SIM28ML GPS Module
- Motor Driver
- Temperature and Humidity Sensor
- Other relevant components

## Dependencies

- Arduino IDE
- ESP32 and STM32 Board Support Packages (BSPs)
- Additional libraries (e.g., TinyGPS++, DHT)

## Setup Instructions

1. **ESP8266,SIM28ML & ESP32 Setup:**
   - Open `CameraWebServer.ino` and  `maps.ino` in Arduino IDE.
   - Set the correct camera model and WiFi credentials.
   - Make the neceessary connections, follow the instructions [here](https://mechatrofice.com/arduino/gps-latitude-longitude).
   - Upload the code to the ESP32.

2. **STM32 Setup:**
   - Open `main.c` in your STM32 IDE.
   - Configure the STM32 peripherals and pins as needed.
   - Upload the code to the STM32 microcontroller.

3. **NodeMCU Firmware:**
   - Ensure NodeMCU firmware is installed on the ESP32.
   - If not, follow the instructions [here](https://docs.platformio.org/en/latest/platforms/espressif32.html#platform-package).
   - Install required libraries and dependencies.

## NodeMCU Protocol

- The NodeMCU protocol is a custom communication protocol implemented on the NodeMCU firmware.
- It facilitates the exchange of image data, sensor readings, and control signals.
- Data is formatted as JSON for simplicity and flexibility.
- HTTP communication is used, with custom commands for specific actions.

  ![nodemcu](https://github.com/ksheersagaragrawal/surveillancerobot/assets/76050795/8d750410-30c9-4f70-b264-3f1dc329e5f9)

## Operation

The Surveillance Robot can be controlled remotely through a user-friendly web application hosted at [https://ksheersagaragrawal.github.io/surveillancerobot/](https://ksheersagaragrawal.github.io/surveillancerobot/). The web interface provides intuitive controls for real-time interaction with the robot. 

1. **Surveillance Robot:**
   - The surveillance robot is designed for unmanned spaces. It has no range constraints and operates on battery power and internet connectivity.
   - Team can operate rover using only four keys (A, W, S, D) from anywhere around the globe using a user-friendly web application interface.  
   - NodeMCU Server facilitates in real time communication between the web application and the sensors.

3. **Data Processing:**
   - The NodeMCU reads data from various sensors, including temperature & humidity sensors, Camera Module, GPS Module.
   - The NodeMCU connects to the predefined WiFi network and posts the json data on NodeMCU server.
   - The Web Application fetches the sensor data from the NodeMCU in real time.
   - The Web Application read the movement of operation of the rover and sends the data to the NodeMCU server.
   - The NodeMCU reads incoming data and translates it into directional commands to the STM32 microcontroller.
   - The STM32 interacts with motor driver, adjusting the robot's movements based on the interpreted commands.

4. **Real-time Tracking:**
   - The surveillance robot features a SIM28ML GPS module that continuously fetches real-time location data.
   - The accuracy of location mapping is equivalent to the highest resolution available on Google Maps.
   - The robot publishes its location data onto a dedicated website for remote monitoring.
   - The web application connects to the live video streaming server using the ESP32 camera module attactched at the fore front of rover.
   - ESP32 Cam Module featues Object Detection & Identification with OpenCV. Captured data, including images, can be stored in a database for future reference.

5. **Sensor Data Transmission:**
   - The STM32 collects real-time data from temperature and humidity sensors, transmitting this information to the website.
   - A safety feature is integrated into the robot, utilizing a proximity sensor at the front.
   - In the presence of an unseen barrier, the robot automatically halts its movement, providing a safety mechanism.
   - The operator can then redirect the robot in an alternative direction, ensuring safe and obstacle-free operation.
     
## Author

Ksheer Sagar Agrawal

## License

This project is licensed under the [License Name] - see the [LICENSE.md](LICENSE.md) file for details.

## Support

If you have any questions, concerns, or need support regarding the Surveillance Robot project, feel free to reach out. We are here to assist you in making the most of this innovative solution.
