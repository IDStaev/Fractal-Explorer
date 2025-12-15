#include <iostream>
#include <SFML/Graphics.hpp>
#include "renderer/FractalRenderer.h"
#include "fractal/MandelbrotSet.h"
#include "buffer/BufferedImage.h"

#include <vector>

int main() {
    auto fr = std::make_unique<FractalRenderer>(
        std::make_unique<MandelbrotSet>(),
        std::make_unique<BufferedImage>(800, 600)
    );
    std::cout << "Rendering..." << std::endl;
    fr->render();
    std::cout << "Render complete" << std::endl;
    const IBufferedImage* image = fr->get_image();
    unsigned width = image->get_width();
    unsigned height = image->get_height();
    std::cout << "Image size: " << width << "x" << height << std::endl;

    const uint8_t* buffer = image->get_buffer();

    // Print first 100 pixel values
    std::cout << "First 100 pixel values: ";
    for (int i = 0; i < 100; i++) {
        std::cout << (int)buffer[i] << " ";
    }
    std::cout << std::endl;

    // Find min and max values
    uint8_t minVal = 255, maxVal = 0;
    for (size_t i = 0; i < width * height; ++i) {
        if (buffer[i] < minVal) minVal = buffer[i];
        if (buffer[i] > maxVal) maxVal = buffer[i];
    }
    std::cout << "Min value: " << (int)minVal << ", Max value: " << (int)maxVal << std::endl;

    // Convert grayscale to RGBA - use WHITE for any non-255 value
    long long nonZeroCount = 0;
    std::vector<uint8_t> pixels(width * height * 4);
    for (size_t i = 0; i < width * height; ++i) {
        uint8_t gray = buffer[i];
        if (gray > nonZeroCount) nonZeroCount++;
        uint8_t color = (gray == 21) ? 0 : 255;  // WHITE if not in set, BLACK if in set
        pixels[i * 4 + 0] = color;  // R
        pixels[i * 4 + 1] = color;  // G
        pixels[i * 4 + 2] = color;  // B
        pixels[i * 4 + 3] = 255;    // A
    }

    std::cout << "Non-zero pixels: " << nonZeroCount << " / " << (width * height) << std::endl;

    sf::Texture texture(sf::Vector2u(width, height));
    texture.update(pixels.data());
    sf::Sprite sprite(texture);

    auto window = sf::RenderWindow(sf::VideoMode({ width, height }), "FractalStudio");
    window.setFramerateLimit(144);
    window.clear();
    window.draw(sprite);
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }
        window.clear();
        window.draw(sprite);
        window.display();
    }
}