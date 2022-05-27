#include "menu.h"
#include "utils.h"
#include <string.h>


Menu::Menu(float width, float height, int cat)
{
	if (!font.loadFromFile("../repository/fonts/arial.ttf"))
	{
		// handle error
	}

    width_ = width;
    height_ = height;

    cat_ = cat;

    backgroundTexture_.loadFromFile("../repository/Images/background.png");
    backgroundSprite_.setTexture(backgroundTexture_);
    scaleToMinSize(backgroundSprite_, width, height);

    if(cat_ == 1){
        strcpy(option1, "Play");
        strcpy(option2, "Options");
        strcpy(option3, "Exit");
    }

    if(cat_ == 2){
        strcpy(option1, "Decision making");
        strcpy(option2, "");
        strcpy(option3, "Exit");
    }

    if(cat_ == 3){
        strcpy(option1, "Manual");
        strcpy(option2, "Next CP AI");
        strcpy(option3, "");
    }

	menu[0].setFont(font);
    menu[0].setCharacterSize(1000);
	menu[0].setFillColor(sf::Color::White);
	menu[0].setString(option1);
	menu[0].setPosition(sf::Vector2f(width_ / 2, height_ / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[1].setFont(font);
    menu[1].setCharacterSize(1000);
	menu[1].setFillColor(sf::Color{170,170,170,128});
	menu[1].setString(option2);
	menu[1].setPosition(sf::Vector2f(width_ / 2, height_ / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[2].setFont(font);
    menu[2].setCharacterSize(1000);
	menu[2].setFillColor(sf::Color{170,170,170,128});
	menu[2].setString(option3);
	menu[2].setPosition(sf::Vector2f(width_ / 2, height_ / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	selectedItemIndex = 0;
}


void Menu::update()
{
    if(cat_ == 1){
        strcpy(option1, "Play");
        strcpy(option2, "Options");
        strcpy(option3, "Back");
    }

    if(cat_ == 2){
        strcpy(option1, "Decision making");
        strcpy(option2, "");
        strcpy(option3, "Back");
    }

    if(cat_ == 3){
        strcpy(option1, "Manual");
        strcpy(option2, "Next CP AI");
        strcpy(option3, "");
    }

	menu[0].setFont(font);
    menu[0].setCharacterSize(1000);
	menu[0].setFillColor(sf::Color::White);
	menu[0].setString(option1);
	menu[0].setPosition(sf::Vector2f(width_ / 2, height_ / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[1].setFont(font);
    menu[1].setCharacterSize(1000);
	menu[1].setFillColor(sf::Color{170,170,170,128});
	menu[1].setString(option2);
	menu[1].setPosition(sf::Vector2f(width_ / 2, height_ / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[2].setFont(font);
    menu[2].setCharacterSize(1000);
	menu[2].setFillColor(sf::Color{170,170,170,128});
	menu[2].setString(option3);
	menu[2].setPosition(sf::Vector2f(width_ / 2, height_ / (MAX_NUMBER_OF_ITEMS + 1) * 3));

    selectedItemIndex = 0;
}


Menu::~Menu()
{
}

// void Menu::draw(sf::RenderWindow &window)
// {
// 	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
// 	{
// 		window.draw(menu[i]);
// 	}
// }

void Menu::draw(sf::RenderTarget &target, sf::RenderStates states) const
{

    target.draw(backgroundSprite_, states);

	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		target.draw(menu[i], states);
	}
}



void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color{170,170,170,128});
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::White);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color{170,170,170,128});
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::White);
	}
}