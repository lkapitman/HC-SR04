#include <Arduino.h>
#include <Servo.h>

#define TRIG_PIN 11
#define ECHO_PIN 12

Servo myservo;

int pos = 0;

long cm;

void servo() {
    for(pos = 180; pos>=0; pos-=1) {
        myservo.write(pos);
        delay(15);
    }

    for(pos = 0; pos <= 180; pos += 1) {
        myservo.write(pos);
        delay(15);
    }
}

void setup() {
    Serial.begin (9600);
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    myservo.attach(9);
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
    servo();
}
