#pragma once
#include "../util/Complex.hpp"
#include <cstdint>

class IFractal {
public:
    virtual ~IFractal() = default;

    virtual int get_min_x() const = 0;
    virtual int get_max_x() const = 0;
    virtual int get_min_y() const = 0;
    virtual int get_max_y() const = 0;
    virtual uint8_t compute_at_point(const Complex<double>& c, uint8_t depth) const = 0;
};