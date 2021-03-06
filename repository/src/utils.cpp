#include "utils.h"
#include <cmath>

// Sets the origin of any Sprite to its center
void setOriginToCenter(sf::Sprite &object)
{
    auto rect = object.getGlobalBounds();
    object.setOrigin(rect.width/2., rect.height/2.);
}

// Sets the origin of any object from base class Shape to its center
void setOriginToCenter(sf::Shape &object)
{
    auto rect = object.getGlobalBounds();
    object.setOrigin(rect.width/2., rect.height/2.);
}

void scaleToMinSize(sf::Sprite &sp, double size_x, double size_y)
{
    double scalingFactor = std::max(size_x/sp.getTextureRect().width, size_y/sp.getTextureRect().height);
    sp.scale(scalingFactor, scalingFactor);
}

void scaleToMaxSize(sf::Sprite &sp, double size_x, double size_y)
{
    double scalingFactor = std::min(size_x/sp.getTextureRect().width, size_y/sp.getTextureRect().height);
    sp.scale(scalingFactor, scalingFactor);
}

void scaleByRadius(sf::Sprite &sp, int radius)
{
    double scalingFactor = 2*radius/std::sqrt(sp.getTextureRect().width*sp.getTextureRect().width + sp.getTextureRect().height*sp.getTextureRect().height);
    sp.scale(scalingFactor, scalingFactor);
}

void setTextCenterPosition(sf::Text &txt, sf::Vector2f center)
{
    sf::Vector2f offset;
    offset.x = txt.getPosition().x - txt.getGlobalBounds().left - txt.getGlobalBounds().width/2.;
    offset.y = txt.getPosition().y - txt.getGlobalBounds().top - txt.getGlobalBounds().height/2.;

    txt.setPosition(center + offset);
}

// returns the euclidian norm of a vector
double norm(sf::Vector2f v){

    return std::sqrt(v.x*v.x + v.y*v.y);
}

// returns the angle between two vectors
double calculateAngle(sf::Vector2f pointA, sf::Vector2f pointB){

    double length = pointB.x - pointA.x;
    double height = pointA.y - pointB.y;

    double angle;


    if(length >= 0) angle = atan(height/length);
    else angle = M_PI + atan(height/length);

    return 2*M_PI - angle;
}

// returns the new angle of the pod after taking into accounts the game rules
// (no change of more than pi/10 per physics update)
double legalAngle(double angle, double pod_angle){

        double diff;

        diff = angle - pod_angle;

        if(diff > M_PI) diff = diff - 2*M_PI;
        else if(diff < -M_PI)  diff = diff + 2*M_PI;

        if(fabs(diff) > M_PI/10){
            if(diff >= 0) angle = pod_angle + (M_PI/10);
            else angle = pod_angle - (M_PI/10);

        }

        return angle;
}
