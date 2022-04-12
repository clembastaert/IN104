#ifndef INC_UTILS_H
#define INC_UTILS_H


#include <SFML/Graphics.hpp>

template<class T>
void setOriginToCenter(T &object)
{
    auto rect = object.getGlobalBounds();
    object.setOrigin(rect.width/2,rect.height/2);
}

void scaleToMinSize(sf::Sprite &sprite, int maxWidth, int maxHeight);

void scaleToMaxSize(sf::Sprite &sprite, int maxWidth, int maxHeight);

void scalebyRadius(sf::Sprite &sprite, int radius);

#endif

