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
    
    sf::ContextSettings settings;
    settings.antialiasingLevel = 32;

    sf::RenderWindow window(sf::VideoMode(1600, 900), "SFML works!", sf::Style::Default, settings);
    window.setView(sf::View(sf::Rect(0.f,0.f,16000.f,9000.f)));

    sf::Texture background_texture;
    if( !background_texture.loadFromFile("../repository/Images/background.png"))return 1;
    sf::Sprite background;
    background.setTexture(background_texture);


        scaleToMinSize(background, 16000,9000);


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
        window.draw(background);
        window.display();
    }

    return 0;
}