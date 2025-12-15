#pragma once
#include <cstdint>
#include "IBufferedImage.h"

class BufferedImage : public IBufferedImage {
public:
    BufferedImage(size_t width, size_t height);
    //ImageBuffer(size_t width, size_t height, const uint8_t* src);
    ~BufferedImage() override;

    size_t get_width() const override;
    size_t get_height() const override;
    const uint8_t* get_buffer() const override;

    void set_pixel(size_t x, size_t y, uint8_t value) override;
    uint8_t get_pixel(size_t x, size_t y) const override;


private:
    size_t width;
    size_t height;

    uint8_t* buffer;

    bool is_in_bound(size_t x, size_t y) const;
    long long to_image_coord(size_t x, size_t y) const;
};