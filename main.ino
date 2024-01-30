const int fireSensorDigitalPin = 2;
const int relayIN2Pin = 7;
const int buzzerPin = 8;
const int fireSensorAnalogPin = A0;

void setup() {
  pinMode(fireSensorDigitalPin, INPUT);
  pinMode(relayIN2Pin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int fireSensorDigitalValue = digitalRead(fireSensorDigitalPin);
  if (fireSensorDigitalValue == HIGH) {
    // Fire detected
    digitalWrite(relayIN2Pin, LOW);
    for (int i = 0; i < 10; i++) {
      digitalWrite(buzzerPin, HIGH);
      delay(100);
      digitalWrite(buzzerPin, LOW);
      delay(50);
    }

    Serial.println("Fire detected!");
    int fireSensorAnalogValue = analogRead(fireSensorAnalogPin);
    Serial.print("Analog value: ");
    Serial.println(fireSensorAnalogValue);
  } else {
        // Fire Not detected
    digitalWrite(relayIN2Pin, HIGH);
    digitalWrite(buzzerPin, LOW);
  }
}
