#pragma once 


#include <SFML/Graphics.hpp>


#include "ParticleSystem.h"



class ParticleWindow {
public:
    ParticleWindow() 
        : window(sf::VideoMode({1920, 1080}), "Tilemap") 
    {
        
    }

    void run() {
        window.setFramerateLimit(144);
        // create the particle system
        ParticleSystem particles(1000);

        // create a clock to track the elapsed time
        sf::Clock clock;

       

        while (window.isOpen())
        {
            while (const std::optional event = window.pollEvent())
            {
                if (event->is<sf::Event::Closed>())
                {
                    window.close();
                }
            }

            // make the particle system emitter follow the mouse
            sf::Vector2i mouse = sf::Mouse::getPosition(window);
            particles.setEmitter(window.mapPixelToCoords(mouse));

            // update it
            sf::Time elapsed = clock.restart();
            particles.update(elapsed);

            // draw it
            window.clear();
            window.draw(particles);
            window.display();
            
        }
    }

private:
    sf::RenderWindow window;
};