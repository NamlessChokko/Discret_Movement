#include "../inc/gameloop.hpp"
#include "../Dismov.hpp"
#include "../inc/Basic.hpp"
#include <unistd.h>
#include <chrono>
#include <thread>
#include <algorithm>
#include <vector>

using namespace std;

GameLoop::GameLoop(Map* map, int fps){
    this->map = map;
    this->fps = fps;
};

GameLoop::~GameLoop(){
};

void GameLoop::run(){
    int pause_time = 1000 / fps;
    while (1){
        system("clear");

        cout << "#" << basic::rep_char(this->map->get_x(), '=') << "#";
        cout << '\n';
        for (int y = 0; y < this->map->get_y(); y++){
            cout << "#";
            for (int x = 0; x < this->map->get_x(); x++){
                duo position{x, y};
                std::vector<Entity*> entities = this->map->get_entities_at(position);

                if (entities.empty()){
                    cout << " ";
                } else {
                    Entity* entity_to_render = nullptr;
                    for (Entity* entity : entities){
                        if (!entity->get_isStatic()){
                            entity_to_render = entity;
                        }
                    }

                    if (entity_to_render == nullptr){
                        entity_to_render = entities.back();
                    }
                    
                    cout << entity_to_render->get_body(); 
                }
            }
            
            cout << "#";
            cout << '\n';
        }
        cout << "#" << basic::rep_char(this->map->get_x(), '=') << "#";
        cout << '\n';
        this->map->run();
        this_thread::sleep_for(chrono::milliseconds(pause_time)); 
    }
}
