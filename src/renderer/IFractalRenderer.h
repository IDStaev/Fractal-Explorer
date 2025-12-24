#pragma once
#include "../fractal/IFractal.h"
#include "IRenderer.h"
#include "../view/FractalView.h"

class IFractalRenderer : public IRenderer {
public:
    // Should not be able to reset/move, reassign
    virtual const FractalView* get_fractal_view() const = 0;
};
