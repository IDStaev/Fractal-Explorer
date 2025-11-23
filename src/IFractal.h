#pragma once

class IFractal {
public:
    virtual ~IFractal() = default;
    virtual int get_min_x() const = 0;
    virtual int get_max_x() const = 0;
    virtual int get_min_y() const = 0;
    virtual int get_max_x() const = 0;
    virtual int compute_point() const = 0;
};