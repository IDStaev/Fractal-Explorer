#include "GridRenderer.h"

#include <utility>

GridRenderer::GridRenderer(std::shared_ptr<IBufferedImage> image, size_t x, size_t y)
    : image(std::move(image)), x(0), y(0) {
    set_x(x);
    set_y(y);
}

void GridRenderer::render() {
    size_t width = this->image->get_width();
    size_t height = this->image->get_height();

    // Draw horizontal line
    for (int i = 0; i < width; i++) {
        this->image->set_pixel(i, x, {255, 0, 0, 255});
    }

    // Draw vertical line
    for (int i = 0; i < height; i++) {
        this->image->set_pixel(y, i, {255, 0, 0, 255});
    }
}

const IBufferedImage * GridRenderer::get_image() const {
    return this->image.get();
}

void GridRenderer::set_x(size_t x) {
    if (is_valid_x(x)) {
        this->x = x;
    }
}

void GridRenderer::set_y(size_t y) {
    if (is_valid_y(y)) {
        this->y = y;
    }
}

bool GridRenderer::is_valid_x(size_t x) const {
    return (x < this->image->get_width());
}

bool GridRenderer::is_valid_y(size_t y) const {
    return (y < this->image->get_height());
}
