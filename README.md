# README.md

# ESP32 Potentiometer Project

This project is designed to read values from five potentiometers connected to the ESP32 DevKit. The potentiometers are connected to the following GPIO pins: 36, 39, 34, 35, and 32. The readings are translated to a scale of 0-4095, and the degree of spin and percentage of spin are calculated and displayed.

## Project Structure

```
esp32-potentiometer-project
├── main
│   ├── potentiometer_main.c
├── components
├── CMakeLists.txt
├── sdkconfig
└── README.md
```

## Getting Started

### Prerequisites

- Ensure you have the ESP-IDF installed on your system. Follow the official ESP-IDF installation guide for your operating system.
- Install the ESP-IDF extension in your code editor.

### Instructions to Open and Run the Project

1. **Install Prerequisites**:
   - Ensure you have the ESP-IDF installed on your system. Follow the official ESP-IDF installation guide for your operating system.

2. **Install the ESP-IDF Extension**:
   - Open your code editor.
   - Go to the Extensions view and search for "ESP-IDF" and install the extension.

3. **Create the Project**:
   - Open a terminal in your code editor.
   - Navigate to the directory where you want to create your project.
   - Run the command: `idf.py create-project esp32-potentiometer-project`.
   - Navigate into the project directory: `cd esp32-potentiometer-project`.

4. **Set Up the Project Structure**:
   - Create the `main` directory: `mkdir main`.
   - Create the `components` directory: `mkdir components`.
   - Create the `CMakeLists.txt` file in the root directory and add the necessary configurations.
   - Create the `README.md` file for documentation.

5. **Add the Code**:
   - Create the `potentiometer_main.c` file in the `main` directory and copy the provided code into it.

6. **Configure the Project**:
   - Run `idf.py menuconfig` to configure your project settings, such as the target chip and other options.

7. **Build the Project**:
   - In the terminal, run `idf.py build` to compile the project.

8. **Flash the Project**:
   - Connect your ESP32 DevKit to your computer via USB.
   - Run `idf.py -p (YOUR_PORT) flash`, replacing `(YOUR_PORT)` with the appropriate port (e.g., `/dev/ttyUSB0` on Linux or `COM3` on Windows).

9. **Monitor the Output**:
   - After flashing, run `idf.py -p (YOUR_PORT) monitor` to see the output from the ESP32, including the potentiometer readings.

10. **Stop Monitoring**:
    - To stop monitoring, press `Ctrl + ]` in the terminal.

Now you have a complete setup for reading potentiometer values on the ESP32 DevKit!