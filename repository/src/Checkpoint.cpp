#include "Checkpoint.h"
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/RenderStates.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "utils.h"

Checkpoint::Checkpoint(int x, int y, int id) : X_(x), Y_(y), id_(id) {};

void Checkpoint::draw()
{
    sf::CircleShape circle(600); 
    setOriginToCenter(circle);
    circle.setFillColor(sf::Color(0,0,0,63));
    circle.setOutlineColor(sf::Color(0,0,0));
    circle.setOutlineThickness(-50);
    circle.setPosition(X_,Y_);
    
}