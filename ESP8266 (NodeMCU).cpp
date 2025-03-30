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
