#include "FractalRenderer.h"

FractalRenderer::FractalRenderer(std::unique_ptr<IFractal> fractal,
    std::unique_ptr<IBufferedImage> image, size_t depth)
    : fractal(std::move(fractal)), image(std::move(image)), depth(depth) {
}

const IFractal* FractalRenderer::get_fractal() const {
    return this->fractal.get();
}

const IBufferedImage* FractalRenderer::get_image() const {
    return this->image.get();
}

void FractalRenderer::render() {
    size_t width = this->image->get_width();
    size_t height = this->image->get_height();

    for (size_t i = 0; i < height; i++) {
        for (size_t j = 0; j < width; j++) {
            Complex<double> point;

            point.set_x((double)j / width // [0, 1)
                * (this->fractal->get_max_x() - this->fractal->get_min_x()) // [min, max)
                + this->fractal->get_min_x()); // offset
            point.set_y((double)i / height // [0, 1)
                * (this->fractal->get_max_y() - this->fractal->get_min_y()) // [min, max)
                + this->fractal->get_min_y()); // offset

            uint8_t val = this->fractal->compute_at_point(point, this->depth);
            val = (uint8_t)((double)val/depth*255);
            this->image->set_pixel(j, i, val);
        }
    }
}
