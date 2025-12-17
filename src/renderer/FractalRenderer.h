#pragma once
#include "IFractalRenderer.h"
#include "../color/IColorStrategy.h"

class FractalRenderer : public IFractalRenderer {
public:
    FractalRenderer(std::unique_ptr<IFractal> fractal, std::unique_ptr<IBufferedImage> image,
        std::unique_ptr<IColorStrategy> color_strategy, size_t depth = 13);

    // Let callers observe while retaining ownership
    const IFractal* get_fractal() const override;
    const IBufferedImage* get_image() const override;
    void render() override;

private:
    std::unique_ptr<const IColorStrategy> color_strategy;
    std::unique_ptr<const IFractal> fractal;
    std::unique_ptr<IBufferedImage> image;
    size_t depth;
};
