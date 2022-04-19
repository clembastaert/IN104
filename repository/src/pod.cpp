#include "pod.h"
#include "game.h"
#include <SFML/System/Vector2.hpp>

Decision::Decision(sf::Vector2f target, float power) 
{
    //TODO
};

Pod::Pod(sf::Vector2f pos, float angle, sf::Vector2f vel) 
{
    //TODO
};

Decision Pod::getDecision(Game gameSnapshot) const
{
    //TO CHANGE
    return Decision({8000, 4500}, 100);
};