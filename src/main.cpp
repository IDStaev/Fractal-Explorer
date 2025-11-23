#include <iostream>
#include "Complex.hpp"

int main() {
    Complex<int> c1(3, 6);
    Complex<int> c2(1, 1);
    Complex<int> res1 = c1 + c2;
    Complex<int> res2 = c1 - c2;

    std::cout << res1 << " " << res2;
}


// #include <SFML/Graphics.hpp>
// int main()
// {
//     auto window = sf::RenderWindow(sf::VideoMode({ 480u, 480u }), "CMake SFML Project");
//     window.setFramerateLimit(144);
//     while (window.isOpen())
//     {
//         while (const std::optional event = window.pollEvent())
//         {
//             if (event->is<sf::Event::Closed>())
//             {
//                 window.close();
//             }
//         }
//         window.clear();
//         window.display();
//     }
// }