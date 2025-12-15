#pragma once
#include "../fractal/IFractal.h"
#include "IRenderer.h"

class IFractalRenderer : public IRenderer {
public:
    // Should not be able to reset/move, reassign
    virtual const IFractal* get_fractal() const = 0;
};