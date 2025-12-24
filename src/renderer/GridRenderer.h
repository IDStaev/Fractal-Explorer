#pragma once
#include "IRenderer.h"

class GridRenderer : IRenderer {
public:
    GridRenderer(std::shared_ptr<IBufferedImage> image, size_t x, size_t y);

    void render() override;
    const IBufferedImage* get_image() const override;
    void set_x(size_t x);
    void set_y(size_t y);

private:
    std::shared_ptr<IBufferedImage> image;
    size_t x;
    size_t y;

    bool is_valid_x(size_t x) const;
    bool is_valid_y(size_t y) const;
};
