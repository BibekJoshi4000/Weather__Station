# Arduino Weather Station

This Arduino project is a weather station that measures temperature, humidity, rain, and water level. It uses an Arduino Mega 2560 board and various sensors. The project is intended as an embedded system and was created by Bibek Joshi.

## Getting Started

### Prerequisites

- Arduino Mega 2560 (or compatible) board
- DHT11 Temperature and Humidity Sensor
- Rain Sensor
- Water Level Sensor
- I2C LCD Display (16x2)
- Arduino IDE installed
- Required libraries: LiquidCrystal_I2C, DHT

### Installation

1. Connect the sensors and the I2C LCD display to the Arduino board. Adjust pin numbers if using a different board.

2. Install the required libraries using the Arduino Library Manager.

3. Open the Arduino IDE, load the sketch, and upload it to the Arduino board.

### Usage

1. Open the Serial Monitor (9600 baud) to view temperature and humidity readings.

2. The LCD display will show information about rain status, temperature, humidity, and water level.

## Customization

- You can customize the project by adjusting the names in the LCD display setup section (lines 34-39).

- Ensure proper pin configurations if using a different Arduino board.

## Context and Use Cases

This weather station project can be used in various contexts, including:

- **Home Weather Monitoring:** Keep track of indoor temperature and humidity.

- **Garden Monitoring:** Monitor rain conditions and soil moisture for efficient gardening.

- **Educational Purposes:** Ideal for learning about Arduino, sensors, and data visualization.

- **DIY Projects:** Serve as a base for creating more complex weather monitoring systems.

- **IoT Integration:** Expand the project for internet connectivity to create a remote weather station.

## Code Overview

The Arduino code for this weather station project is structured as follows:

- **Sensor Initialization:** The code begins by initializing the DHT11 sensor for temperature and humidity, creating custom characters for the LCD display, and setting up pins for the rain and water level sensors.

- **LCD Display Setup:** The LCD display is configured with custom characters for water drop, sun, degree Celsius, and percentage symbols. The project creator's name is displayed at the beginning.

- **Main Loop:** The main loop continuously reads data from the DHT11 sensor to get temperature and humidity readings. It then checks the rain sensor to determine if it's raining and displays corresponding information on the LCD, including temperature, humidity, and water level.

- **Custom Characters:** Custom characters (bitmaps) are used to represent water drops, the sun, the degree Celsius symbol, and the percentage symbol, adding a visual element to the LCD display.

Feel free to explore and modify the code to suit your specific needs. If you have any questions or need assistance, refer to the comments in the code for detailed explanations of each section. You can also email @ bibekjoshi4000@gmail.com
