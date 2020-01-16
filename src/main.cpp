#include <Arduino.h>

#define TRIG_PIN 11
#define ECHO_PIN 12

long cm;

void setup() {
    Serial.begin (9600);
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
}

void loop() {

    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(5);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    cm = pulseIn(ECHO_PIN, HIGH) / 2 / 29.1;

    Serial.print(cm);
    Serial.println(" cm");

    delay(250);
}
