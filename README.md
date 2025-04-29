# 🔥 Fire Detection & Response System

A fire detection system based on the **ATmega32 microcontroller** that monitors **temperature**, **smoke**, and **pressure** levels to detect and respond to fire conditions using actuators such as a **buzzer**, **pump**, **air conditioner (DC fan)**, and **indicator LEDs**.

---

## 🚦 System Overview

The system operates in **three states**, based on sensor input:

### ✅ Fine State
- **Conditions:**  
  - Temperature < 50°C  
  - Pressure < 100  
  - No smoke detected
- **Action:**  
  - All actuators off.

---

### 🌡️ Heat State
- **Conditions:**  
  - Temperature > 50°C  
  - Pressure < 100  
  - No smoke detected
- **Action:**  
  - Air conditioner and heat indicator LED turn **on**.
- **Recovery:**  
  - Returns to Fine State if temperature drops below 50°C.

---

### 🔥 Fire State
- **Conditions:**  
  - Temperature > 50°C  
  - Pressure < 100  
  - Smoke **detected**
- **Action:**  
  - Air conditioner and heat LED turn **off**  
  - Pump, buzzer, and fire indicator LED turn **on**
- **Exit Condition:**  
  - Requires **password input** from a keypad to deactivate and return to Fine State.

---

## 🧰 Hardware Components

- **Microcontroller:** ATmega32
- **Sensors:**
  - LM35 (Temperature)
  - MQ-2 (Smoke)
  - MPX4115 (Pressure)
- **Actuators:**
  - Buzzer
  - DC Motor (Air Conditioner)
  - Water Pump
  - LEDs (Heat & Fire indicators)
- **User Interface:**
  - 4x4 Keypad
  - 16x2 LCD Display

---

## 🔧 Software Architecture

### HAL (Hardware Abstraction Layer)
- LCD
- Keypad
- DC Motor
- Buzzer
- LEDs
- LM35 (Temp sensor)
- MQ-2 (Smoke sensor)
- MPX4115 (Pressure sensor)

### MCAL (Microcontroller Abstraction Layer)
- GPIO
- ADC
- EEPROM
- External Interrupt Unit (EIU)

---

## 📂 File Structure
Fire-System/
├── HAL/                       # Hardware Abstraction Layer (modules for external devices)
│   ├── LCD/                   # LCD display driver
│   ├── KEYPAD/                # Keypad driver
│   ├── DC_MOTOR/              # DC motor (air conditioner) driver
│   ├── LED/                   # LED driver
│   ├── BUZZER/                # Buzzer driver
│   ├── SENSOR_LM35/           # Temperature sensor driver
│   ├── SENSOR_MQ2/            # Smoke sensor driver
│   └── SENSOR_MPX4115/        # Pressure sensor driver
│
├── MCAL/                      # Microcontroller Abstraction Layer (low-level drivers)
│   ├── GPIO/                  # Digital I/O configuration
│   ├── ADC/                   # Analog to Digital Converter driver
│   ├── EEPROM/                # EEPROM memory driver
│   └── EIU/                   # External Interrupt Unit driver
│
├── APP/                       # Application layer (main logic and system control)
│   └── main.c                 # Entry point and main control logic
│
├── CONFIG/                    # Configuration headers (constants, macros, settings)
│
├── include/                   # Shared header files
│
├── README.md                  # Project documentation
└── LICENSE                    # License file

## 📹 Demo Video

🎥 Click to watch the test demo:

[▶️ Watch Demo](Demo Video/Fire System.mp4)
