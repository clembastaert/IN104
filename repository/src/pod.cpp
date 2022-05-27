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
    power_ = 100;

};

// One method for 3 different ways of getting a decision from the pod, depending on the chosen parameter
Decision Pod::getDecision(Game gameSnapshot) const
{
    sf::Vector2f target;
    sf::Vector2f traj;

    float angle, diff, length;
    float power;

    if(decision_making_ == 0){ // Manual mode

        int left = 0;
        int right = 0;
        int up = 0;
        int down = 0;
        int throttle_down = 0;
        int throttle_up = 0;

        

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) left = 1;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) right = 1;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) up = 1;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) down = 1;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) throttle_down = 1;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) throttle_up = 1;

        target.x = pos_.x + (right-left);
        target.y = pos_.y + (down-up);
        power = std::max(0.f, std::min(100.f, power_ + 5 * (throttle_up-throttle_down)));

        traj = target - pos_;
        length = norm(traj);

        if(pos_ != target) angle = calculateAngle(pos_, target);
        else angle = angle_;
    }

    if(decision_making_ == 1){ // First AI mode : anticipating next checkpoint, adapting
                               // speed depending on distance and angle from next CP 
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
            if(length < 1250){
                power = 30;
            } 
            else{
                power = 100;
            }
        }

    }

    if(decision_making_ == 2){ // Second AI mode : same as before but adapting speed
                               // depending quadratically on distance from next CP (vs linearily) 
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
            if(length < 1750){
                power = std::min(30 * length / 1500, 30.f) + std::min(70 * (length * length / 3062500), 70.f);
            } 
            else{
                power = 100;
            }
        }

    }

    angle = legalAngle(angle, angle_); // Checking if desired angle is legal and if not, returning corrected angle

    return Decision(traj, power, angle, length);
};

// Updating pods next CP if it will cross the next one before next physics update
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

