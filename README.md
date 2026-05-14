# 🚗 Car-Black-Box
The **Car Black Box System** is an embedded systems project designed to record and monitor important vehicle parameters such as **speed, gear position, time, and event logs**. Similar to an aircraft black box, this system stores critical data that can be useful for analyzing vehicle activity during abnormal conditions or accidents.

Developed using the **PIC18F4580 Microcontroller** and **Embedded C Programming**, this project demonstrates real-time monitoring, data logging, menu-driven operations, and peripheral interfacing in embedded systems.

---

## 🚀 Features

- ⏱️ Real-Time Clock (RTC) integration using I2C Protocol  
- 🚘 Real-time monitoring of:
  - Vehicle Speed
  - Gear Shifts
  - Time Stamps
- 📝 Event Logging System  
- 📂 View Stored Logs  
- 💾 Download Logs through UART  
- 🗑️ Clear Log Function  
- ⚙️ Set Time Option  
- 🎛️ Menu-driven interface using Matrix Keypad/Switches  
- 📟 LCD Display for real-time data visualization  

---
## 🛠️ Technologies Used

- 💻 Embedded C  
- 🔹 PIC18F4580 Microcontroller  
- 🛠️ MPLAB X IDE  
- ⚙️ XC8 Compiler  
- 🔄 UART Communication  
- 🔗 I2C Communication  
- 💾 EEPROM Storage  
- ⏱️ RTC Module  
- 📟 LCD Display  
- 🎛️ Matrix Keypad  

---

## 🧠 Concepts Used

- 🧩 Embedded C Programming  
- 🏗️ Modular Programming  
- 📝 Real-Time Data Logging  
- 🔗 I2C Communication Protocol  
- 🔄 UART Serial Communication  
- 💾 EEPROM Memory Handling  
- ⏱️ RTC (Real-Time Clock) Interfacing  
- 📈 ADC for Speed Monitoring  
- 🎛️ Menu-Driven System Design  
- ⚡ Interrupt and Peripheral Handling  

---

## 🧩 Hardware Components

-  PIC18F4580 Development Board  
-  RTC Module (DS1307)  
-  External EEPROM  
-  16x2 CLCD Display  
-  Matrix Keypad  
-  UART Interface  
-  Power Supply Unit  

---

## ⚙️ Working Principle :
The system continuously monitors vehicle parameters and stores important events with corresponding timestamps into EEPROM memory. The RTC module maintains         accurate time using the I2C communication protocol. Users can navigate through various options such as viewing logs, clearing memory, downloading logs, and        setting time using the keypad interface.

---

## 🗂️ Project Structure

```
Car-Black-Box-System/
│
├── README.md                 # Project documentation
├── main.c                    # Entry point of the application
├── black_box.h               # Common macros, declarations & configurations
│
├── adc.c                     # ADC functions for speed monitoring
├── adc.h                     # ADC function declarations
│
├── clcd.c                    # CLCD display functions
├── clcd.h                    # CLCD function declarations
│
├── dashboard.c               # Dashboard display and monitoring logic
│
├── ds1307.c                  # DS1307 RTC interfacing functions
├── ds1307.h                  # DS1307 RTC declarations
│
├── external_eeprom.c         # External EEPROM read/write operations
├── external_eeprom.h         # EEPROM function declarations
│
├── i2c.c                     # I2C communication protocol implementation
├── i2c.h                     # I2C function declarations
│
├── main_menu.c               # Main menu handling functions
├── menu_options.c            # Menu option functionalities
│
├── matrix_keypad.c           # Matrix keypad interface functions
├── matrix_keypad.h           # Keypad function declarations
│
├── uart.c                    # UART communication functions
├── uart.h                    # UART function declarations
│
└── makefile                  # Build and compilation instructions
```

---
## 📷 Project Modules

  ### 📊 Dashboard Display
  - ⏱️ Time  
  - 🚘 Speed  
  - ⚙️ Gear Position  

  ### 📋 Menu Options
  - 📂 View Logs  
  - 💾 Download Logs  
  - 🗑️ Clear Logs  
  - ⚙️ Set Time  

---

## 🎯 Learning Outcomes

- ✅ Gained hands-on experience in Embedded C Programming  
- ✅ Understood peripheral interfacing using I2C and UART protocols  
- ✅ Implemented real-time data logging concepts  
- ✅ Improved debugging and problem-solving skills in embedded systems  
- ✅ Learned EEPROM memory handling and storage techniques  

---

## 🚀 Future Enhancements

- 📍 GPS Tracking Integration  
- 📡 GSM Alert System  
- ☁️ Cloud Data Storage  
- 🚨 Accident Detection Sensors  
- 📱 Mobile Application Connectivity  

---

## 👨‍💻 Author

**Mohammad Mohseen**  
Embedded Systems Enthusiast  
