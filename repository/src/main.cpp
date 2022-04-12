#include <SFML/Graphics.hpp>
#include <cstdio>
#include <string>
#include "SFML/System/Time.hpp"
#include "utils.h"
#include "Checkpoint.h"
using namespace std;

#define DELAY 0.0166666
#define W_WIDTH 16000
#define W_HEIGHT 9000


int main()
{
    sf::View view(sf::FloatRect(0, 0, W_WIDTH, W_HEIGHT));
    sf::RenderWindow window(sf::VideoMode(W_WIDTH, W_HEIGHT), "Premiere fenetre");
    window.setView(view);

    sf::Texture background_texture;
    if( !background_texture.loadFromFile("../repository/Images/background.png"))return 1;
    sf::Sprite background;
    background.setTexture(background_texture);


        scaleToMinSize(background, W_WIDTH,W_HEIGHT);


    sf::Texture BSGCylon_texture;
    if( !BSGCylon_texture.loadFromFile("../repository/Images/BSGCylon.png")) return 1;
    sf::Sprite BSGCylon;
    BSGCylon.setTexture(BSGCylon_texture);


        setOriginToCenter(BSGCylon);
        scaleToMaxSize(BSGCylon,800,800);
        BSGCylon.setPosition(8000,4500);


    sf::Texture BSGViper_texture;
    if( !BSGViper_texture.loadFromFile("../repository/Images/BSGViper.png")) return 1;
    sf::Sprite BSGViper;
    BSGViper.setTexture(BSGViper_texture);


        setOriginToCenter(BSGViper);
        scaleToMaxSize(BSGViper, 800,800);
        BSGViper.setPosition(12000,4500);


    sf::Texture checkeredFlag_texture;
    if( !checkeredFlag_texture.loadFromFile("../repository/Images/checkeredFlag.png")) return 1;
    sf::Sprite checkeredFlag;
    checkeredFlag.setTexture(checkeredFlag_texture);


        setOriginToCenter(checkeredFlag);
        scaleToMaxSize(checkeredFlag, 800,800);
        checkeredFlag.setPosition(1000,1000);


    sf::Texture NMSFighterG_texture;
    if( !NMSFighterG_texture.loadFromFile("../repository/Images/NMSFighterG.png"))return 1;
    sf::Sprite NMSFighterG;
    NMSFighterG.setTexture(NMSFighterG_texture);

    sf::Texture NMSFighterY_texture;
    if( !NMSFighterY_texture.loadFromFile("../repository/Images/NMSFighterY.png"))return 1;
    sf::Sprite NMSFighterY;
    NMSFighterY.setTexture(NMSFighterY_texture);

    sf::Texture SWAnakinsPod_texture;
    if( !SWAnakinsPod_texture.loadFromFile("../repository/Images/SWAnakinsPod.png"))return 1;
    sf::Sprite SWAnakinsPod;
    SWAnakinsPod.setTexture(SWAnakinsPod_texture);


        setOriginToCenter(SWAnakinsPod);
        scaleToMaxSize(SWAnakinsPod, 800, 800);
        SWAnakinsPod.setPosition(8000,2000);


    sf::Texture SWMilleniumFalcon_texture;
    if( !SWMilleniumFalcon_texture.loadFromFile("../repository/Images/SWMilleniumFalcon.png"))return 1;
    sf::Sprite SWMilleniumFalcon;
    SWMilleniumFalcon.setTexture(SWMilleniumFalcon_texture);


        setOriginToCenter(SWMilleniumFalcon);
        scaleToMaxSize(SWMilleniumFalcon, 800, 800);
        SWMilleniumFalcon.setPosition(4000,4500);

    
    sf::Text fpsDisplay;
    sf::Font font;

    font.loadFromFile("../repository/fonts/arial.ttf");

    fpsDisplay.setFillColor(sf::Color::Green);
    fpsDisplay.setCharacterSize(250);
    fpsDisplay.setFont(font);
    fpsDisplay.setPosition(5, 5);


    sf::Clock clock;
    float currentTime = clock.restart().asSeconds();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        BSGCylon.move(4,3);

        while ((currentTime=clock.getElapsedTime().asSeconds())<=DELAY){
            continue;
        }

        float framerate = 1/currentTime;

        currentTime = clock.restart().asSeconds();

        string str = to_string(framerate);
        fpsDisplay.setString(str);

        window.clear();
        
        window.draw(background);
        window.draw(BSGCylon);
        window.draw(BSGViper);
        window.draw(SWAnakinsPod);
        window.draw(SWMilleniumFalcon);
        window.draw(checkeredFlag);
        window.draw(fpsDisplay);


        window.display();
    }


    return 0;
}