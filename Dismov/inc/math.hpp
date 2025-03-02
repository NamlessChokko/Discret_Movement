#pragma once 
#ifndef MATH
#define MATH

#include "structs.hpp"
#include <vector>

struct duo;

int mcd (int a, int b);
duo find_ratio(int a, int b);
int randNum(
    int max, 
    int min = 0, 
    const std::vector<int>& exclude = {}, 
    bool real = false
);
bool even (int input);

#endif // MATH 