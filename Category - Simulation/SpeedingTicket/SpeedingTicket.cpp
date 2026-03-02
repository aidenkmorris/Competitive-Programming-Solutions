// Aiden K Morris
// Problem: https://usaco.org/index.php?page=viewproblem2&cpid=568
// Tags: Simulation
#include <iostream>
#include <vector>
#include <algorithm> // std::max()
#include <fstream>

// 100 miles on the road
const int ROAD_LENGTH = 100;

std::ifstream read("speeding.in");

// Splits the speed of each segment into the speed of each distinct mile
void speedPerMile(std::vector<int> &vec, int segments) {
    int start = 0;
    
    for(int i = 0; i < segments; i++) {
        int length, speed;
        read >> length >> speed;

        for(int j = start; j < start + length; j++) {
            vec[j] = speed;
        }

        start += length;
    }
}

int main() {
    int N, M;
    read >> N >> M;

    std::vector<int> speedLimit(ROAD_LENGTH);
    speedPerMile(speedLimit, N);

    std::vector<int> bessieSpeed(ROAD_LENGTH);
    speedPerMile(bessieSpeed, M);

    int max = 0;

    for(int i = 0; i < ROAD_LENGTH; i++) {
        int speedOver = bessieSpeed[i] - speedLimit[i];
        max = std::max(max, speedOver);
    }

    std::ofstream write("speeding.out");
    write << max << "\n";
    return 0;
}