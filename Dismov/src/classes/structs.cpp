#include "../../inc/structs.hpp"
#include "../../inc/math.hpp"

using namespace std;

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
    const vector<int>& exclude
){
    if (op){
        this->y = randNum(max, min, exclude, false);
    } else if (!op){
        this->x = randNum(max, min, exclude, false);
    }
}

int duo::gcd(){
    return mcd(this->x, this->y);
}

bool duo::operator==(const duo& other) const {
    return (x == other.x) && (y == other.y);
}