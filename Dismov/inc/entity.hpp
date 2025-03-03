#pragma once
#ifndef ENTITY
#define ENTITY

#include "structs.hpp"
#include <string>
class Map;

class Entity {
protected:
    Map &map;
    std::string name;
    char body;
    duo position;
    bool isStatic;
    bool exists;
    int id;
    bool immortal;
    std::string color;
    int kills;
    int deaths;

public:
    Entity(Map &map);
    virtual ~Entity();
    void put_in(Map &map);
    void set_name(std::string name);
    void set_body(char body);
    void set_position(duo pos);
    void set_isStatic(bool isStatic);
    void set_id(int id);
    void set_immortal(bool immortal);
    void set_color(std::string color);
    
    std::string get_name();
    char get_body();
    duo get_position();
    bool get_isStatic();
    int get_id();
    bool get_immortal();
    bool does_exist();
    std::string get_color();
    int get_kills();
    int get_deaths();
    
    
    virtual void turn();
    void move();
    void move(int dir);
    void kill();
    void born();
};


#endif // ENTITY