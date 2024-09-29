#include "globals.h"

float randomPosition(float min_float, float max_float){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> distrib(min_float, max_float);

    return distrib(gen);
}