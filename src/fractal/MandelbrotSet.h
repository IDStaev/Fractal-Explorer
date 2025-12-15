#pragma once
#include "IFractal.h"

class MandelbrotSet : public IFractal {
public:
    int get_min_x() const override;
    int get_max_x() const override;
    int get_min_y() const override;
    int get_max_y() const override;

    uint8_t compute_at_point(const Complex<double>& c, uint8_t depth) const override;

private:
    bool is_in_bounds(const Complex<double>& c) const;
};