#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cmath>
#include "game.h"
#include <vector>
#include <string>
#include "checkpoint.h"

int main()
{

    srand(time(0));
    
    sf::ContextSettings settings;
    settings.antialiasingLevel = 32;

    sf::RenderWindow window(sf::VideoMode(1600, 900), "SFML works!", sf::Style::Default, settings);
    window.setView(sf::View(sf::Rect(0.f,0.f,16000.f,9000.f)));

  

    CheckPoint checkpoint(sf::Vector2f(1000, 1000), 1);
    FinalCheckPoint finalcheckpoint(sf::Vector2f(10000, 1000));

    std::vector<sf::Vector2f> checkpointsPositions;
    checkpointsPositions.insert(checkpointsPositions.begin(), sf::Vector2f(1000, 1000));
    checkpointsPositions.insert(checkpointsPositions.begin(), sf::Vector2f(10000, 1000));
    Game g;





    while (window.isOpen())
    {   

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        
        window.clear();
        // window.draw(background);
        // window.draw(checkpoint);
        // window.draw(finalcheckpoint);
        window.draw(g);
        window.display();
    }

    return 0;
}