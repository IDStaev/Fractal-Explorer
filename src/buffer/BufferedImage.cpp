#include "BufferedImage.h"
#include <stdexcept>

BufferedImage::BufferedImage(size_t width, size_t height) {
    this->width = width;
    this->height = height;

    this->buffer = new uint8_t[width * height * 4]{};
}

BufferedImage::~BufferedImage() {
    delete[] this->buffer;
}

size_t BufferedImage::get_width() const {
    return this->width;
}

size_t BufferedImage::get_height() const {
    return this->height;
}

const uint8_t* BufferedImage::get_buffer() const {
    return this->buffer;
}

void BufferedImage::set_pixel(size_t x, size_t y, const Pixel& pixel) {
    if (!is_in_bound(x, y)) {
        throw std::out_of_range("Coordinates are out of bound.");
    }

    this->buffer[to_image_coord(x, y)] = pixel.r;
    this->buffer[to_image_coord(x, y) + 1] = pixel.g;
    this->buffer[to_image_coord(x, y) + 2] = pixel.b;
    this->buffer[to_image_coord(x, y) + 3] = pixel.a;
}

Pixel BufferedImage::get_pixel(size_t x, size_t y) const {
    if (!is_in_bound(x, y)) {
        throw std::out_of_range("Coordinates are out of bound.");
    }

    uint8_t r = this->buffer[to_image_coord(x, y)];
    uint8_t g = this->buffer[to_image_coord(x, y) + 1];
    uint8_t b = this->buffer[to_image_coord(x, y) + 2];
    uint8_t a = this->buffer[to_image_coord(x, y) + 3];

    return {r, g, b, a};
}

bool BufferedImage::is_in_bound(size_t x, size_t y) const {
    return (x < width && y < height);
}

long long BufferedImage::to_image_coord(size_t x, size_t y) const {
    return (this->width * y + x) * 4;
}
