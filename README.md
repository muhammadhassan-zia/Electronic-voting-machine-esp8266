# Electronic Voting Machine (EVM) using ESP8266

## Overview
This project is a microcontroller-based Electronic Voting Machine designed to provide a secure and efficient voting process using embedded system design.

## Features
- Button-based voting system for multiple parties
- LED indication for vote confirmation
- Buzzer feedback on each vote
- Real-time vote display on LCD
- Reset functionality for new voting sessions

## Components Used
- NodeMCU (ESP8266)
- I2C LCD Display
- Push Buttons (for voting)
- LEDs (indication)
- Buzzer
- Power Supply and supporting circuitry

## Working Principle
Each button corresponds to a specific party. When a button is pressed, the vote is registered by the ESP8266, the corresponding LED is activated, and a buzzer provides feedback. The LCD displays the selected party and updates vote counts in real time. A reset function clears all stored votes for a new session.

## Functionality
- Detects button input for voting
- Registers and stores vote count
- Displays vote information on LCD
- Provides audio and visual feedback
- Resets system for new voting cycle

## My Contribution
- Designed and implemented the complete system
- Interfaced buttons, LCD, LEDs, and buzzer with ESP8266
- Developed embedded code for vote counting and display
- Tested and debugged system performance

## Applications
- Electronic voting systems
- Classroom or small-scale voting setups
- Embedded system learning projects

## Code
The ESP8266 program for vote counting and display is included in the `code/` folder.

## Output
The system successfully registers votes, provides instant feedback, and displays real-time voting results on the LCD.

## Circuit Diagram
![Circuit](images/circuit.png)

## Hardware Setup
![Setup](hardware-design.jfif)
