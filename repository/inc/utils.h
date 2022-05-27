#ifndef INC_UTILS_H
#define INC_UTILS_H

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

void setOriginToCenter(sf::Sprite &object);
void setOriginToCenter(sf::Shape &object);

void scaleToMinSize(sf::Sprite &sp, double size_x, double size_y);
void scaleToMaxSize(sf::Sprite &sp, double size_x, double size_y);
void scaleByRadius(sf::Sprite &sp, int radius);

void setTextCenterPosition(sf::Text &txt, sf::Vector2f center);

double norm(sf::Vector2f v);

double calculateAngle(sf::Vector2f pointA, sf::Vector2f pointB);
double legalAngle(double angle, double pod_angle);

#endif