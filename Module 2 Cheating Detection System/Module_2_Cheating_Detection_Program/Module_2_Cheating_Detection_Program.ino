// --- Pin Definitions ---
const int trigPin1 = 10;   // Sensor 1 Trigger
const int echoPin1 = 9;    // Sensor 1 Echo
const int trigPin2 = 8;    // Sensor 2 Trigger
const int echoPin2 = 7;    // Sensor 2 Echo

const int Motor = 11;      // Common LED
const int buzzer = 13;     // Buzzer

const int irPin1 = 6;      // IR Sensor 1
const int irPin2 = 2;      // IR Sensor 2

// --- LEDs ---
const int ledUS1 = 4;      // US1 LED
const int ledUS2 = 5;      // US2 LED
const int ledIR1 = 3;      // IR1 LED
const int ledIR2 = 12;     // IR2 LED
const int ledLDR = A1;     // LDR LED

// --- LDR ---
const int ldrPin = A0;     // LDR analog input
int ldrThreshold = 600;    // Adjust based on ambient light

// --- Variables ---
float distance1, distance2;
const float threshold = 16.0; // cm ultrasonic threshold

// --- Hold times (in ms) ---
const unsigned long ledHoldTime = 2000;   // LEDs stay ON for 2s
const unsigned long buzzerHoldTime = 500; // Buzzer stays ON for 0.5s

// --- Timers ---
unsigned long lastTriggerUS1 = 0;
unsigned long lastTriggerUS2 = 0;
unsigned long lastTriggerIR1 = 0;
unsigned long lastTriggerIR2 = 0;
unsigned long lastTriggerLDR = 0;
unsigned long lastTriggerAny = 0; // For buzzer & common LED

void setup() {
    pinMode(buzzer, OUTPUT);
    pinMode(Motor, OUTPUT);

    pinMode(trigPin1, OUTPUT);
    pinMode(echoPin1, INPUT);
    pinMode(trigPin2, OUTPUT);
    pinMode(echoPin2, INPUT);

    pinMode(irPin1, INPUT);
    pinMode(irPin2, INPUT);

    pinMode(ledUS1, OUTPUT);
    pinMode(ledUS2, OUTPUT);
    pinMode(ledIR1, OUTPUT);
    pinMode(ledIR2, OUTPUT);
    pinMode(ledLDR, OUTPUT);

    Serial.begin(9600);
}

void loop() {
    unsigned long currentMillis = millis();

    // --- Read ultrasonic sensors ---
    distance1 = measureDistance(trigPin1, echoPin1);
    distance2 = measureDistance(trigPin2, echoPin2);

    bool sensor1Detected = (distance1 <= threshold);
    bool sensor2Detected = (distance2 <= threshold);

    // --- Read IR sensors ---
    bool ir1Detected = (digitalRead(irPin1) == LOW);
    bool ir2Detected = (digitalRead(irPin2) == LOW);

    // --- Read LDR ---
    int ldrValue = analogRead(ldrPin);
    bool ldrDetected = (ldrValue > ldrThreshold);

    // --- Debug Print ---
    Serial.print("US1: ");
    Serial.print(distance1, 1);
    Serial.print(" | US2: ");
    Serial.print(distance2, 1);
    Serial.print(" | IR1: ");
    Serial.print(ir1Detected ? "D" : "C");
    Serial.print(" | IR2: ");
    Serial.print(ir2Detected ? "D" : "C");
    Serial.print(" | LDR: ");
    Serial.print(ldrValue);
    Serial.println(ldrDetected ? " -> Bright" : " -> Normal");

    // --- Update timers when detection happens ---
    if (sensor1Detected) lastTriggerUS1 = currentMillis;
    if (sensor2Detected) lastTriggerUS2 = currentMillis;
    if (ir1Detected)     lastTriggerIR1 = currentMillis;
    if (ir2Detected)     lastTriggerIR2 = currentMillis;
    if (ldrDetected)     lastTriggerLDR = currentMillis;

    if (sensor1Detected || sensor2Detected || ir1Detected || ir2Detected || ldrDetected) {
        lastTriggerAny = currentMillis;
    }

    // --- Control LEDs with hold time ---
    digitalWrite(ledUS1, (currentMillis - lastTriggerUS1 < ledHoldTime) ? HIGH : LOW);
    digitalWrite(ledUS2, (currentMillis - lastTriggerUS2 < ledHoldTime) ? HIGH : LOW);
    digitalWrite(ledIR1, (currentMillis - lastTriggerIR1 < ledHoldTime) ? HIGH : LOW);
    digitalWrite(ledIR2, (currentMillis - lastTriggerIR2 < ledHoldTime) ? HIGH : LOW);
    digitalWrite(ledLDR, (currentMillis - lastTriggerLDR < ledHoldTime) ? HIGH : LOW);

    // --- Common LED ---
    digitalWrite(Motor, (currentMillis - lastTriggerAny < ledHoldTime) ? HIGH : LOW);

    // --- Buzzer ---
    digitalWrite(buzzer, (currentMillis - lastTriggerAny < buzzerHoldTime) ? HIGH : LOW);

    delay(50); // Small delay
}

// --- Function to measure distance from ultrasonic sensor ---
float measureDistance(int trigPin, int echoPin) {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    long duration = pulseIn(echoPin, HIGH, 20000); // timeout 20ms
    if (duration == 0) return 999; // No object detected

    return duration * 0.0343 / 2.0; // convert to cm
}
