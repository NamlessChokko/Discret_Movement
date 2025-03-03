#pragma once 
#ifndef DISMOV
#define DISMOV

class Map;

class GameLoop{
private:
    Map *map;
    int emulation_speed;

public:
    GameLoop(Map *map);
    ~GameLoop();
    void run(int emulation_speed);
};



#endif //DISMOV