#include "game.h"
#include "checkpoint.h"
#include "utils.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <iostream>

Game::Game(std::vector<sf::Vector2f> checkpointsPositions) : finalCP_(checkpointsPositions[0])
{
    // TODO
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

    for (const auto &podSprite : podsSprites_)
    {
        target.draw(podSprite, states);
    }
}