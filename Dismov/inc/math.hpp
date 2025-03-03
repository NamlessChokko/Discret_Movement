#pragma once 
#ifndef MATH
#define MATH

#include "structs.hpp"
#include <vector>

struct duo;

namespace myMath {
/*
The Euclidean algorithm:

The Euclidean algorithm is a way to find the greatest 
common divisor of two positive integers. GCD of 
two numbers is the largest number that divides 
both of them. A simple way to find GCD is to 
factorize both numbers and multiply common prime factors.

Source: 
https://www.geeksforgeeks.org/euclidean-algorithms-basic-and-extended/
*/
int mcd (int a, int b);

int mcm (int a, int b);
duo find_ratio(int a, int b);
int randInt(
    int max, 
    int min = 0, 
    const std::vector<int>& exclude = {}
);
int find_distance(duo pointA, duo pointB);
bool even (int input);
}

#endif // MATH 