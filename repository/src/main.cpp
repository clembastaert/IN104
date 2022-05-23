#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cmath>
#include "game.h"
#include <vector>
#include <string>
#include "checkpoint.h"
#include "utils.h"

int main()
{

    srand(time(0));
    
    sf::ContextSettings settings;
    settings.antialiasingLevel = 32;

    sf::RenderWindow window(sf::VideoMode(1600, 900), "SFML works!", sf::Style::Default, settings);
    window.setView(sf::View(sf::Rect(0.f,0.f,16000.f,9000.f)));

  


    std::vector<sf::Vector2f> checkpointsPositions;
    checkpointsPositions.insert(checkpointsPositions.begin(), sf::Vector2f(3000, 3000));
    checkpointsPositions.insert(checkpointsPositions.begin(), sf::Vector2f(8000, 5000));
    checkpointsPositions.insert(checkpointsPositions.begin(), sf::Vector2f(1000, 1000));
    checkpointsPositions.insert(checkpointsPositions.begin(), sf::Vector2f(10000, 1000));
    Game g(checkpointsPositions);

    //Game g;

    g.addPod("../repository/Images/BSGCylon.png");

    // sf::Texture BSGCylon_texture;
    // BSGCylon_texture.loadFromFile("../repository/Images/BSGCylon.png");

    //sf::Sprite Sprite;
    //Sprite.setTexture(g.podsTextures_[0]);
    //g.podsSprites_.emplace_back(Sprite);

    // scaleToMaxSize(Sprite, 800, 800);
    // setOriginToCenter(Sprite);
    // Sprite.setPosition({2800, 2800});

    sf::Clock clock;
    sf::Time elapsed;
    int lastTime = 0;
    int cpt = 0;
    std::string fps;

    sf::Text text;
    sf::Font font;
    font.loadFromFile("../repository/fonts/arial.ttf");
    text.setFont(font);
    text.setString("Hello world");
    text.setCharacterSize(800);
    text.setFillColor(sf::Color::Green);

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

        elapsed = clock.getElapsedTime();

        if(elapsed.asMilliseconds() - g.physicsTime.asMilliseconds() > PHYSICS_TIME_STEP.asMilliseconds()){
            g.updatePhysics();
        }

        if(elapsed.asMilliseconds() - lastTime > 1000){
            lastTime = elapsed.asMilliseconds();
            fps = std::to_string(cpt);
            cpt = 0;
            text.setString(fps);
        }

        cpt++;
        
        g.updateGraphics(elapsed);
        
        window.clear();
        // window.draw(background);
        // window.draw(checkpoint);
        // window.draw(finalcheckpoint);
        window.draw(g);
        window.draw(text);
        //window.draw(Sprite);
        window.display();
    }

    return 0;
}