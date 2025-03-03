#include "../../inc/math.hpp"
#include "../../inc/structs.hpp"
#include <cmath>
#include <random>
#include <algorithm>


int myMath::mcd (int a, int b) {
    a = abs(a); b = abs(b);
    if (a == 0) return b;
    return mcd(b % a, a);

}

int myMath::mcm(int a, int b){
    return (a * b) / myMath::mcd(a, b);
}

duo myMath::find_ratio(int x, int y){
    int mcd_r = mcd(abs(x), abs(y));
    if(x == 0){
        return {0, (y/mcd_r)};
    } else if(y == 0){
        return {(x/mcd_r), 0};
    } else {
        return {(x/mcd_r), (y/mcd_r)};
    }
}

int myMath::randInt(int max, int min, const std::vector<int>& exclude){
    
    std::random_device rd;
    std::mt19937 generator(rd());

    std::uniform_int_distribution<> distribution(min, max);
    int ran = distribution(generator);
    bool ex = false;

    for(int i = 0; i < static_cast<int>(exclude.size()); i++){
        if(ran == exclude[i]){
            ex = true;
        }
    }

    if(ex){
        return randInt(max, min, exclude);
    } else {
        return ran;
    }
}

int myMath::find_distance(duo pointA, duo pointB){
    int x_distance = abs(pointA.x - pointB.x);
    int y_distance = abs(pointA.y - pointB.y);

    return sqrt(pow(x_distance, 2) + pow(y_distance, 2));
}
