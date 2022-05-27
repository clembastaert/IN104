#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS 3

class Menu : public sf::Drawable
{
public:
	Menu(float width, float height, int cat);
	~Menu();

	float width_, height_;
	
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }
	int cat_;

private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
	
	char option1[20];
	char option2[20];
	char option3[20];


	sf::Texture backgroundTexture_;
    sf::Sprite backgroundSprite_;

};