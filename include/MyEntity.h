#pragma once

#include <SFML/Graphics.hpp>

class MyEntity : public sf::Drawable, public sf::Transformable
{
public:
    // add functions to play with the entity's geometry / colors / texturing...
    MyEntity();
    ~MyEntity();

private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    sf::VertexArray m_vertices;
    sf::Texture     m_texture;
};