#pragma once 
#ifndef MATH
#define MATH

#include "structs.hpp"
#include <vector>

struct duo;

namespace myMath {
int mcd (int a, int b);
duo find_ratio(int a, int b);
int randInt(
    int max, 
    int min = 0, 
    const std::vector<int>& exclude = {}
);
bool even (int input);
}

#endif // MATH 