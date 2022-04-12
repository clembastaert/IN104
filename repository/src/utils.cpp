
#include "utils.h"
#include <cmath>

void scaleToMinSize(sf::Sprite &sprite, int maxWidth, int maxHeight)
{
    auto rect = sprite.getGlobalBounds();
    float rapportHeight = (float)maxHeight/(float)rect.height;
    float rapportWidth = (float)maxWidth/(float)rect.width;
    if (rapportHeight>rapportWidth){
        sprite.scale(rapportHeight,rapportHeight);
    }
    else {
        sprite.scale(rapportWidth,rapportWidth);
    }
}

void scaleToMaxSize(sf::Sprite &sprite, int maxWidth, int maxHeight)
{
    auto rect = sprite.getGlobalBounds();
    float rapportHeight = (float)maxHeight/(float)rect.height;
    float rapportWidth = (float)maxWidth/(float)rect.width;
    if (rapportHeight<rapportWidth){
        sprite.scale(rapportHeight,rapportHeight);
    }
    else sprite.scale(rapportWidth,rapportWidth);
}

void scalebyRadius(sf::Sprite &sprite, int radius)
{
    auto rect = sprite.getGlobalBounds();
    float demidiagonalecarre = 0.25*(rect.height*rect.height + rect.width*rect.width);
    float demidiagonale = sqrt(demidiagonalecarre);
    float rapport = (float)radius/demidiagonale;
    sprite.scale(rapport,rapport);
}
