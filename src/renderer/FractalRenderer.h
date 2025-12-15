#pragma once
#include "IFractalRenderer.h"

class FractalRenderer : public IFractalRenderer {
public:
    FractalRenderer(std::unique_ptr<IFractal> fractal, std::unique_ptr<IBufferedImage> image);

    // Let callers observe while retaining ownership
    const IFractal* get_fractal() const override;
    const IBufferedImage* get_image() const override;
    void render() override;

private:
    std::unique_ptr<const IFractal> fractal;
    std::unique_ptr<IBufferedImage> image;
};