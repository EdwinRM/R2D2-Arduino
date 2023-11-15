# R2D2 Project

## Author
Edwin Ramirez Mondragon

## Description
This Arduino project simulates the behavior of R2D2 (Arturito) using various components, including an LED, PIR motion sensor, buzzer, motor, and servo motor.

## Components
- **LED (Arturito):** Connected to pin 13.
- **PIR Motion Sensor:** Connected to pin 7.
- **Buzzer:** Connected to pin 12.
- **Motor:** Connected to pin 4.
- **Servo Motor:** Connected to pin 2.

## Servo Configuration
- The servo motor is configured with a minimum pulse of 650 and a maximum pulse of 2550 microseconds.
- It is controlled based on sensor input to simulate the movement of R2D2's head.

## Setup
1. Connect the components according to the specified pins.
2. Upload the code to your Arduino board.
3. Power on the Arduino.

## Behavior
The project exhibits the following behavior:
- When motion is detected by the PIR sensor:
  - The LED (Arturito) lights up.
  - The buzzer emits tones.
  - The servo motor simulates the movement of the head.
  - The motor is powered on for a specified duration.
- After the motion event, the system returns to the initial state.

## Notes
- Adjustments to the servo motor angles, tones, and motor duration can be made by modifying the code.
- The LED (Arturito) and buzzer are used for visual and auditory feedback.

## License
This project is open-source and available under the [MIT License](LICENSE).

