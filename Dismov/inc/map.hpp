#pragma once 
#ifndef MAP
#define MAP

#include "structs.hpp"
#include <string>
#include <unordered_map>
#include <vector>

class Entity;

class Map{
private:
    std::string map_name;
    duo map_dimensions;
    int entity_id;
    int entities_limit;
    
public:
    std::unordered_map<int, Entity*> entities; // Map for entities <int : entity id | Entity* : entity>
    std::vector<corpse*> corpses;
    Map(int width, int height, int entities_limit);
    ~Map();

    void set_map_name(std::string map_name);
    void set_map_dimensions(duo map_dimensions);
    void set_entities_limit(int entities_limit);
    
    int get_x();
    int get_y();
    
    int get_entities_count();
    int get_corpses_count();

    void add_entity(Entity* entity);
    void delete_entity(int entity_id);
    
    void add_corpse(corpse* corpse);
    void delete_corpse(int corpse_id);

    void run();
    void kill_all();
    
    std::vector<Entity*> get_entities_at(const duo& pos);
    std::vector<corpse*> get_corpses_at(const duo& pos);
};


#endif // MAP
