#pragma once
#include <memory>
#include "../buffer/IBufferedImage.h"

class IRenderer {
public:
    virtual ~IRenderer() = default;

    virtual const IBufferedImage* get_image() const = 0;
    virtual void render() = 0;
};