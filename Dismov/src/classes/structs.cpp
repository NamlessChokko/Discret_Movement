#include "../../inc/structs.hpp"
#include "../../inc/math.hpp"
#include "../../inc/entity.hpp"
#include <string>

void duo::swap(){
    int z = y;
    y = x;
    x = z;
}

void duo::setZero(int op){
    if (op){
        this->y = 0;
        return;
    } else if (!op){
        this->x = 0;
        return;
    }
} 

void duo::neg(int op){
    if (op){
        this->y = -1 * y;
        return;
    } else if (!op){
        this->x = -1 * y;
        return;
    }
}

void duo::setRan(
    int op, 
    int max, 
    int min, 
    const std::vector<int>& exclude
){
    if (op){
        this->y = myMath::randInt(max, min, exclude);
    } else if (!op){
        this->x = myMath::randInt(max, min, exclude);
    }
}

int duo::gcd(){
    return myMath::mcd(this->x, this->y);
}

bool duo::operator==(const duo& other) const {
    return (x == other.x) && (y == other.y);
};

std::string to_string(duo input){
    return "{" + std::to_string(input.x) + ", " + std::to_string(input.y) + "}";
};


corpse::corpse(duo position, char body){
    this->position = position;
    this->body = body;
};

corpse* to_corpse(Entity* entity){
    corpse* newCorpse = new corpse(entity->get_position(), entity->get_body());
    return newCorpse;
}
