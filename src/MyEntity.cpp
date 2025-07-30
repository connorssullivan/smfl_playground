#include "MyEntity.h"


MyEntity::MyEntity()
{
    // 
    m_vertices.setPrimitiveType(sf::PrimitiveType::Triangles);
    m_vertices.resize(6);


    /// Triangle 1
    m_vertices[0].position = {0.f, 0.f};
    m_vertices[1].position = {100.f, 0.f};
    m_vertices[2].position = {100.f, 100.f};

    // Triangle 2
    m_vertices[3].position = {0.f, 0.f};
    m_vertices[4].position = {100.f, 100.f};
    m_vertices[5].position = {0.f, 100.f};

    // Color it for visibility
    m_vertices[0].color = sf::Color::Red;
    m_vertices[1].color = sf::Color::Green;
    m_vertices[2].color = sf::Color::Blue;
    m_vertices[3].color = sf::Color::Red;
    m_vertices[4].color = sf::Color::Blue;
    m_vertices[5].color = sf::Color::Yellow;
}


MyEntity::~MyEntity()
{

}

void MyEntity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // apply the entity's transform -- combine it with the one that was passed by the caller
    states.transform *= getTransform(); // getTransform() is defined by sf::Transformable

    // apply the texture
    states.texture = &m_texture;

    // you may also override states.shader or states.blendMode if you want

    // draw the vertex array
    target.draw(m_vertices, states);
}

