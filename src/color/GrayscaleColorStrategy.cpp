#include "GrayscaleColorStrategy.h"

Pixel GrayscaleColorStrategy::get_color(uint8_t iteration, uint8_t max_iteration) const {
    uint8_t color = (double) iteration / max_iteration * 255; // [0, 255]
    return {color, color, color, 255};
}
