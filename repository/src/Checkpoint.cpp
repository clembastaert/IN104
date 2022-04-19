#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include "checkpoint.h"
#include "game.h"
#include "utils.h"

CheckPoint::CheckPoint(sf::Vector2f center, unsigned int id)
{
    circle_ = sf::CircleShape(600,100);
    setOriginToCenter(circle_);
    circle_.setPosition(center.x,center.y);
    circle_.setFillColor(sf::Color(0, 0, 0, 63));
    circle_.setOutlineThickness(-50);
    circle_.setOutlineColor(sf::Color(0, 0, 0));
    font_.loadFromFile("../repository/fonts/arial.ttf");   
    fillingText_ = sf::Text(std::to_string(id), font_, 500);
    fillingText_.setOutlineThickness(100);
    setTextCenterPosition(fillingText_, center);
};

void CheckPoint::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(circle_,states);
    target.draw(fillingText_, states);
};

sf::Vector2f CheckPoint::getPosition()
{
    return circle_.getPosition();
}

FinalCheckPoint::FinalCheckPoint(sf::Vector2f center)
{
    circle_ = sf::CircleShape (600,100);
    setOriginToCenter(circle_);
    circle_.setPosition(center.x,center.y);
    circle_.setFillColor(sf::Color(255, 255, 255, 63));
    circle_.setOutlineThickness(-50);
    circle_.setOutlineColor(sf::Color(0, 0, 0));
    fillingTexture_.loadFromFile("../repository/Images/checkeredFlag.png");
    fillingSprite_.setTexture(fillingTexture_);
    setOriginToCenter(fillingSprite_);
    scaleByRadius(fillingSprite_, 550);
    fillingSprite_.setPosition(center);
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
