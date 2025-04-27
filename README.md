# Smart Water Level Monitoring System

**Academic Project**  
> This project was developed in collaboration with my colleagues as part of an academic project at ISIMM Institute in 2023.

## Project Description
This system is designed to monitor the water level in a tank using an ultrasonic sensor and ESP32. It provides real-time feedback through an LCD display and sends updates via the Blynk IoT platform.  
The system also controls a water pump automatically depending on the water level, with additional visual and sound alerts (LEDs and buzzer).

## Components Used
- ESP32 Development Board
- HC-SR04 Ultrasonic Sensor
- LCD 16x2 I2C Display
- 1-Channel Relay Module
- Water Pump
- Buzzer
- 3 LEDs (Red, Green, Blue)
- 9V Battery (for the pump)
- Breadboard and connecting wires

## Wiring Instructions

### HC-SR04 Ultrasonic Sensor
| Pin | Connection |
| VCC | 5V |
| GND | GND |
| Trig | GPIO 12 |
| Echo | GPIO 13 |

### Relay Module
| Pin | Connection |
| VCC | 3.3V |
| GND | GND |
| IN1 | GPIO 14 |

### LCD Display (I2C)
| Pin | Connection |
| VCC | 5V |
| GND | GND |
| SDA | GPIO 21 |
| SCL | GPIO 22 |

### Water Pump
| Pin | Connection |
| NO (Relay output) | Water Pump +
| GND (Battery) | Water Pump -

### Buzzer
| Pin | Connection |
| Positive | GPIO 33 |
| Negative | GND |

### LEDs
| Color | Connection |
| Red LED | GPIO 2 |
| Green LED | GPIO 5 |
| Blue LED | GPIO 4 |

---

## Water Level Status and Actions
![image](https://github.com/user-attachments/assets/bedb3d4f-8ded-47b0-be20-c7129dc07981)

During the system operation, different actions are triggered depending on the detected water level, as described below:

* Low Level
When the water level is low ("Low"), the user activates the water pump by pressing the control button.
The red LED turns on, and the LCD displays the message "Level: Low; Motor is ON".

 ![image](https://github.com/user-attachments/assets/7c0f403e-5f07-47be-86a1-e537fc89354d)
 ![image](https://github.com/user-attachments/assets/d01a0ea1-5e0d-4b97-afa3-8d9915d08b04)

* Medium Level
When the water level is medium ("Medium"), the user continues to operate the water pump by pressing the control button.
The blue LED lights up, and the LCD shows the message "Level: Medium; Motor is ON".
![image](https://github.com/user-attachments/assets/7cc335c0-ce1d-48c1-a3ec-a6de1dcc7718)
![image](https://github.com/user-attachments/assets/3de784e4-193b-4b90-8a98-4dd5b89e418a)

* High Level
When the water level is high ("High"), the user must activate the pump by pressing the control button.
The buzzer starts emitting sound signals, the green LED lights up, and the LCD shows "Level: High; Motor is OFF".
![image](https://github.com/user-attachments/assets/995216c9-37ae-4a82-9e19-1e29250599a8)
![image](https://github.com/user-attachments/assets/b4c3e19e-b92a-42b8-8565-023989974fca)

The prototype demonstrated a functional smart water monitoring system capable of alerting and taking action based on the water level, confirming the success of the project.


