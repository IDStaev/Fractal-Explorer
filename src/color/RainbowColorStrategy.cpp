#include "RainbowColorStrategy.h"

#include <cmath>

Pixel RainbowColorStrategy::get_color(uint8_t iteration, uint8_t max_iteration) const {
    if (iteration == max_iteration) {
        return {0, 0, 0, 0}; // Black for points in the set
    }

    // Normalize iteration to [0, 1]
    float t = static_cast<float>(iteration) / max_iteration;

    // Map to full spectrum (0-360 degrees in HSV)
    float hue = t * 360.0f;

    // Convert HSV to RGB (Saturation=1, Value=1)
    float c = 1.0f;
    float x = c * (1.0f - std::abs(std::fmod(hue / 60.0f, 2.0f) - 1.0f));

    float r, g, b;
    if (hue < 60) {
        r = c; g = x; b = 0;
    } else if (hue < 120) {
        r = x; g = c; b = 0;
    } else if (hue < 180) {
        r = 0; g = c; b = x;
    } else if (hue < 240) {
        r = 0; g = x; b = c;
    } else if (hue < 300) {
        r = x; g = 0; b = c;
    } else {
        r = c; g = 0; b = x;
    }

    return {
        static_cast<uint8_t>(r * 255),
        static_cast<uint8_t>(g * 255),
        static_cast<uint8_t>(b * 255),
        255
    };
}
