# Arduino-Ultrasonic-Distance-LED-LCD

This Arduino project measures distance using an **ultrasonic sensor**, displays the distance and light levels on a **16x2 LCD**, and controls **LEDs** based on proximity. The red LED blinks faster as objects get closer, while the green LED stays on when the area is clear.

## Features
- Distance measurement with ultrasonic sensor (HC-SR04)
- LED control based on distance
- LCD display for distance and light level
- Non-blocking code for smooth operation
- Adjustable blinking speed based on proximity

## Components
- Arduino Uno or compatible board
- HC-SR04 Ultrasonic Sensor
- 16x2 LCD Display
- Red & Green LEDs
- Photocell (light sensor)
- Resistors and jumper wires

## Wiring
- **Trig Pin** → Arduino pin 9
- **Echo Pin** → Arduino pin 8
- **Red LED** → Arduino pin 6
- **Green LED** → Arduino pin 7
- **Photocell** → Arduino A0
- **LCD** → Pins 12, 11, 5, 4, 3, 2

## Usage
1. Connect the sensor and LEDs as shown in the schematic.
2. Upload the sketch using **Arduino IDE**.
3. Observe distance and light info on the LCD and LED behavior.

## Photo

![Arduino-Ultrasonic-Distance-LED-LCD-2](https://github.com/user-attachments/assets/74abe682-84d5-4659-82ce-bc04ed87c7c9)
![photo_2025-09-10_15-46-46](https://github.com/user-attachments/assets/07f04cbc-3e6b-4f47-a0ae-58bb7e351e51)


