#include <random>
#include <iostream>
#include <chrono>
using namespace std;
int random_number(int min, int max) {
    static mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> dis(min, max);
    return dis(gen);
}

