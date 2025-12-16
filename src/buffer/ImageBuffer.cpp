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

void BufferedImage::set_pixel(size_t x, size_t y, uint8_t value) {
    if (!is_in_bound(x, y)) {
        throw std::out_of_range("Coordinates are out of bound.");
    }

    // TODO: ??????? Abstract away
    this->buffer[to_image_coord(x, y)] = value;
    this->buffer[to_image_coord(x, y) + 1] = value;
    this->buffer[to_image_coord(x, y) + 2] = value;
    this->buffer[to_image_coord(x, y) + 3] = value;
}

uint8_t BufferedImage::get_pixel(size_t x, size_t y) const {
    if (!is_in_bound(x, y)) {
        throw std::out_of_range("Coordinates are out of bound.");
    }

    return this->buffer[to_image_coord(x, y)];
}

bool BufferedImage::is_in_bound(size_t x, size_t y) const {
    return (x < width && y < height);
}

long long BufferedImage::to_image_coord(size_t x, size_t y) const {
    return (y * this->width + x) * 4;
}
