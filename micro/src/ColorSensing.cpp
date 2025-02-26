#include "ColorSensing.h"
#include <Wire.h>
#include <Adafruit_TCS34725.h>
#include <ColorConverterLib.h>

// Constructor
ColorSensing::ColorSensing()
    : tcs(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_1X) {}

// Initialization function, replacing setup.
void ColorSensing::begin() {
    Serial.begin(9600);
    if (!tcs.begin()) {
        Serial.println("Error initializing TCS34725");
        while (1) delay(1000);
    }
}

// Function to get color.
string ColorSensing::getColor(Adafruit_TCS34725 tcs) {
    uint16_t clear, red, green, blue;
    tcs.setInterrupt(false);
    delay(60); 
    
    // Capture color.
    tcs.getRawData(&red, &green, &blue, &clear);
    tcs.setInterrupt(true);

    // Normalize RGB values.
    uint32_t sum = clear;
    float r = red / (float)sum;
    float g = green / (float)sum;
    float b = blue / (float)sum;
    r *= 256; g *= 256; b *= 256;

    // Convert to HSV.
    double hue, saturation, value;
    ColorConverter::RGBtoHSV(r, g, b, hue, saturation, value);

    // Return color based on tested values.
    if (hue > 30 && hue < 105) {
        return "Yellow";
    }
    else if (hue > 222 && hue < 265) {
        return "Purple";
    }
    else if (hue > 195 && hue < 222) {
        return "Blue";
    }
    else if (hue > 300 && hue < 350) {
        return "Pink";
    }
    else if (hue > 0 && hue < 25) {
        return "Red";
    }
    else if (hue > 120 && hue < 160) {
        return "Green";
    }
    else {
        return "None of the above";
    }
}