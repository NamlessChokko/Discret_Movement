#include "../inc/gameloop.hpp"
#include "../Dismov.hpp"
#include "../inc/Basic.hpp"
#include <unistd.h>
#include <chrono>
#include <thread>

using namespace std;

GameLoop::GameLoop(Map& map, int fps) : map(map), fps(fps){
};

GameLoop::~GameLoop(){
};

void GameLoop::run(){
    while (1){
        system("clear");

        cout << "#" << rep_char(map.get_x() - 2, '=') << "#";
        for (int x = 0; x < map.get_x(); x++){
            cout << "#";
            for (int y = 0; y < map.get_y(); y++){
                duo position{x, y};

                if (map.positions.find(position) != map.positions.end()){
                    cout << map.positions[position]->get_body();
                }
                

            }
            
            cout << "#";
            cout << '\n';
        }
        cout << "#" << rep_char(map.get_x() - 2, '=') << "#";
        map.run();
        this_thread::sleep_for(chrono::milliseconds(150)); 
    }
}