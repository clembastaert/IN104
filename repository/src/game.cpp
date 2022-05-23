#include "game.h"
#include "checkpoint.h"
#include "utils.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <cmath>
#include <iostream>

Game::Game() : finalCP_(sf::Vector2f((rand() % 14800) + 600.f, (rand() % 7800) + 600.f))
{
    int random = (rand() % 6) + 3;
    int flag = 0;

    sf::Vector2f temp;
    std::vector<sf::Vector2f> checkpointsPositions;

    // Generating random checkpoints
    for(int i=1; i<random+1; i++){
        while(1){

            temp.x = rand() % 14800 + 600.f;
            temp.y = rand() % 7800 + 600.f;

            // Checking if generated coordinates are not too close to final checkpoint
            if(fabs(temp.x - finalCP_.getPosition().x) < 1000 || fabs(temp.y - finalCP_.getPosition().y) < 1000) continue;

            // If at least a checkpoint has already been generated, checking if generated coordinates are not too close to any existing checkpoint
            if(i>1){
                for(int j=0; j<i; j++){
                    if(fabs(temp.x - checkpointsPositions[j].x) < 1000 || fabs(temp.y - checkpointsPositions[j].y) < 1000){
                        flag = 1;
                        break;
                    }
                }
            }

            if(flag){
                flag = 0;
                continue;
            }

            break;
        }
        
        checkpointsPositions.insert(checkpointsPositions.end(), temp);
    }

    otherCPs_.reserve(random);

    // Filling checkpoints list with generated coordinates
    for(int i=0; i<random; i++){
        otherCPs_.emplace_back(checkpointsPositions[i], i+1);
    }

    // Charging background texture and sprite + scaling
    backgroundTexture_.loadFromFile("../repository/Images/background.png");
    backgroundSprite_.setTexture(backgroundTexture_);
    scaleToMinSize(backgroundSprite_, 16000,9000);


    lastFrameTime = sf::milliseconds(0);
    physicsTime = sf::milliseconds(0);
}

Game::Game(std::vector<sf::Vector2f> checkpointsPositions) : finalCP_(checkpointsPositions[0])
{
    int size = checkpointsPositions.size();
    otherCPs_.reserve(size-1);

    for(int i=1; i<size; i++){
        otherCPs_.emplace_back(checkpointsPositions[i], i);
    }

    backgroundTexture_.loadFromFile("../repository/Images/background.png");
    backgroundSprite_.setTexture(backgroundTexture_);
    scaleToMinSize(backgroundSprite_, 16000,9000);


    lastFrameTime = sf::milliseconds(0);
    physicsTime = sf::milliseconds(0);
}

void Game::addPod(char* loc)
{

    sf::Texture texture;
    sf::Sprite sprite;

    Pod pod({800, 800}, 0, {0, 0});

    int st = podsTextures_.size();
    int ss = podsSprites_.size();

    pods_.emplace_back(pod);

    podsTextures_.reserve(st + 1);
    podsSprites_.reserve(ss + 1);

    podsTextures_.emplace_back(texture);
    podsSprites_.emplace_back(sprite);

    podsTextures_[st].loadFromFile(loc);

    podsSprites_[ss].setTexture(podsTextures_[st]);

    scaleToMaxSize(podsSprites_[ss], 800, 800);
    setOriginToCenter(podsSprites_[ss]);
    podsSprites_[ss].setPosition({800, 800});

    

}

void Game::updatePhysics()
{
    sf::Vector2f traj;
    double angle;
    float length;
    sf::Vector2f correct_target;

    for (Pod &pod : pods_)
    {
        Decision decision = pod.getDecision(*this);

        angle = 2*M_PI - calculateAngle(pod.pos_, decision.target_);

        if(fabs(angle-pod.angle_) > M_PI/10){
            if(angle-pod.angle_ >= 0) angle = pod.angle_ + (M_PI/10);
            else angle = 2*M_PI - pod.angle_ - (M_PI/10);

        }
       
        pod.angle_ = angle;
        

        traj = decision.target_ - pod.pos_;

        length = std::sqrt(traj.x*traj.x + traj.y*traj.y);

        correct_target.x = (length * cos(angle) + pod.pos_.x);
        correct_target.y = (length * sin(angle) + pod.pos_.y);

        traj = correct_target - pod.pos_;

        pod.pos_ = pod.pos_ + pod.vel_;
        pod.vel_ = FRICTION_COEFF * ( pod.vel_ + decision.power_ * (traj) / length);

        
        pod.isNextCPCrossed(otherCPs_, finalCP_, physicsTime);
        
        
    }


    physicsTime += PHYSICS_TIME_STEP;
}

void Game::updateGraphics(sf::Time frameTime)
{
    for(unsigned int i=0; i<pods_.size(); i++)
    {
        podsSprites_[i].setPosition(pods_[i].pos_ + pods_[i].vel_ * (frameTime / (physicsTime + PHYSICS_TIME_STEP)));
        podsSprites_[i].setRotation(pods_[i].angle_ * 180 / M_PI);
    }
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(backgroundSprite_, states);
    target.draw(finalCP_, states);

    for (const auto &cp : otherCPs_)
    {
        target.draw(cp, states);
    }

    for (sf::Sprite podSprite : podsSprites_)
    {
        target.draw(podSprite, states);
    }
}