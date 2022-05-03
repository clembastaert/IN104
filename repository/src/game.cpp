#include "game.h"
#include "checkpoint.h"
#include "utils.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/System/Time.hpp>
#include <iostream>

Game::Game() : finalCP_(sf::Vector2f((rand() % 14800) + 600.f, (rand() % 7800) + 600.f))
{
    int random = (rand() % 6) + 2;

    sf::Vector2f temp;
    std::vector<sf::Vector2f> checkpointsPositions;

    for(int i=1; i<random; i++){
        temp.x = rand() % 14800 + 600.f;
        temp.y = rand() % 7800 + 600.f;
        checkpointsPositions.insert(checkpointsPositions.begin(), temp);
    }

    int size = checkpointsPositions.size();


    for(int i=1; i<size; i++){
        otherCPs_.emplace_back(checkpointsPositions[i], i);
    }

    backgroundTexture_.loadFromFile("../repository/Images/background.png");
    backgroundSprite_.setTexture(backgroundTexture_);
    scaleToMinSize(backgroundSprite_, 16000,9000);

    lastFrameTime = sf::milliseconds(0);
    physicsTime = sf::milliseconds(0);
}

Game::Game(std::vector<sf::Vector2f> checkpointsPositions) : finalCP_(checkpointsPositions[0])
{
    int size = checkpointsPositions.size();


    for(int i=1; i<size; i++){
        otherCPs_.emplace_back(checkpointsPositions[i], i);
    }

    backgroundTexture_.loadFromFile("../repository/Images/background.png");
    backgroundSprite_.setTexture(backgroundTexture_);
    scaleToMinSize(backgroundSprite_, 16000,9000);


    lastFrameTime = sf::milliseconds(0);
    physicsTime = sf::milliseconds(0);
}

void Game::addPod()
{
    //TODO
}

void Game::updatePhysics()
{
    //TODO
}

void Game::updateGraphics(sf::Time frameTime)
{
    //TODO
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(backgroundSprite_, states);
    target.draw(finalCP_, states);
    for (const auto &cp : otherCPs_)
    {
        target.draw(cp, states);
    }

    // for (const auto &podSprite : podsSprites_)
    // {
    //     target.draw(podSprite, states);
    // }
}