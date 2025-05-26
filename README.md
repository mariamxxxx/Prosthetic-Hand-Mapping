# Prosthetic Hand - Mapping Finger Movement (In Progress)


This repository contains embedded code for an ESP32-controlled prosthetic hand. The current implementation reads analog signals from five potentiometers—each corresponding to a finger—and translates the input into both degrees of rotation and percentage values. The readings are also mapped to a register scale (up to 4089) for further processing or actuation.

Key features:

-Multi-finger Analog Input: Captures signals from five independent potentiometers to represent individual finger positions.

-Signal Translation: Converts raw analog readings into degrees of rotation, percentage of movement, and register values for downstream control.

-ESP32 Microcontroller: Utilizes the ESP32 platform for real-time analog input handling and future wireless capabilities.

-Extensible Architecture: The current codebase is intended as a foundation for advanced prosthetic hand control.

Upcoming features:

-Machine Learning Integration: Planned implementation of machine learning algorithms to produce complex hand gestures and enable adaptive, user-specific movement control.


Note:
This project is incomplete and under active development. The current upload demonstrates the initial data acquisition and mapping functionality. Machine learning features and complete actuation logic will be added in future updates
