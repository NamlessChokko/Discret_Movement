#include "../../inc/math.hpp"
#include "../../inc/structs.hpp"
#include <cmath>
#include <random>
#include <algorithm>

using namespace std;

int myMath::mcd (int a, int b) {
    a = abs(a); b = abs(b);
    if (a == 0) return b;
    return mcd(b % a, a);

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
}

duo myMath::find_ratio(int a, int b) {
    int _mcd = mcd(a, b);
    return {a / _mcd, b / _mcd};
}

int myMath::randInt(
    int max, 
    int min, 
    const vector<int>& exclude
) {
    static std::random_device rd;  
    static std::mt19937 gen(rd());


    uniform_int_distribution<int> dist(min, max);
    int number;
    do {
        number = dist(gen);
    } while (
        find(exclude.begin(), exclude.end(), number) != exclude.end()
    );

    return number;
}

bool even (int input){
    return abs((input % 2) - 1);
}
