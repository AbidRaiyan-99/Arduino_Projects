# 🔥 Fire Fighting Robot using Arduino

An Arduino-based autonomous fire-fighting robot designed and simulated in **Tinkercad**. The robot combines obstacle avoidance and fire detection to navigate safely and respond automatically when a fire is detected.

---

## 📌 Features

- 🚗 Autonomous obstacle avoidance using an HC-SR04 ultrasonic sensor
- 🔥 Fire detection using a flame sensor
- 💨 Servo motor simulates a water sprinkler/fire extinguisher
- 📟 16×2 LCD displays system status
- 🤖 Automatic forward, backward, and left-turn navigation
- 📡 Real-time monitoring through the Serial Monitor

---

## 🛠 Components Used

- Arduino Uno
- HC-SR04 Ultrasonic Sensor
- Flame Sensor
- Servo Motor
- 16×2 LCD Display
- DC Motors
- Motor Driver (L293D/L298N)
- Jumper Wires
- Breadboard

---

## ⚙️ Working Principle

1. The ultrasonic sensor continuously measures the distance to obstacles.
2. If an obstacle is detected within 20 cm, the robot:
   - Stops
   - Moves backward
   - Turns left
   - Continues moving
3. The flame sensor continuously checks for fire.
4. When fire is detected:
   - An alert is displayed on the LCD.
   - The servo motor rotates to simulate extinguishing the fire.
5. If no fire is detected, the LCD displays normal system status.

---

## 📂 Files

- `FireFightingRobot.ino` – Arduino source code
- `circuit.png` – Tinkercad circuit screenshot

---

## ▶️ Tinkercad Simulation

https://www.tinkercad.com/things/iWsb5HaSwX2-fire-fighting-robot-project?sharecode=6T5wIBr2uRA01I6a1XQZG1t6HCPdGGnO-o2MveaE6JM

---

## 🚀 Future Improvements

- Bluetooth/Wi-Fi remote monitoring
- Automatic water pump control
- GPS navigation
- Smoke and gas sensors
- Machine vision for flame detection

---

## 👨‍💻 Author

**Abid Raiyan Ayon**

Computer Science & Engineering Student
