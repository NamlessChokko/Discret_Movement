#include "../Dismov.hpp"
#include "Dummy.hpp"
#include <cmath>
#include <string>


Dummy::Dummy(Map &entity_map) : Entity(entity_map){
};

Dummy::~Dummy(){
};

void Dummy::turn(){
    move(myMath::randInt(3));
}