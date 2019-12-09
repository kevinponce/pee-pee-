// Water Sensor + to Arduino 5V
// Water Sensor - to Arduino GND
// Water Sensor S to Arduino A5

// Water Sensor S to Arduino A4
// Water Sensor S to Arduino A3
// Water Sensor S to Arduino A2

// Relay VCC to Arduino 5V
// Relay GND to Arduino GND
// Relay IN1 to Arduino 7

#define Relay 7
#define FIRE_THRESHOLD 500

boolean firing = false;

void setup() {
  Serial.begin(9600);
  pinMode(Relay, OUTPUT);
}

void waterOn() {
  digitalWrite(Relay, HIGH);
}

void waterOff() {
  digitalWrite(Relay, LOW);
}

void loop() {
  int fireSensor1 = analogRead(5) > FIRE_THRESHOLD;
  int fireSensor2 = analogRead(4) > FIRE_THRESHOLD;
  int fireSensor3 = analogRead(3) > FIRE_THRESHOLD;
  int fireSensor4 = analogRead(2) > FIRE_THRESHOLD;

  if (fireSensor1 || fireSensor2 || fireSensor3 || fireSensor4) {
    if (!firing) {
      firing = true;
      waterOn();
      Serial.println("fire");
     }
  } else if (firing) {
    firing = false;
    waterOff();
    Serial.println("stop fire");
  }
}
