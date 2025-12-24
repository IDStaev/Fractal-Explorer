#pragma once
#include <memory>

#include "../buffer/IBufferedImage.h"
#include "../fractal/IFractal.h"

// Gives space to the fractal
class FractalView {
public:
    FractalView(std::unique_ptr<IFractal> image);

    double get_min_x() const;
    double get_max_x() const;
    double get_min_y() const;
    double get_max_y() const;

    void set_min_x(double x);
    void set_max_x(double x);
    void set_min_y(double y);
    void set_max_y(double y);

    const IFractal* get_fractal() const;

private:
    double min_x;
    double max_x;
    double min_y;
    double max_y;

    std::unique_ptr<IFractal> fractal;
};
