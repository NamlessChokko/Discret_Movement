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
        if ((this->objective->get_position().x == this->get_position().x) && (this->objective->get_position().y == this->get_position().y)){
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

void Chaser::turn(){
    chase();
    if (this->objective->get_position() == this->get_position()){
        this->objective->kill();
    }
}