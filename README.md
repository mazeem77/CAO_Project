# CAO_Project

Project comprises of 2 modules:

- One is accelerometer based Car That consists of following components:
    - ESP8266 (NodeMCU) as a development board.
    - HC-05 Bluetooth module for serial communication between Android App and Car
    - l298n motor Drivers for driving motors
    - Battery along with battery charger and Voltage Booster that provides 2A of current.
    - Android APK created in MIT App Inventor that takes accelerometer values from mobile sensor and then send them via Bluetooth to the Car BT HC-05.

- Second Module is GPS Tracker that consists of:
    - *UBLOX NEO-6m GPS tracker* that is the most accurate gps module configured using *u-center*, a Windows app to consol log value using UART interface through FTDI module or using ESP module.
    - ESP8266 as development Board
    - Server that gives the *Latitude*, *Longitude*, *Sattelite time* and also gives the **Google maps Link** which directs to Google Maps App ith the given coordinates pin pointing on the Map.