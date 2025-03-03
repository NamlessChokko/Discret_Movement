#include "../../inc/entity.hpp"
#include "../../inc/map.hpp"
#include "../../inc/structs.hpp"
#include "../../inc/constants.hpp"

using namespace std;


Entity::Entity(Map &map) : map(map){
    this->name = "Null";
    this->body = '0';
    this->position = {0,0};
    this->isStatic = true;
    this->exists = false;
};

Entity::~Entity(){
    kill();
};

void Entity::put_in(Map &map){
    this->map = map;
    map.add_entity(this);
};

void Entity::set_name(string name){
    this->name = name;
};
void Entity::set_body(char body){
    this->body = body;
};
void Entity::set_position(duo position){
    this->position = position;
};

void Entity::set_isStatic(bool isStatic){
    this->isStatic = isStatic;
};
void Entity::set_id(int id){
    this->id = id;
}

string Entity::get_name(){
    return name;
};
char Entity::get_body(){
    return body;
};
duo Entity::get_position(){
    return position;
};
bool Entity::get_isStatic(){
    return isStatic;
};
bool Entity::does_exist(){
    return exists;
}
int Entity::get_id(){
    return id;
};

void Entity::move(int dir){
    if (this->get_isStatic()){
        return;
    }

    duo new_pos = this->get_position();
    switch (dir){
        case RIGHT: new_pos.x ++; break;
        case UP: new_pos.y ++; break;
        case LEFT: new_pos.x --; break;
        case DOWN: new_pos.y --; break;
        default:
            return;
    }

    if (new_pos.x < 0 || new_pos.x >= map.get_x() || new_pos.y < 0 || new_pos.y >= map.get_y()){
        return;
    }

    this->set_position(new_pos);
};


void Entity::born(){
    if(exists){
        return;
    }

    this->exists = true;
    map.add_entity(this);
}

void Entity::kill(){
    if(!exists){
        return;
    }

    this->exists = false;
    this->body = '\0';
    this->position = {0,0};
    this->isStatic = true;
    this->name = "";

    map.delete_entity(this->id); 
    this->exists = false;
}

void Entity::turn(){
    return;
}