#include "../include.hpp"


Entity::Entity(){
    this->entity_name = "Juan";
    this->entity_body = '@';
    this->entity_position = {0,0};
    this->entity_objective = {0,0};
    this->isEntity_Static = false;
    this->entity_exists = true;
};
Entity::Entity(duo entity_position , duo entity_objective , bool isEntity_Static){
    this->entity_position = entity_position;
    this->entity_objective = entity_objective;
    this->isEntity_Static = isEntity_Static;
};
Entity::~Entity(){
    kill();
};


void Entity::name(string entity_name ){
    this->entity_name = entity_name;
};
void Entity::body(char entity_body){
    this->entity_body = entity_body;
};
void Entity::position(duo entity_position){
    this->entity_position = entity_position;
};
void Entity::objective(duo entity_objective){
    if ((entity_objective.x == entity_objective.x) && (entity_objective.y == entity_objective.y)){return;}
    this->entity_objective = entity_objective;
};
void Entity::isStatic(bool isEntity_Static){
    this->isEntity_Static = isEntity_Static;
};

string Entity::name(){
    return entity_name;
};
char Entity::body(){
    return entity_body;
};
duo Entity::position(){
    return entity_position;
};
duo Entity::objective(){
    return entity_objective;
};
bool Entity::isStatic(){
    return isEntity_Static;
};
bool Entity::doesExist(){
    return entity_exists;
}

void Entity::move(){
    if (this->isStatic()){
        return;
    }

    int dir = randNum(3);
    duo new_pos = this->position();
    switch (dir){
        case RIGHT: new_pos.x ++; break;
        case UP: new_pos.y ++; break;
        case LEFT: new_pos.x --; break;
        case DOWN: new_pos.y --; break;
        default:
            return;
    }

    this->position(new_pos);
};
void Entity::move(int dir){
    if (this->isStatic()){
        return;
    }

    duo new_pos = this->position();
    switch (dir){
        case RIGHT: new_pos.x ++; break;
        case UP: new_pos.y ++; break;
        case LEFT: new_pos.x --; break;
        case DOWN: new_pos.y --; break;
        default:
            return;
    }

    this->position(new_pos);
};
void Entity::move(duo _objective){
    if ((_objective.x == this->position().x) && (_objective.y == this->position().y)){
        return;
    }

    int x_distance = _objective.x - position().x;
    int y_distance = _objective.y - position().y;
    
    if (abs(x_distance) > abs(y_distance)){
        int run = find_ratio(x_distance, y_distance).x;
        int x_direction = (run > 0) ? RIGHT : LEFT;
        this->move(x_direction);
    } else {
        int rise = find_ratio(x_distance, y_distance).y;
        int y_direction = (rise > 0) ? UP : DOWN;
        this->move(y_direction);
    } 
}
void Entity::kill(){
    this->entity_exists = false;
    this->entity_body = '\0';
    this->entity_position = {0,0};
    this->entity_objective = {0,0};
    this->isEntity_Static = true;
    this->entity_name = "";
}