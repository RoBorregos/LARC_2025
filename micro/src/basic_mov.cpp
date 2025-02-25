#include <Arduino.h>

// Define motor pins
const int M1_1 = 2;
const int M1_2 = 3;
const int M2_1 = 4;
const int M2_2 = 5;
const int M3_1 = 6;
const int M3_2 = 7;
const int M4_1 = 8;
const int M4_2 = 9;

void setup() {

    pinMode(M1_!, OUTPUT);
    pinMode(M1_2, OUTPUT);
    pinMode(M2_1, OUTPUT);
    pinMode(M2_2, OUTPUT);
    pinMode(M3_1, OUTPUT);
    pinMode(M3_2, OUTPUT);
    pinMode(M4_1, OUTPUT);
    pinMode(M4_2, OUTPUT);

}

void loop() {

    Forward();
    Stop();
    Backwards();
        
}

void Forward(){

    digitalWrite(M1_1, HIGH);
    digitalWrite(M1_2, LOW);
    digitalWrite(M2_1, HIGH);
    digitalWrite(M2_2, LOW);
    digitalWrite(M3_1, HIGH);
    digitalWrite(M3_2, LOW);
    digitalWrite(M4_1, HIGH);
    digitalWrite(M4_2, LOW);
    delay(2000);
}

void Stop(){
    digitalWrite(M1_1, LOW);
    digitalWrite(M1_2, LOW);
    digitalWrite(M2_1, LOW);
    digitalWrite(M2_2, LOW);
    digitalWrite(M3_1, LOW);
    digitalWrite(M3_2, LOW);
    digitalWrite(M4_1, LOW);
    digitalWrite(M4_2, LOW);
    delay(1000); 
}

void Backwards(){
    digitalWrite(M1_1, LOW);
    digitalWrite(M1_2, HIGH);
    digitalWrite(M2_1, LOW);
    digitalWrite(M2_2, HIGH);
    digitalWrite(M3_1, LOW);
    digitalWrite(M3_2, HIGH);
    digitalWrite(M4_1, LOW);
    digitalWrite(M4_2, HIGH);
    delay(2000);
}