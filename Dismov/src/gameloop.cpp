#include "../inc/gameloop.hpp"
#include "../Dismov.hpp"
#include "../inc/Basic.hpp"
#include <unistd.h>
#include <chrono>
#include <thread>
#include <algorithm>
#include <vector>

using std::cout;

GameLoop::GameLoop(Map* map){
    this->map = map;
};

GameLoop::~GameLoop(){
};

void GameLoop::run(int emulation_speed){
    int pause_time;
    long frame = 0;
    while (1){
        frame++;
        system("clear");
        pause_time = 1000 / emulation_speed;
        std::vector<Entity*> entities;
        cout << "#" << basic::rep_char(this->map->get_x(), '=') << "#";
        cout << '\n';
        for (int y = 0; y < this->map->get_y(); y++){
            cout << "#";
            for (int x = 0; x < this->map->get_x(); x++){
                duo position{x, y};
                entities = this->map->get_entities_at(position);

                if (!entities.empty()){
                    Entity* entity_to_render = nullptr;
                    for (Entity* entity : entities){
                        entity_to_render = entity;
                    }

                    if (entity_to_render != nullptr){
                        entity_to_render = entities.back();
                    }

                    cout << entity_to_render->get_color() << entity_to_render->get_body() << color::rst; 
                } else {
                    std::vector<corpse*> corpses = this->map->get_corpses_at(position);
                    if (!corpses.empty() && corpses.back() != nullptr){
                        cout << corpses.back()->body;      
                    }else{
                        cout << ' ';
                    }
                }
            }
            
            cout << "#";
            cout << '\n';
        }
        cout << "#" << basic::rep_char(this->map->get_x(), '=') << "#";
        cout << '\n';
        for (auto pair : map->entities){
            cout 
            << pair.second->get_color() 
            << pair.second->get_name() 
            << " : " 
            << to_string(pair.second->get_position()) 
            << " | "
            << "Kills: " << pair.second->get_kills()
            << " | "
            << "Deaths: " << pair.second->get_deaths()
            << color::rst << '\n';
        }
        cout << "Map: " << std::to_string(map->get_x()) << '|' << std::to_string(map->get_y()) << '\n';
        cout << "Frame: " << std::to_string(frame) << '\n';
        this->map->run();
        std::this_thread::sleep_for(std::chrono::milliseconds(pause_time)); 
    }
}
