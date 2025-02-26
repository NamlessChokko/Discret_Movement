#pragma once
#ifndef INCLUDE
#define INCLUDE

#include <math.h>
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <random>
#include <algorithm>
#include <unistd.h>
#include <cstdlib>
#include <chrono>
#include <thread>

using namespace std;

// Structs: 

// Struct to pair two values
struct duo{ 
    int x, y; 
    void flip();
    void setZero(int op);
    void neg(int Z);
    void setRan(
        int op, 
        int max, 
        int min = 0, 
        const vector<int>& exclude = {}
    );
}; 





// Math functions:

// Find the maximum common divisor
int mcd (int a, int b);
// Enter two numbers and it will return the simplified form of the fraction between them
duo find_ratio(int a, int b);
// Generate a random number within a range
int randNum(
    int max, // Maximum number
    int min = 0, // Minimum number
    const vector<int>& exclude = {}, // Numbers to exclude
    bool real = false // True if you want float or real numbers
);





// Map:
class Map{
private:
    string map_name;
    duo map_dimensions;

public:

};





// Entity:
class Entity{
private:
    string entity_name;
    char entity_body;
    duo entity_position;
    duo entity_objective;
    duo route;
    int steps;
    bool isEntity_Static;
    bool entity_exists;
    Map map;

public:
    Entity();
    Entity(duo pos, duo obj, bool isAble);
    ~Entity();
    void name(string name);
    void body(char body);
    void position(duo pos);
    void objective(duo obj);
    void isStatic(bool isStatic);
    void doesExist(bool exists);

    string name();
    char body();
    duo position();
    duo objective();
    bool isStatic();
    bool doesExist();

    void move();
    void move(int dir);
    void move(duo _objective);
    void kill();
};





class events{
private:

public:
    events();
    ~events();
};





// Definitions:
constexpr int RIGHT = 0;
constexpr int UP = 1;
constexpr int LEFT = 2;
constexpr int DOWN = 3;

#endif // INCLUDE