// Aiden K Morris
// Problem: https://usaco.org/index.php?page=viewproblem2&cpid=664
// Tags: Simulation
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility> // std::pair
#include <fstream>

int main() {
    std::ifstream read("blocks.in");

    int alphabet[26] = {0};

    int n;
    read >> n;

    std::vector<std::pair<std::string, std::string>> blocks(n);

    for(auto &b : blocks) {
        read >> b.first >> b.second;
    }

    // For each block...
    for(auto &b : blocks) {
        // The maximum number of each letter needed
        // per side of the block
        int maxFirst[26] = {0};
        int maxSecond[26] = {0};

        // The number of each letter needed
        // for the first side of the block
        for(int i = 0; i < b.first.length(); i++) {
            char c = b.first[i];
            int index = c - 'a';
            maxFirst[index]++;
        }

        // The number of each letter needed
        // for the second side of the block
        for(int i = 0; i < b.second.length(); i++) {
            char c = b.second[i];
            int index = c - 'a';
            maxSecond[index]++;
        }

        // Increases the maximum number needed of each letter
        // by the greater needed number of either side of block
        for(int i = 0; i < 26; i++) {
            alphabet[i] += std::max(maxFirst[i], maxSecond[i]);
        }
    }

    std::ofstream write("blocks.out");

    for(int i = 0; i < 26; i++) {
        write << alphabet[i] << "\n";
    }

    return 0;
}