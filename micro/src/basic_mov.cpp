#include <Arduino.h>

const int IN1_1 = 2;
const int IN1_2 = 3;
const int IN2_1 = 4;
const int IN2_2 = 5;
const int IN3_1 = 6;
const int IN3_2 = 7;
const int IN4_1 = 8;
const int IN4_2 = 9;

const int ENCODER1_A = 10;
const int ENCODER1_B = 11;
const int ENCODER2_A = 12;
const int ENCODER2_B = 13;

const int PWM_1 = 14;
const int PWM_2 = 15;
const int PWM_3 = 16;
const int PWM_4 = 17;

volatile long encoder1Pos = 0;
volatile long encoder2Pos = 0;

void setup() {
    Serial.begin(9600);

    pinMode(IN1_1, OUTPUT);
    pinMode(IN1_2, OUTPUT);
    pinMode(IN2_1, OUTPUT);
    pinMode(IN2_2, OUTPUT);
    pinMode(IN3_1, OUTPUT);
    pinMode(IN3_2, OUTPUT);
    pinMode(IN4_1, OUTPUT);
    pinMode(IN4_2, OUTPUT);

    pinMode(PWM_1, OUTPUT);
    pinMode(PWM_2, OUTPUT);
    pinMode(PWM_3, OUTPUT);
    pinMode(PWM_4, OUTPUT);

    setupEncoders();
}

void loop() {
    Forward();
    Stop();
    Backwards();
}

void Forward() {
    digitalWrite(IN1_1, HIGH);
    digitalWrite(IN1_2, LOW);
    digitalWrite(IN2_1, HIGH);
    digitalWrite(IN2_2, LOW);
    digitalWrite(IN3_1, HIGH);
    digitalWrite(IN3_2, LOW);
    digitalWrite(IN4_1, HIGH);
    digitalWrite(IN4_2, LOW);
    analogWrite(PWM_1, 255);
    analogWrite(PWM_2, 255);
    analogWrite(PWM_3, 255);
    analogWrite(PWM_4, 255);
    delay(2000);
    printStatus();
}

void Stop() {
    digitalWrite(IN1_1, LOW);
    digitalWrite(IN1_2, LOW);
    digitalWrite(IN2_1, LOW);
    digitalWrite(IN2_2, LOW);
    digitalWrite(IN3_1, LOW);
    digitalWrite(IN3_2, LOW);
    digitalWrite(IN4_1, LOW);
    digitalWrite(IN4_2, LOW);
    analogWrite(PWM_1, 0);
    analogWrite(PWM_2, 0);
    analogWrite(PWM_3, 0);
    analogWrite(PWM_4, 0);
    delay(1000);
    printStatus();
}

void Backwards() {
    digitalWrite(IN1_1, LOW);
    digitalWrite(IN1_2, HIGH);
    digitalWrite(IN2_1, LOW);
    digitalWrite(IN2_2, HIGH);
    digitalWrite(IN3_1, LOW);
    digitalWrite(IN3_2, HIGH);
    digitalWrite(IN4_1, LOW);
    digitalWrite(IN4_2, HIGH);
    analogWrite(PWM_1, 255);
    analogWrite(PWM_2, 255);
    analogWrite(PWM_3, 255);
    analogWrite(PWM_4, 255);
    delay(2000);
    printStatus();
}

void encoder1ISR() {
    if (digitalRead(ENCODER1_A) == digitalRead(ENCODER1_B)) {
        encoder1Pos++;
    } else {
        encoder1Pos--;
    }
}

void encoder2ISR() {
    if (digitalRead(ENCODER2_A) == digitalRead(ENCODER2_B)) {
        encoder2Pos++;
    } else {
        encoder2Pos--;
    }
}

void setupEncoders() {
    pinMode(ENCODER1_A, INPUT);
    pinMode(ENCODER1_B, INPUT);
    pinMode(ENCODER2_A, INPUT);
    pinMode(ENCODER2_B, INPUT);

    attachInterrupt(digitalPinToInterrupt(ENCODER1_A), encoder1ISR, CHANGE);
    attachInterrupt(digitalPinToInterrupt(ENCODER2_A), encoder2ISR, CHANGE);
}

void printStatus() {
    Serial.print("Encoder 1 Position: ");
    Serial.println(encoder1Pos);
    Serial.print("Encoder 2 Position: ");
    Serial.println(encoder2Pos);
    Serial.print("PWM 1 Value: ");
    Serial.println(analogRead(PWM_1));
    Serial.print("PWM 2 Value: ");
    Serial.println(analogRead(PWM_2));
    Serial.print("PWM 3 Value: ");
    Serial.println(analogRead(PWM_3));
    Serial.print("PWM 4 Value: ");
    Serial.println(analogRead(PWM_4));
}