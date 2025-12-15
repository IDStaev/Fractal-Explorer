#include "MandelbrotSet.h"
#include <cstdint>

int MandelbrotSet::get_min_x() const
{
    return -2;
}

int MandelbrotSet::get_max_x() const
{
    return 1;
}

int MandelbrotSet::get_min_y() const
{
    return -1;
}

int MandelbrotSet::get_max_y() const
{
    return 1;
}


uint8_t MandelbrotSet::compute_at_point(const Complex<double>& c, uint8_t depth) const
{
    // Escape time unoptimized algorithm

    Complex<double> z;
    uint8_t iterations = 0;

    while (iterations <= depth && this->is_in_bounds(z)) {
        z = z.square() + c;
        iterations++;
    }

    return iterations;
}

bool MandelbrotSet::is_in_bounds(const Complex<double>& c) const
{
    // Point is in bounds if it lies in the circle of radius 2
    return (c.get_x() * c.get_x() + c.get_y() * c.get_y()) <= (2 * 2);

    // Assumes plane is rectangular ???
    // return (c.get_x() <= this->get_max_x() && c.get_x() >= this->get_min_x()
    //     && c.get_y() <= this->get_max_y() && c.get_y() >= this->get_min_y());
}

