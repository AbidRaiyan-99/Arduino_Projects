# 📏 Ultrasonic Distance Sensor with Servo Motor

An Arduino-based distance measurement and object indication system designed and simulated in **Tinkercad**. The project uses an HC-SR04 ultrasonic sensor to measure the distance of an object and controls a servo motor and three LEDs based on the measured distance.

---

## 📌 Features

- 📡 Real-time distance measurement using an HC-SR04 ultrasonic sensor
- 🔴🔶🟢 Three-level LED indication based on object distance
- ⚙️ Servo motor rotates to different angles according to the detected distance
- 💻 Serial Monitor displays live distance readings
- 🛠️ Designed and simulated in Tinkercad

---

## 🛠 Components Used

- Arduino Uno
- HC-SR04 Ultrasonic Sensor
- Servo Motor
- Red LED
- Orange LED
- Green LED
- Resistors
- Breadboard
- Jumper Wires

---

## ⚙️ Working Principle

- The HC-SR04 ultrasonic sensor continuously measures the distance to an object.
- Depending on the measured distance:
  - **Less than 10 cm**
    - Red LED turns ON
    - Servo rotates to **180°**
  - **Between 10 cm and 20 cm**
    - Orange LED turns ON
    - Servo rotates to **90°**
  - **Greater than 20 cm**
    - Green LED turns ON
    - Servo returns to **0°**
- The measured distance is displayed in the Arduino Serial Monitor.

---

## 📂 Files

- `UltrasonicServo.ino` – Arduino source code
- `circuit.png` – Tinkercad circuit screenshot

---

## ▶️ Tinkercad Simulation

https://www.tinkercad.com/things/8KWKKqeZBV0-ultrasonic-distance-sensorservo

---

## 🚀 Future Improvements

- Add an LCD or OLED display
- Add a buzzer for obstacle alerts
- Display distance graphically
- Wireless monitoring using Bluetooth or Wi-Fi
- Integrate with a robotic arm or smart parking system

---

## 👨‍💻 Author

**Abid Raiyan Ayon**

Computer Science & Engineering Student
