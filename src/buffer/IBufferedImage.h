#pragma once

#include <cstdint>

class IBufferedImage {
public:
    virtual ~IBufferedImage() = default;

    virtual size_t get_width() const = 0;
    virtual size_t get_height() const = 0;
    virtual const uint8_t* get_buffer() const = 0;

    virtual void set_pixel(size_t x, size_t y, uint8_t value) = 0;
    virtual uint8_t get_pixel(size_t x, size_t y) const = 0;
};