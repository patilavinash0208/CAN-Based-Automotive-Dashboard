# 🚗 CAN-Based Automotive Dashboard

> A distributed embedded systems project simulating real-time automotive ECU communication over a CAN bus using **three PIC18F4580 microcontrollers**.

![Platform](https://img.shields.io/badge/Platform-PIC18F4580-blue)
![Protocol](https://img.shields.io/badge/Protocol-CAN-orange)
![IDE](https://img.shields.io/badge/IDE-MPLAB%20X-red)
![Compiler](https://img.shields.io/badge/Compiler-XC8-green)
![Language](https://img.shields.io/badge/Language-Embedded%20C-yellow)

---

## 📖 Overview

The **CAN-Based Automotive Dashboard** simulates communication between multiple **Electronic Control Units (ECUs)** in a vehicle using the **Controller Area Network (CAN)** protocol.

The system continuously monitors vehicle parameters — 🏎️ **Speed**, ⚙️ **Gear Position**, 🔄 **RPM**, and 🚦 **Indicator Status** — transmits them over the CAN bus, and displays the received data on a Character LCD in real time.

This project showcases distributed embedded system design, CAN communication, peripheral interfacing, and modular firmware development across multiple microcontroller nodes.

---

## ✨ Features

- 🔁 Real-time CAN communication between three ECUs
- 🚀 Vehicle speed monitoring using ADC
- 🔄 RPM monitoring
- ⚙️ Gear position display
- 💡 Left, Right, and Hazard indicator control
- 🖥️ Character LCD–based dashboard
- 📡 CAN message transmission and reception
- 🧩 Multi-ECU architecture
- 🛠️ Modular firmware design

---

## 🏗️ System Architecture

```text
                    CAN BUS

     +---------------------------+
     |                           |
     |                           |
+-----------+             +-----------+
|   ECU1    |             |   ECU2    |
|-----------|             |-----------|
| Speed     |             | RPM       |
| Gear      |             | Indicator |
+-----------+             +-----------+
        \                     /
         \                   /
          \                 /
           \               /
            +-------------+
            |    ECU3     |
            |-------------|
            | Dashboard   |
            | LCD Display |
            | Indicator   |
            | LED Control |
            +-------------+
```

---

## 🧠 ECU Responsibilities

### 🟦 ECU1 — Speed & Gear Node
- Reads vehicle speed using ADC
- Reads gear position
- Transmits Speed and Gear data over CAN

### 🟧 ECU2 — RPM & Indicator Node
- Reads RPM using ADC
- Reads Left, Right, and Hazard switch inputs
- Transmits RPM and Indicator status over CAN

### 🟩 ECU3 — Dashboard Display Node
- Receives CAN messages from ECU1 and ECU2
- Displays Speed, Gear, RPM, and Indicator status on Character LCD
- Controls Indicator LEDs based on received CAN messages

---

## 🔧 Hardware Used

| Component | Quantity |
|---|---|
| 🧠 PIC18F4580 Microcontroller | 3 (one per node) |
| 📡 MCP2551 CAN Transceiver | 3 |
| 🖥️ Character LCD (16x2) | 1 |
| 🎚️ Potentiometers | 2 |
| 🔘 Push Buttons / Switches | Multiple |
| 💡 LEDs | Multiple |
| 🔌 CAN Bus Interface | 1 |

---

## 💻 Software Used

- 🧰 MPLAB X IDE
- ⚙️ XC8 Compiler
- 📝 Embedded C

---

## 🛠️ Technologies Used

`Embedded C` · `CAN Protocol` · `ADC` · `GPIO` · `Timers` · `Interrupts` · `MPLAB X IDE` · `XC8 Compiler`

---

## 📂 Repository Structure

```text
CAN-Based-Automotive-Dashboard
│
├── README.md
│
├── ECU1_Speed_Gear_Node.X
│   ├── nbproject
│   ├── main.c
│   ├── can.c
│   ├── adc.c
│   └── ...
│
├── ECU2_RPM_Indicator_Node.X
│   ├── nbproject
│   ├── main.c
│   ├── can.c
│   ├── adc.c
│   └── ...
│
├── ECU3_Dashboard_Display_Node.X
│   ├── nbproject
│   ├── main.c
│   ├── can.c
│   ├── clcd.c
│   ├── timer0.c
│   └── ...
│
└── Project_Images
```

---

## ⚙️ Working Principle

1. 🟦 **ECU1** continuously acquires vehicle Speed and Gear information and transmits the data over the CAN bus.
2. 🟧 **ECU2** acquires RPM and Indicator switch status and transmits them as CAN messages.
3. 🟩 **ECU3** receives messages from both ECUs, updates the Character LCD with real-time vehicle information, and controls the indicator LEDs accordingly.

The three ECUs communicate independently over the CAN network, simulating a distributed automotive embedded system. 🔁

---

## 🎓 Learning Outcomes

Through this project, hands-on experience was gained in:

- 📡 CAN Protocol implementation
- 🧩 Multi-ECU communication
- 🛠️ Embedded Firmware Development
- 🧠 PIC18F4580 Programming
- 🎚️ ADC Interfacing
- 🖥️ Character LCD Interfacing
- 🐞 Embedded Debugging
- 🔧 Hardware Troubleshooting
- 📦 Modular Firmware Design
- 🚗 Automotive Embedded System Architecture

---

## 🚀 Future Enhancements

- 🔍 OBD-II Diagnostics
- 💾 Data Logging using External EEPROM/SD Card
- ⏰ Real-time Clock integration
- 🖼️ TFT Display Dashboard
- 🧵 FreeRTOS-based implementation
- 📶 Wireless vehicle diagnostics

---

## 👤 Author

**Avinash Patil**

[![GitHub](https://img.shields.io/badge/GitHub-patilavinash0208-181717?logo=github)](https://github.com/patilavinash0208)
[![LinkedIn](https://img.shields.io/badge/LinkedIn-Avinash%20Patil-0A66C2?logo=linkedin)](https://www.linkedin.com/in/avinash-patil-873b9b227)

---

⭐ If you found this project interesting, consider giving it a star on GitHub!
