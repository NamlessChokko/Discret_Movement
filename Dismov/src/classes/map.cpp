#include "../../inc/map.hpp"
#include "../../inc/entity.hpp"
#include "../../inc/structs.hpp"
#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>

using std::string;
using std::make_pair;
using std::vector;

Map::Map(int width, int height, int entities_limit){
    this->map_dimensions = {width, height};
    this->entities_limit = entities_limit;
    this->entity_id = 0;
}
Map::~Map(){
    for(auto &entity : entities){
        delete entity.second;
    }
    for (auto &corpse : corpses){
        delete corpse;
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
    return this->entities.size();
}
int Map::get_corpses_count(){
    return this->corpses.size();
}

void Map::add_entity(Entity* entity){
    if (entity == nullptr || static_cast<int>(entities.size()) + 1 >= entities_limit){
        return;
    }

    std::cout << "Entity name: ";
    std::cout << entity->get_name() << '\n';
    this->entity_id++;
    this->entities.insert(make_pair(this->entity_id, entity));
    entity->set_id(this->entity_id);
}
void Map::delete_entity(int entity_id){
    if (entities.find(entity_id) == entities.end()){
        return;
    }
    delete entities[entity_id];
    entities.erase(entity_id);
}

void Map::add_corpse(corpse* corpse){
    this->corpses.push_back(corpse);
}
void Map::delete_corpse(int corpse_id){
    if(corpses.empty()){
        return;
    }
    if (static_cast<int>(corpses.size()) < corpse_id){
        return;
    }
    corpses.erase(corpses.begin() + corpse_id);
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

std::vector<Entity*> Map::get_entities_at(const duo& pos) { 
    std::vector<Entity*> entities = {}; 
    if (this->entities.size() == 0){
        return entities;
    }; 

    for (const auto& pair : this->entities) {
        if (pair.second->get_position() == pos && pair.second->does_exist()) {
            entities.push_back(pair.second); 
        }
    }
    
    return entities; 
}
std::vector<corpse*> Map::get_corpses_at(const duo& pos){
    std::vector<corpse*> found_corpses = {};
    if (this->corpses.empty()){
        return found_corpses;
    }

    for (const auto& corpse : this->corpses) {
        if (corpse->position == pos) {
            found_corpses.push_back(corpse);
        }
    }
    
    return found_corpses;
}
