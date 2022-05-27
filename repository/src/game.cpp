#include "game.h"
#include "checkpoint.h"
#include "utils.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <cmath>
#include <iostream>
#include <pthread.h>

Game::Game() : finalCP_(sf::Vector2f((rand() % 14800) + 600.f, (rand() % 7800) + 600.f))
{
    int random = (rand() % 4) + 2;
    int flag = 0;

    sf::Vector2f temp;
    std::vector<sf::Vector2f> checkpointsPositions;


    // Generating random checkpoints
    for(int i=1; i<random+1; i++){

        while(1){

            temp.x = rand() % 14800 + 600.f;
            temp.y = rand() % 7800 + 600.f;


            // Checking if generated coordinates are not too close to final checkpoint
            if(fabs(temp.x - finalCP_.getPosition().x) < 1000 && fabs(temp.y - finalCP_.getPosition().y) < 1000) continue;

            // If at least a checkpoint has already been generated, checking if generated coordinates are not too close to any existing checkpoint
            if(i>1){
                for(int j=0; j<i; j++){
                    //printf("Boucle check coordinates\n");
                    if(fabs(temp.x - checkpointsPositions[j].x) < 1000 && fabs(temp.y - checkpointsPositions[j].y) < 1000){
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

void Game::addPod(char* loc, int decision_making)
{

    sf::Texture texture;
    sf::Sprite sprite;

    Pod pod({finalCP_.getPosition().x, finalCP_.getPosition().y}, 0, {0, 0}, decision_making);

    int s = pods_.size();

    pods_.reserve(s + 1);
    podsTextures_.reserve(s + 1);
    podsSprites_.reserve(s + 1);

    pods_.emplace_back(pod);

    podsTextures_.emplace_back(texture);
    podsSprites_.emplace_back(sprite);

    podsTextures_[s].loadFromFile(loc);

    podsSprites_[s].setTexture(podsTextures_[s]);

    scaleToMaxSize(podsSprites_[s], 800, 800);
    setOriginToCenter(podsSprites_[s]);
    podsSprites_[s].setPosition({800, 800});

    for(int i = 0; i < s+1; i++){
        podsSprites_[i].setTexture(podsTextures_[i]);
    }

}

int Game::updatePhysics()
{
    sf::Vector2f correct_target;

    for (unsigned int i=0; i<pods_.size(); i++)
    {
        Decision decision = pods_[i].getDecision(*this);

        pods_[i].power_ = decision.power_;

        pods_[i].angle_ = decision.angle_;

        correct_target.x = (decision.length_ * cos(pods_[i].angle_) + pods_[i].pos_.x);
        correct_target.y = (decision.length_ * sin(pods_[i].angle_) + pods_[i].pos_.y);

        
        if(decision.length_ != 0){
            pods_[i].vel_ = FRICTION_COEFF * ( pods_[i].vel_ + decision.power_ * (decision.traj_) / decision.length_);
        }
        else{
            pods_[i].vel_ = FRICTION_COEFF * pods_[i].vel_;
        }

        pods_[i].pos_ = pods_[i].pos_ + pods_[i].vel_;


        
        if(pods_[i].isNextCPCrossed(otherCPs_, finalCP_)){
            return i+1;
        }

        
        
        
    }


    physicsTime += PHYSICS_TIME_STEP;

    return 0;
}

void Game::updateGraphics(sf::Time frameTime)
{
    sf::Vector2f current_pos;
    float R = (physicsTime - frameTime)/(frameTime - lastFrameTime);

    for(unsigned int i=0; i<pods_.size(); i++)
    {
        current_pos = podsSprites_[i].getPosition();

        if (R>1)  podsSprites_[i].setPosition( current_pos + (pods_[i].pos_ - current_pos) / R );
        else podsSprites_[i].setPosition(pods_[i].pos_);
        podsSprites_[i].setRotation(pods_[i].angle_ * 180 / M_PI);
    }

    lastFrameTime = frameTime;
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