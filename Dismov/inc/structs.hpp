#pragma once 
#ifndef STRUCTS
#define STRUCTS

#include "math.hpp"
#include <vector>

// Duo: 
// -- Struct use to pair to integer values:
// -- flip() Swap values of x and y
// -- setZero() Set x or y to 0 depending on the value of op (0 for x, 1 for y)
// -- neg() Negate x or y depending on the value of op (0 for x, 1 for y)
// -- setRan() Set x or y to a random number between min and max, excluding the values in exclude
// -- gcd() Return the greatest common divisor of x and y
struct duo{ 
    int x, y; 
    void swap();
    void setZero(int op);
    void neg(int Z);
    void setRan(
        int op, 
        int max, 
        int min = 0, 
        const std::vector<int>& exclude = {}
    );
    int gcd();
    bool operator ==(const duo& other) const;

}; 

struct hash_duo {
    size_t operator()(const duo& d) const {
        return std::hash<int>()(d.x) ^ (std::hash<int>()(d.y) << 1);
    }
};

#endif // STRUCTS

