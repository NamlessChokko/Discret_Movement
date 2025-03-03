#include "../../inc/map.hpp"
#include "../../inc/entity.hpp"
#include "../../inc/structs.hpp"
#include <string>
#include <unordered_map>
#include <iostream>

using std::string;
using std::make_pair;

Map::Map(int width, int height, int entities_limit){
    this->map_dimensions = {width, height};
    this->entities_limit = entities_limit;
    this->entity_id = 0;
}
Map::~Map(){
    for(auto &entity : entities){
        delete entity.second;
    }
}

void Map::set_map_name(string map_name){
    this->map_name = map_name;
}
void Map::set_map_dimensions(duo map_dimensions){
    this->map_dimensions = map_dimensions;
}
void Map::set_entities_limit(int entities_limit){
    this->entities_limit = entities_limit;
}


int Map::get_x(){
    return this->map_dimensions.x;
}
int Map::get_y(){
    return this->map_dimensions.y;
}

int Map::get_entities_count(){
    return entities.size();
}

void Map::add_entity(Entity* entity){
    if (entity == nullptr || this->get_entities_count() + 1 >= entities_limit){
        return;
    }

    this->entity_id++;
    
    std::cout << "Entity name: ";
    std::cout << entity->get_name() << '\n';
    this->entities.insert(make_pair(entity_id, entity));
}
void Map::delete_entity(int entity_id){
    if (entities.find(entity_id) == entities.end()){
        return;
    }

    delete entities[entity_id];
    entities.erase(entity_id);
}
void Map::run(){
    for(auto &entity : entities){
        entity.second->turn();
    }
}
void Map::kill_all() {
    for(auto &entity : entities){
        entity.second->kill();
    }
}

std::vector<Entity*> Map::get_entities_at(const duo& pos) { // ADDED: Implementation of get_entity_at.
    std::vector<Entity*> entities; 
    for (const auto& pair : this->entities) {
        if (pair.second->get_position() == pos && pair.second->does_exist()) {
            entities.push_back(pair.second);
        }
    }
    return entities; // No entity found at that position.
}

