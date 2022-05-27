#include "pod.h"
#include "game.h"
#include "utils.h"
#include <SFML/System/Vector2.hpp>

Decision::Decision(sf::Vector2f traj, float power, float angle, float length) 
{
    traj_ = traj;
    power_ = power;
    angle_ = angle;
    length_ = length;

};

Pod::Pod(sf::Vector2f pos, float angle, sf::Vector2f vel, int decision_making) 
{
    angle_=angle;
    pos_=pos;
    vel_=vel;
    decision_making_=decision_making;
    
    nextCP_ = 1;
    lapCount_ = 0;

};

Decision Pod::getDecision(Game gameSnapshot) const
{
    sf::Vector2f target;
    sf::Vector2f traj;

    float angle, diff, length;
    float power;

    if(decision_making_ == 0){

        int left = 0;
        int right = 0;
        int up = 0;
        int down = 0;

        power = 100;

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) left = 1;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) right = 1;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) up = 1;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) down = 1;

        target.x = pos_.x + (right-left);
        target.y = pos_.y + (down-up);

        traj = target - pos_;
        length = norm(traj);

        if(pos_ != target) angle = calculateAngle(pos_, target);
        else angle = angle_;
    }

    if(decision_making_ == 1){

        if(nextCP_ > 0) target = gameSnapshot.otherCPs_[nextCP_-1].getPosition();

        else target = gameSnapshot.finalCP_.getPosition();

        // Calculating distance between pod and target
        traj = target - pos_;
        length = norm(traj);

        // Calculating difference between current angle and absolute target angle 
        angle = calculateAngle(pos_, target);
        diff = angle - angle_;
        if(diff > M_PI) diff = diff - 2*M_PI;
        else if(diff < -M_PI)  diff = diff + 2*M_PI;

        if(fabs(diff) > M_PI/4){
            power = 15;
        }
        else{
            if(length < 2500){
                power = 5 + 40 * length / 2700 + 55 * (length * length / 7290000);
            } 
            else{
                power = 100;
            }
        }

    }

    angle = legalAngle(angle, angle_);

    return Decision(traj, std::min(power, 100.f), angle, length);
};


int Pod::isNextCPCrossed(std::vector<CheckPoint> otherCPs_, FinalCheckPoint finalCP_)
{
    sf::Vector2f CP_pos;

    if(nextCP_ > 0){
        CP_pos = otherCPs_[nextCP_-1].getPosition();
    }
    else{
        CP_pos = finalCP_.getPosition();
    }


    if(norm(pos_ - CP_pos) < 550){
        nextCP_ = (nextCP_ + 1) % (otherCPs_.size() + 1);
        if(nextCP_ == 1){
            lapCount_ ++;
            if(lapCount_ == NUMBER_OF_LAPS){
                return 1;
            }
        }
    }

    return 0;
}


// void Pod::isNextCPCrossed(std::vector<CheckPoint> otherCPs_, FinalCheckPoint finalCP_, sf::Time physicsTime)
// {
//     sf::Vector2f future_pos(pos_.x + vel_.x * (physicsTime / (physicsTime + PHYSICS_TIME_STEP)), pos_.y + vel_.x * (physicsTime / (physicsTime + PHYSICS_TIME_STEP)));
//     sf::Vector2f len((future_pos.x - pos_.x) / 5, (future_pos.y - pos_.y) / 5);
//     sf::Vector2f CP_pos;

//     if(nextCP_ > 0){
//         CP_pos = otherCPs_[nextCP_-1].getPosition();
//     }
//     else{
//         CP_pos = finalCP_.getPosition();
//     }

//     float norm;

//     for(int i=0; i<4; i++){
//         norm = std::sqrt((pos_.x + len.x * i - CP_pos.x)*(pos_.x + len.x * i - CP_pos.x)
//                      + (pos_.y + len.y * i - CP_pos.y)*(pos_.y + len.y * i - CP_pos.y));
//         if(norm < 600){
//             nextCP_ = (nextCP_ + 1) % (otherCPs_.size() + 1);
//             if(nextCP_ == 1){
//                 lapCount_ ++;
//                 if(lapCount_ == NUMBER_OF_LAPS){
//                     exit(0);
//                 }
//             }
//             break;
//         }
//     }
// }