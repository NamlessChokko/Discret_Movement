#pragma once 
#ifndef DISMOV
#define DISMOV

class Map;

class GameLoop{
private:
    Map *map;
    int fps;

public:
    GameLoop(Map *map, int fps);
    ~GameLoop();
    void set_speed(int fps);
    int get_speed();
    void run();
};



#endif //DISMOV