#include "../../inc/map.hpp"
#include "../../inc/entity.hpp"
#include "../../inc/structs.hpp"
#include <string>
#include <unordered_map>

using namespace std;


Map::Map(int width, int height, int entities_limit){
    this->map_dimensions = {width, height};
    this->entities_limit = entities_limit;
    this->entities_count = 0;
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
    return this->entities_count;
}

void Map::add_entity(Entity* entity){
    if (!entity || entities_count + 1 >= entities_limit){
        return;
    }

    this->positions.insert(make_pair(entity->get_position(), entity));
    this->entities.insert(make_pair(entities_count, entity));
    this->entities_count++;
    entity->set_id(entities_count);
}
void Map::delete_entity(int entity_id){
    if (entities.find(entity_id) == entities.end()){
        return;
    }

    delete entities[entity_id];
    entities.erase(entity_id);
    entities_count--;
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

