#ifndef COLORSENSING_H
#define COLORSENSING_H

#include <Arduino.h>
#include <Adafruit_TCS34725.h>
#include <ColorConverterLib.h>

class ColorSensing {
public:
    ColorSensing();
    void begin();
    String getColor();¿

private:
    Adafruit_TCS34725 tcs;
};

#endif