#ifndef INC_POD_H
#define INC_POD_H

#include <SFML/System.hpp>
#include <cmath>
#include "Checkpoint.h"

class Game;

struct Decision
{
    Decision(sf::Vector2f traj, float power, float angle, float length);

    sf::Vector2f traj_;
    float power_;
    float angle_;
    float length_;
};

class Pod
{
    public :
    Pod(sf::Vector2f pos, float angle, sf::Vector2f vel = {0, 0}, int decision_making = 0);
    Decision getDecision(Game gameSnapshot) const; 
    int isNextCPCrossed(std::vector<CheckPoint> otherCPs_, FinalCheckPoint finalCP_);
    int decision_making_;
    float power_;

    private :
    sf::Vector2f pos_, vel_; //position and velocity vectors
    float angle_; //angle in radians
    int nextCP_, lapCount_;
    
    
    friend class Game; //allows game to modify pod's private attributes
};

#endif