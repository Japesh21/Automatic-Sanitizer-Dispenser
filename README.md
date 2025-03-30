Automatic Sanitizer Dispenser using ESP8266
🚀 A touchless sanitizer dispenser using ESP8266, IR Sensor, and Motor Driver.

📷 Project Overview
This project automates the dispensing of hand sanitizer using an infrared (IR) sensor to detect a hand, an ESP8266 (NodeMCU) to process the input, and a DC pump to dispense sanitizer.

🛠 Components Required
Component	Description
ESP8266 (NodeMCU)	Microcontroller for processing
IR Sensor	Detects hand presence
Motor Driver (L298N)	Controls the motor
12V DC Pump	Dispenses sanitizer
Power Supply	9V or 12V battery
⚡ Circuit Diagram
[Upload an image of your wiring diagram here]

Connections:

Component	ESP8266 Pin
IR Sensor VCC	3.3V
IR Sensor GND	GND
IR Sensor OUT	D2 (GPIO4)
Motor Driver IN1	D5 (GPIO14)
Motor Driver IN2	D6 (GPIO12)
Motor Driver VCC	VIN (or external 12V)
Motor Driver GND	GND
Pump Motor	Connected to Motor Driver Output
📜 Code
Here’s the main code for the ESP8266:

cpp
Copy
Edit
#define IR_SENSOR D2  // GPIO4 (IR Sensor Output)
#define MOTOR1 D5      // GPIO14 (Motor Driver IN1)
#define MOTOR2 D6      // GPIO12 (Motor Driver IN2)

void setup() {
    pinMode(IR_SENSOR, INPUT);
    pinMode(MOTOR1, OUTPUT);
    pinMode(MOTOR2, OUTPUT);
    digitalWrite(MOTOR1, LOW);
    digitalWrite(MOTOR2, LOW);
    Serial.begin(115200);
}

void loop() {
    int sensorValue = digitalRead(IR_SENSOR); // Read IR sensor
    
    if (sensorValue == LOW) {  // Object detected
        Serial.println("Hand detected! Pump ON");
        digitalWrite(MOTOR1, HIGH);
        digitalWrite(MOTOR2, LOW);
        delay(1000); // Run the pump for 1 second
        digitalWrite(MOTOR1, LOW);
        digitalWrite(MOTOR2, LOW);
    }
    delay(200); // Small delay to prevent false triggering
}
🚀 How to Use
Assemble the circuit following the wiring diagram.

Upload the code to your ESP8266 using Arduino IDE.

Power up the circuit (9V or 12V battery).

Place your hand near the IR sensor to dispense sanitizer.

The pump will turn ON for 1 second and then turn OFF.

📌 Features
✔️ Touchless Operation
✔️ Compact & Cost-Effective
✔️ ESP8266 for future IoT features
✔️ Expandable (WiFi, OLED display, etc.)
