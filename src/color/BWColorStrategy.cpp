#include "BWColorStrategy.h"

Pixel BWColorStrategy::get_color(uint8_t iteration, uint8_t max_iteration) const {
    uint8_t color = (iteration == max_iteration) ? 255 : 0;
    return Pixel(color, color, color, 255);
}
