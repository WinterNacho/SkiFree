#include "globals.h"

float randomPosition(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> distrib(-SCREEN_SIZE_X * 0.125f, SCREEN_SIZE_X * 1.125f);

    return distrib(gen);
}