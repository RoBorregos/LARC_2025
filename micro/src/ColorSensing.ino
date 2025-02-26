#include <Wire.h>
#include "Adafruit_TCS34725.h"
#include "ColorConverterLib.h"

void setup(){
  Serial.begin(9600);

  if (!tcs.begin())
  {
    Serial.println("Error al iniciar TCS34725");
    while (1) delay(1000);
  }
}

void loop(){
    string color = getColor();
    delay(1000);
}

string getColor() {
    // Código basado mayormente en https://www.luisllamas.es/en/arduino-rgb-color-sensor-tcs34725/
    uint16_t clear, red, green, blue;

    tcs.setInterrupt(false);
    delay(60); // Takes 50ms to capture the color
    tcs.getRawData(&red, &green, &blue, &clear);
    tcs.setInterrupt(true);

    // Make rgb measurement relative
    uint32_t sum = clear;
    float r, g, b;
    r = red; r /= sum;
    g = green; g /= sum;
    b = blue; b /= sum;

    // Scale rgb to bytes
    r *= 256; g *= 256; b *= 256;

    // Convert to hue, saturation, value
    double hue, saturation, value;
    ColorConverter::RgbToHsv(static_cast<uint8_t>(r), static_cast<uint8_t>(g), static_cast<uint8_t>(b), hue, saturation, value);

    // Show color name
    return commonColor(hue * 360);
}

string commonColor(double hue){
    // Valores encontrados después de probar.
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