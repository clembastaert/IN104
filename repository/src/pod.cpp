#include "pod.h"
#include "game.h"
#include <SFML/System/Vector2.hpp>

Decision::Decision(sf::Vector2f target, float power) 
{
    target_=target;
    power_ = power;

};

Pod::Pod(sf::Vector2f pos, float angle, sf::Vector2f vel) 
{
    angle_=angle;
    pos_=pos;
    vel_=vel;
    
};

Decision Pod::getDecision(Game gameSnapshot) const
{
    //TO CHANGE
    return Decision({8000, 4500}, 100);
};