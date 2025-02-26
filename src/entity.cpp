#include "../include.hpp"


Entity::Entity(){
    this->entity_name = "Juan";
    this->entity_body = '@';
    this->entity_position = {0,0};
    this->entity_objective = {0,0};
    this->isEntity_Static = false;
    this->entity_exists = true;
};
Entity::Entity(duo _pos, duo _obj, bool _isStatic){
    this->entity_position = _pos;
    this->entity_objective = _obj;
    this->isEntity_Static = _isStatic;
};
Entity::~Entity(){
    kill();
};


void Entity::name(string _name){
    this->entity_name = _name;
};
void Entity::body(char _body){
    this->entity_body = _body;
};
void Entity::position(duo _pos){
    this->entity_position = _pos;
};
void Entity::objective(duo _obj){
    if ((_obj.x == entity_objective.x) && (_obj.y == entity_objective.y)){return;}
    this->entity_objective = _obj;
};
void Entity::isStatic(bool _isStatic){
    this->isEntity_Static = _isStatic;
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