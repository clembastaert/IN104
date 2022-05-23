#include "pod.h"
#include "game.h"
#include <SFML/System/Vector2.hpp>

Decision::Decision(sf::Vector2f target, float power) 
{
    target_=target;
    power_ = power;

};

Pod::Pod(sf::Vector2f pos, float angle, sf::Vector2f vel) 
{
    angle_=angle;
    pos_=pos;
    vel_=vel;
    
    nextCP_ = 1;
    
};

Decision Pod::getDecision(Game gameSnapshot) const
{
    sf::Vector2f pos;

    if(nextCP_ > 0) pos = gameSnapshot.otherCPs_[nextCP_-1].getPosition();

    else pos = gameSnapshot.finalCP_.getPosition();

    return Decision(pos, 100);
};

void Pod::isNextCPCrossed(std::vector<CheckPoint> otherCPs_, FinalCheckPoint finalCP_, sf::Time physicsTime)
{
    sf::Vector2f future_pos(pos_.x + vel_.x * (physicsTime / (physicsTime + PHYSICS_TIME_STEP)), pos_.y + vel_.x * (physicsTime / (physicsTime + PHYSICS_TIME_STEP)));
    sf::Vector2f len((future_pos.x - pos_.x) / 5, (future_pos.y - pos_.y) / 5);
    sf::Vector2f CP_pos;

    if(nextCP_ > 0){
        CP_pos = otherCPs_[nextCP_-1].getPosition();
    }
    else{
        CP_pos = finalCP_.getPosition();
    }

    float norm;

    for(int i=0; i<4; i++){
        norm = std::sqrt((pos_.x + len.x * i - CP_pos.x)*(pos_.x + len.x * i - CP_pos.x)
                     + (pos_.y + len.y * i - CP_pos.y)*(pos_.y + len.y * i - CP_pos.y));
        if(norm < 600){
            nextCP_ = (nextCP_ + 1) % (otherCPs_.size() + 1);
            printf("%d\n", nextCP_);
            break;
        }
    }
}