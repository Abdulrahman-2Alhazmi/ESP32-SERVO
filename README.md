# ESP32 Servo Web Controller

A web-based servo control system using an ESP32 (WeMos). The ESP32 creates its own Wi-Fi Access Point, allowing users to control a servo motor through a web browser without requiring an Internet connection. The system also uses LED indicators to display the servo status.

---

## 📖 Project Overview

This project demonstrates how to:

- Create a Wi-Fi Access Point using ESP32.
- Host a web page directly on the ESP32.
- Control a servo motor remotely.
- Display the servo status using LED indicators.
- Access the control page from both smartphones and laptops.

---

## ✨ Features

- 📶 ESP32 Wi-Fi Access Point
- 🌐 Browser-based control interface
- ⚙️ Servo motor control
- 🔵 Blue LED indicator for **Open**
- 🔴 Red LED indicator for **Close**
- 📱 Compatible with smartphones
- 💻 Compatible with laptops
- 🌍 No Internet connection required

---

## 🛠 Hardware Components

- ESP32 (WeMos)
- Servo Motor
- Blue LED
- Red LED
- 220Ω Resistors
- Jumper Wires
- USB Cable

---

## 📡 Wi-Fi Configuration

| Setting | Value |
|----------|-------|
| SSID | ESP32-Servo |
| Password | 12345678 |

---

## 🔌 Pin Connections

| Component | ESP32 Pin |
|-----------|-----------|
| Servo Signal | GPIO 18 |
| Blue LED | GPIO 27 |
| Red LED | GPIO 26 |
| Servo VCC | 5V |
| Servo GND | GND |
| LEDs GND | GND |

---

## 🚀 How to Run

1. Upload the Arduino code to the ESP32.
2. Connect the ESP32 using USB power.
3. Connect your phone or laptop to:

**SSID**

```text
ESP32-Servo
```

**Password**

```text
12345678
```

4. Open your browser and visit:

```text
http://192.168.4.1
```

5. Use the **Open** and **Close** buttons to control the servo.

---

## 🎥 Simulation Video

Watch the simulation here:

▶️ **[Watch the Simulation Video](https://YOUR_SIMULATION_VIDEO_LINK)**

---

## 🎥 Real Project Demonstration

Watch the real hardware implementation here:

▶️ **[Watch the Real Project Demonstration](https://youtu.be/k0fvWiI7dZY)**

---

## 🌐 Cirkit Designer Project

View the simulation design here:

🔗 **[Open the Cirkit Designer Project]([https://app.cirkitdesigner.com/project/YOUR_PROJECT_LINK](https://wokwi.com/projects/470877376494686209))**

---

## ⚠ Challenges Encountered

### 1. Green LED Not Available

A green LED was not available during the implementation.

**Solution**

A blue LED was used instead to indicate the **Open** state.

---

### 2. Damaged LEDs

During testing, one red LED and one blue LED were defective and had to be replaced.

---

### 3. ESP32 Heating

The ESP32 became warm while testing the Wi-Fi Access Point.

**Solution**

The board was disconnected immediately, all wiring was inspected, and testing continued only after verifying the hardware connections.

---

### 4. Missing ESP32Servo Library

Compilation failed because the required **ESP32Servo** library was missing.

**Solution**

The library was installed using the Arduino IDE Library Manager.

---

### 5. Web Interface Not Loading

Initially, the ESP32 created a Wi-Fi network but did not display a web page.

**Solution**

A WebServer was implemented to host the browser-based control interface.

---

## 📂 Project Structure

```
ESP32-Servo-Web-Control
│
├── README.md
├── ESP32_Servo_Web.ino
├── images
├── simulation
└── videos
```

---

## 💡 Future Improvements

- Add a login page.
- Add a servo angle slider.
- Support multiple servo motors.
- Improve the user interface.
- Display real-time servo status.
- Add IoT cloud connectivity.

---

## 👨‍💻 Author

**Abdulrahman Alhazmi**
