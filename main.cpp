#include "Renderer.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <time.h>
#define WINDOW_WIDTH 250
#define WINDOW_HEIGHT 250


int main()
{

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML Ray Tracing (CPU)");
    sf::Texture image;
    image.create(WINDOW_WIDTH, WINDOW_HEIGHT);
    sf::Sprite frame(image);
    sf::Uint8* frameBuffer = new sf::Uint8[WINDOW_WIDTH * WINDOW_HEIGHT * 4];
    int start = clock();
    initRenderer(WINDOW_WIDTH, WINDOW_HEIGHT);
    window.setSize(sf::Vector2u(4 * WINDOW_WIDTH, 4 * WINDOW_HEIGHT));
    while (window.isOpen())
    {
        window.clear();

        int time = clock() - start;


        renderFrame(frameBuffer, (float)time);


        //std::cout << clock() - time << "\n";

        image.update(frameBuffer);
        frame.setTexture(image);
        window.draw(frame);


        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                releaseRenderer();
                delete[] frameBuffer;
                window.close();
            }
        }
        window.display();
    }



	return 0;
}