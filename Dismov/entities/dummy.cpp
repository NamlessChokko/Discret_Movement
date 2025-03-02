#include "../Dismov.hpp"
#include "Dummy.hpp"
#include <cmath>
#include <string>

using namespace std;

Dummy::Dummy(Map &entity_map) : Entity(entity_map){
};

Dummy::~Dummy(){
};

void Dummy::turn(){
    move(randNum(3));
}