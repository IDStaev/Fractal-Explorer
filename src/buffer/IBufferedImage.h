#pragma once

#include <cstdint>
#include "../pixel/Pixel.h"

class IBufferedImage {
public:
    virtual ~IBufferedImage() = default;

    virtual size_t get_width() const = 0;
    virtual size_t get_height() const = 0;
    virtual const uint8_t* get_buffer() const = 0;

    virtual void set_pixel(size_t x, size_t y, const Pixel& pixel) = 0;
    virtual Pixel get_pixel(size_t x, size_t y) const = 0;
};