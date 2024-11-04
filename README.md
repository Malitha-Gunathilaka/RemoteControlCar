# Remote Control Car Project

A complete project to control a remote car using Arduino Mega and ESP8266 with a React Native app interface.

## Project Overview

This project enables users to control a car remotely using a mobile app. The car uses an Arduino Mega with a built-in ESP8266 for Wi-Fi communication. The app provides directional controls and speed adjustments.

## Table of Contents

- [Components](#components)
- [Setup](#setup)
  - [Arduino](#arduino-setup)
  - [ESP8266](#esp8266-setup)
  - [React Native App](#react-native-app-setup)
- [Usage](#usage)
- [Contributing](#contributing)

## Components

- Arduino Mega 2560 with ESP8266
- Motor Driver (L298N)
- Motors and Wheels
- Power Source (12V battery)

## Setup

### Arduino Setup
1. Connect motors to the L298N driver.
2. Configure DIP switches for Serial3 communication between Mega and ESP8266.
3. Upload the `Arduino_Code/RemoteCarMega.ino` file to your Mega board.

### ESP8266 Setup
1. Configure the Wi-Fi credentials in the `ESP8266_Code/ESP8266_RemoteControl.ino` file.
2. Upload this code to your ESP8266 module.

### React Native App Setup
1. Install [Node.js and React Native](https://reactnative.dev/docs/environment-setup).
2. Download the React Native app code in `React_Native_App/`.
3. Replace `const esp8266Ip = 'http://<YOUR_ESP8266_IP>'` with your ESP8266’s IP address in `App.js`.

## Usage

- Launch the app on your mobile device and connect to the car over Wi-Fi.
- Use the app controls to move the car forward, backward, left, or right, and adjust the speed.

## Contributing

Feel free to submit issues or pull requests for improvements.

---

### License

This project is licensed under the MIT License - see the LICENSE file for details.
