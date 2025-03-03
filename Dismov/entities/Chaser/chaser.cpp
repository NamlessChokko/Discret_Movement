#include "Chaser.hpp"
#include <cmath>
#include <string>

using namespace std;


Chaser::Chaser(Map &entity_map) : Entity(entity_map){
    this->objective = nullptr;
}

Chaser::~Chaser(){
    if (this->objective){
        delete this->objective;
    }
}

void Chaser::set_objective (Entity* objective){
    if (objective == nullptr){
        return;
    }

    this->objective = objective;
};

void Chaser::chase(){
    if (!this->objective || !this->objective->does_exist()){
        return;
    }
    if (this->objective->get_position() == this->get_position()){ 
        return;
    }

    int x_distance = this->objective->get_position().x - get_position().x;
    int y_distance = this->objective->get_position().y - get_position().y;
    
    if (abs(x_distance) > abs(y_distance)){
        int run = myMath::find_ratio(x_distance, y_distance).x;
        int x_direction = (run > 0) ? RIGHT : LEFT;
        this->Entity::move(x_direction);
    } else {
        int rise = myMath::find_ratio(x_distance, y_distance).y;
        int y_direction = (rise > 0) ? UP : DOWN;
        this->Entity::move(y_direction);
    }    
};

void Chaser::kill_objective(){
    if (this->objective == nullptr){
        return;
    }
    if (!this->objective->does_exist()){
        return;
    }
    if (this->objective->get_position() == this->get_position()){
        this->kills++;
        this->objective->kill();
    }
};

void Chaser::turn(){
    chase();
    kill_objective();
}