//
// Created by Ivan on 23/12/2025.
//

#include "FractalView.h"

#include "../fractal/IFractal.h"

FractalView::FractalView(std::unique_ptr<IFractal> fractal)
    : fractal(std::move(fractal)) {
}

double FractalView::get_min_x() const {
    return this->min_x;
}

double FractalView::get_max_x() const {
    return this->max_x;
}

double FractalView::get_min_y() const {
    return this->min_y;
}

double FractalView::get_max_y() const {
    return this->max_y;
}

void FractalView::set_min_x(double x) {
    this->min_x = x;
}

void FractalView::set_max_x(double x) {
    this->max_x = x;
}

void FractalView::set_min_y(double y) {
    this->min_y = y;
}

void FractalView::set_max_y(double y) {
    this->max_y = y;
}

const IFractal * FractalView::get_fractal() const {
    return this->fractal.get();
}

