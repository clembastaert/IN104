#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cmath>
#include "game.h"
#include <vector>
#include <cstring>
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


    Game g;


    char textures[6][43];
    strcpy(textures[0], "../repository/Images/SWMilleniumFalcon.png");
    strcpy(textures[1], "../repository/Images/BSGCylon.png");
    strcpy(textures[2], "../repository/Images/BSGViper.png");
    strcpy(textures[3], "../repository/Images/SWAnakinsPod.png");
    strcpy(textures[4], "../repository/Images/NMSFighterY.png");
    strcpy(textures[5], "../repository/Images/NMSFighterG.png");

    g.addPod(textures[0], 0);


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
    int end = 0;
    int pods_number = 1;

    while (window.isOpen())
    {   

        // if gameOn == 0, the game has not started yet so we want to display the menu
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
                        case sf::Keyboard::Up:  //using arrows to browse menu
                            menu.MoveUp();
                            break;

                        case sf::Keyboard::Down:
                            menu.MoveDown();
                            break;

                        case sf::Keyboard::Return:  //selecting an entry with Return
                            switch (menu.cat_)      //result depends on current sub-menu ...
                            {
                                case 1:
                                switch (menu.GetPressedItem())  // ... and of course selected entry
                                {
                                    case 0:         // Play button
                                        gameOn = 1; // setting gameOn = 1 to enter game loop
                                        for(int i=1; i<pods_number; i++){
                                            g.addPod(textures[i], (i%2) + 1);
                                        }
                                        break;
                                    case 1:         // Options button
                                        menu.cat_ = 2;
                                        menu.update();
                                        break;
                                    case 2:         // Exit button
                                        window.close();
                                        return 0;
                                }
                                break;

                                case 2:
                                switch (menu.GetPressedItem())  // another sub-menu : Options
                                {
                                    case 0:         // Decision making button    
                                        menu.cat_ = 3;
                                        menu.update();
                                        break;
                                    case 1:         // Number of pods button
                                        menu.cat_ = 4;
                                        menu.update();
                                        break;
                                    case 2:         // Go back button
                                        menu.cat_ = 1;
                                        menu.update();
                                        break;
                                }
                                break;

                                case 3:
                                switch (menu.GetPressedItem())  // another sub-menu : Decision making
                                {
                                    case 0:         // Manual mode
                                        g.pods_[0].decision_making_ = 0;
                                        menu.cat_ = 2;
                                        menu.update();
                                        break;;
                                    case 1:         // AI V1
                                        g.pods_[0].decision_making_ = 1;
                                        menu.cat_ = 2;
                                        menu.update();
                                        break;
                                    case 2:         // AI V2
                                        g.pods_[0].decision_making_ = 2;
                                        menu.cat_ = 2;
                                        menu.update();
                                        break;
                                }
                                break;

                                case 4:
                                switch (menu.GetPressedItem())  // another sub-menu : Number of Pods
                                {
                                    case 0:
                                        pods_number = 1;
                                        menu.cat_ = 2;
                                        menu.update();
                                        break;;
                                    case 1:
                                        pods_number = 2;
                                        menu.cat_ = 2;
                                        menu.update();
                                        break;
                                    case 2:
                                        pods_number = 3;
                                        menu.cat_ = 2;
                                        menu.update();
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


        else{   // Entering game loop

            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                    return 0;
                }
            }

            // Starting game clock
            elapsed = clock.getElapsedTime();

            if(elapsed.asMilliseconds() - g.physicsTime.asMilliseconds() > PHYSICS_TIME_STEP.asMilliseconds()){
                // Updating physics every PHYSICS_TIME_STEP
                if(end){        //updatePhysics returns the id of the winning pod when the race is over
                    break;      //so we want to break out of loop when end != 0
                }
                end = g.updatePhysics(); 
            }

            if(elapsed.asMilliseconds() - lastTime > 1000){ //calculating frames per second
                lastTime = elapsed.asMilliseconds();
                fps = std::to_string(cpt);
                cpt = 0;
                text.setString(fps);
            }

            cpt++;
            
            g.updateGraphics(elapsed);  //updating graphics at every frame
            
            window.clear();
            window.draw(g);
            window.draw(text);
        }


        window.display();
    }

    // Everything that follows is to display a simple text indicating which pod
    // won the race at the end of the game
    sf::Event event;
    char str[13] = "Pod x wins !";
    str[4] = end + '0';
    text.setFillColor(sf::Color::White);
    text.setString(str);
    setTextCenterPosition(text, {8000.f, 4500.f});

    while (1)
    {
        
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                return 0;
            }
        }

        window.clear();
        window.draw(g);
        window.draw(text);
        window.display();
    }
    
    return 0;
}