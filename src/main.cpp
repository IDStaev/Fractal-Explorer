#include <iostream>
#include <SFML/Graphics.hpp>
#include "renderer/FractalRenderer.h"
#include "fractal/MandelbrotSet.h"
#include "buffer/BufferedImage.h"
#include "color/BWColorStrategy.h"
#include "color/GrayscaleColorStrategy.h"
#include "color/RainbowColorStrategy.h"

// TODO: Isolate Presentation/SFML logic
// TODO: Command line args for image size, depth, fractal type, output file
// TODO: Zooming and panning functionality
// TODO: Window size independence

int main() {
    int depth = 20;

    auto fr = std::make_unique<FractalRenderer>(
        std::make_unique<MandelbrotSet>(),
        std::make_unique<BufferedImage>(800, 600),
        //std::make_unique<BWColorStrategy>(),
        std::make_unique<RainbowColorStrategy>(),
        depth
    );

    std::cout << "Rendering..." << std::endl;
    fr->render();
    std::cout << "Render complete" << std::endl;

    const IBufferedImage* image = fr->get_image();
    unsigned width = image->get_width();
    unsigned height = image->get_height();
    std::cout << "Image size: " << width << "x" << height << std::endl;

    const uint8_t* buffer = image->get_buffer();

    // Find min and max values
    uint8_t minVal = 255, maxVal = 0;
    for (size_t i = 0; i < width * height; ++i) {
        if (buffer[i] < minVal) minVal = buffer[i];
        if (buffer[i] > maxVal) maxVal = buffer[i];
    }
    std::cout << "Min value: " << (int)minVal << ", Max value: " << (int)maxVal << std::endl;




    sf::Texture texture(sf::Vector2u(width, height));
    texture.update(buffer);
    sf::Sprite sprite(texture);

    auto window = sf::RenderWindow(sf::VideoMode({ width, height }), "FractalStudio");
    window.setFramerateLimit(144);
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