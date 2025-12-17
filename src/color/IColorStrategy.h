#pragma once

#include <cstdint>
#include "../pixel/Pixel.h"

class IColorStrategy {
public:
    virtual ~IColorStrategy() = default;

    virtual Pixel get_color(uint8_t iteration, uint8_t max_iteration) const = 0;
};