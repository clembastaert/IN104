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
#include "menu.h"


int main()
{

    srand(time(0));
    
    sf::ContextSettings settings;
    settings.antialiasingLevel = 32;

    sf::RenderWindow window(sf::VideoMode(1600, 900), "SFML works!", sf::Style::Default, settings);
    window.setView(sf::View(sf::Rect(0.f,0.f,16000.f,9000.f)));

  


    std::vector<sf::Vector2f> checkpointsPositions;
    checkpointsPositions.insert(checkpointsPositions.begin(), sf::Vector2f(7000, 8000));
    checkpointsPositions.insert(checkpointsPositions.begin(), sf::Vector2f(8000, 5000));
    checkpointsPositions.insert(checkpointsPositions.begin(), sf::Vector2f(2500, 1200));
    checkpointsPositions.insert(checkpointsPositions.begin(), sf::Vector2f(10000, 2500));
    Game g(checkpointsPositions);

    //Game g;

    g.addPod("../repository/Images/BSGCylon.png");
    //g.addPod("../repository/Images/BSGViper.png", 1);


    sf::Clock clock;
    sf::Time elapsed;
    int lastTime = 0;
    int cpt = 0;
    std::string fps;

    sf::Text text;
    sf::Font font;
    font.loadFromFile("../repository/fonts/arial.ttf");
    text.setFont(font);
    text.setCharacterSize(800);
    text.setFillColor(sf::Color::Green);

    Menu menu(16000.f, 9000.f, 1);
    int gameOn = 0;
    int decision_making;
    int end = 0;

    while (window.isOpen())
    {   

        if(!gameOn)
        {
            sf::Event event;
            while (window.pollEvent(event))
            {


                switch(event.type)
                {

                case sf::Event::KeyReleased:
                    switch (event.key.code)
                    {
                        case sf::Keyboard::Up:
                            menu.MoveUp();
                            break;

                        case sf::Keyboard::Down:
                            menu.MoveDown();
                            break;

                        case sf::Keyboard::Return:
                            switch (menu.cat_)
                            {
                                case 1:
                                switch (menu.GetPressedItem())
                                {
                                    case 0:
                                        gameOn = 1;
                                        break;
                                    case 1:
                                        menu.cat_ = 2;
                                        menu.update();
                                        break;
                                    case 2:
                                        window.close();
                                        break;
                                }
                                break;

                                case 2:
                                switch (menu.GetPressedItem())
                                {
                                    case 0:
                                        menu.cat_ = 3;
                                        menu.update();
                                        break;
                                    case 1:
                                        break;
                                    case 2:
                                        menu.cat_ = 1;
                                        menu.update();
                                        break;
                                }
                                break;

                                case 3:
                                switch (menu.GetPressedItem())
                                {
                                    case 0:
                                        g.pods_[0].decision_making_ = 0;
                                        menu.cat_ = 2;
                                        menu.update();
                                        break;;
                                    case 1:
                                        g.pods_[0].decision_making_ = 1;
                                        menu.cat_ = 2;
                                        menu.update();
                                        break;
                                    case 2:
                                        break;
                                }
                                break;
                            }
                            break;

                        default :
                            continue;
                    }
                    break;

                case sf::Event::Closed:
                    window.close();
                    break;

                default : continue;

                }
            }

            
            window.clear();
            window.draw(menu);
        }   

        else{

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
                if(end){
                    printf("%f\n", elapsed.asSeconds());
                    return 0;
                }
                end = g.updatePhysics();
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
            window.draw(g);
            window.draw(text);
        }


        window.display();
    }

    return 0;
}