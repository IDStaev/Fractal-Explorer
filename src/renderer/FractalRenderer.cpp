#include "FractalRenderer.h"

FractalRenderer::FractalRenderer(std::unique_ptr<IFractal> fractal, std::unique_ptr<IBufferedImage> image)
    : fractal(std::move(fractal)), image(std::move(image)) {
}

const IFractal* FractalRenderer::get_fractal() const {
    return this->fractal.get();
}

const IBufferedImage* FractalRenderer::get_image() const {
    return this->image.get();
}

void FractalRenderer::render() {
    double width = this->image->get_width();
    double height = this->image->get_height();

    for (size_t i = 0; i < height; i++) {
        for (size_t j = 0; j < width; j++) {
            Complex<double> point;
            point.set_x(j / width // [0, 1)
                * (this->fractal->get_max_x() - this->fractal->get_min_x()) // [min, max)
                + this->fractal->get_min_x()); // offset
            point.set_y(i / height // [0, 1)
                * (this->fractal->get_max_y() - this->fractal->get_min_y()) // [min, max)
                + this->fractal->get_min_y()); // offset

            uint8_t val = this->fractal->compute_at_point(point, 10); // TODO: not constant
            this->image->set_pixel(j, i, val == 10 ? 0 : val);
        }
    }
}
