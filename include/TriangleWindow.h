#pragma once 


#include <SFML/Graphics.hpp>
#include <array>
#include <optional>

#include "MyEntity.h"



class TriangleWindow {
public:
    TriangleWindow() 
        : window(sf::VideoMode({1920, 1080}), "Tilemap") 
    {
        
    }

    void run() {
        window.setFramerateLimit(144);

        //Create my entity
        MyEntity entity;
        float x_pos {1000.f};
        float y_pos {550.f};
        float deg {0.f};

        entity.setPosition({x_pos, y_pos});
        entity.setRotation(sf::degrees(45));

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
            window.draw(entity);
            window.display();

            x_pos += 1.f;
            entity.setPosition({x_pos, y_pos});
            
        }
    }

private:
    sf::RenderWindow window;
};
