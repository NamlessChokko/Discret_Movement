#include "../../Dismov.hpp"
#include "Cleaner.hpp"
#include <limits.h>

Cleaner::Cleaner(Map &map) : Chaser(map){
    this->color = color::rst;
}

Cleaner::~Cleaner(){
}
void Cleaner::kill_objective(){
    if (this->objective != nullptr && this->objective->position == this->get_position()){
        this->kills++;
        this->map.delete_corpse(this->corpse_id);
        this->objective = nullptr;
    }
}

void Cleaner::find_objective(){
    int distance = INT_MAX;
    int corpse_id = -1;
    std::vector<corpse*> corpses = this->map.corpses;
    if (corpses.empty()){
        this->objective = nullptr;
        return;
    }
    
    for (int i = 0; i < static_cast<int>(corpses.size()); i++){
        if (myMath::find_distance(this->get_position(), corpses[i]->position) < distance) {
            distance = myMath::find_distance(this->get_position(), corpses[i]->position);
            corpse_id = i;
        } 
    }
    if (corpse_id != -1){
        this->corpse_id = corpse_id;
        this->objective = corpses[corpse_id];
    }
}

void Cleaner::turn(){
    find_objective();
    if (this->objective == nullptr){
        move(myMath::randInt(3));
    } else {
        chase();
    }
    
    kill_objective();
}

void Cleaner::chase(){
    if (!this->objective){
        return;
    }
    if (this->objective->position == this->get_position()){  
        return;
    }

    int x_distance = this->objective->position.x - get_position().x;
    int y_distance = this->objective->position.y - get_position().y;
    
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
