#include "FractalRenderer.h"

FractalRenderer::FractalRenderer(std::unique_ptr<FractalView> fractal_view,
                                 std::shared_ptr<IBufferedImage> image,
                                 std::unique_ptr<IColorStrategy> color_strategy, size_t depth)
    : fractal_view(std::move(fractal_view)), image(std::move(image)),
      color_strategy(std::move(color_strategy)), depth(depth) {
}

const FractalView *FractalRenderer::get_fractal_view() const {
    return this->fractal_view.get();
}

const IBufferedImage *FractalRenderer::get_image() const {
    return this->image.get();
}

void FractalRenderer::render() {
    size_t width = this->image->get_width();
    size_t height = this->image->get_height();

    double min_x = fractal_view->get_min_x();
    double max_x = fractal_view->get_max_x();
    double min_y = fractal_view->get_min_y();
    double max_y = fractal_view->get_max_y();

    const IFractal* fractal = this->fractal_view->get_fractal();

    for (size_t i = 0; i < height; i++) {
        for (size_t j = 0; j < width; j++) {

            Complex<double> point;

            point.set_x((double) j / width // [0, 1)
                        * (max_x - min_x) // [min, max)
                        + min_x); // offset

            point.set_y((double) i / height // [0, 1)
                        * (max_y - min_y) // [min, max)
                        + min_y); // offset

            uint8_t val = fractal->compute_at_point(point, this->depth);
            Pixel pixel = this->color_strategy->get_color(val, this->depth);
            this->image->set_pixel(j, i, pixel);
        }
    }

    for (int i = 0; i < width; i++) {
        this->image->set_pixel(i, height / 2, {255, 0, 0, 255});
    }

    for (int i = 0; i < height; i++) {
        this->image->set_pixel(width / 2, i, {255, 0, 0, 255});
    }
}
