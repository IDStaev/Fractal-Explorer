#pragma once
#include "IColorStrategy.h"

class GrayscaleColorStrategy : public IColorStrategy {
public:
    Pixel get_color(uint8_t iteration, uint8_t max_iteration) const override;
};
