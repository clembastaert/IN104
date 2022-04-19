#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include "checkpoint.h"
#include "game.h"

CheckPoint::CheckPoint(sf::Vector2f center, unsigned int id)
{
    //TODO
};

void CheckPoint::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(circle_, states);
    target.draw(fillingText_);
};

sf::Vector2f CheckPoint::getPosition()
{
    return circle_.getPosition();
}

FinalCheckPoint::FinalCheckPoint(sf::Vector2f center)
{
    //TODO
};

void FinalCheckPoint::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(circle_, states);
    target.draw(fillingSprite_, states);
};

sf::Vector2f FinalCheckPoint::getPosition()
{
    return circle_.getPosition();
}
