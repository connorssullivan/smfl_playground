#pragma once

#include <SFML/Graphics.hpp>
#include <array>
#include <optional>

#include "TileMap.h"

class TileMapWindow {
public:
    TileMapWindow() 
        : window(sf::VideoMode({512, 256}), "Tilemap") 
    {
        constexpr std::array level = {
            0, 0, 3, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
            1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
            0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
            0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
            0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
            2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
            0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
        };
        
        if (!map.load("assets/tileset.png", {32, 32}, level.data(), 16, 8)) {
            throw std::runtime_error("Failed to load tilemap");
        }
    }

    void run() {
        while (window.isOpen()) {
            while (const std::optional event = window.pollEvent()) {
                if (event->is<sf::Event::Closed>())
                    window.close();
            }

            window.clear();
            window.draw(map);
            window.display();
        }
    }

private:
    sf::RenderWindow window;
    TileMap map; // your TileMap class
};
