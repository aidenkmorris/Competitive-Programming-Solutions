// Aiden K Morris
// Problem: https://usaco.org/index.php?page=viewproblem2&cpid=592
// Tags: Sorting, Simulation
#include <bits/stdc++.h>
using namespace std;

int explodeRight(const vector<int> &bales, const int &target) {
    int start = target;
    int current = start + 1;
    int radius = 1;
    
    while(true) {
        while(current + 1 < bales.size() && bales[current + 1] - bales[start] <= radius) {
            current++;
        }

        if(bales[current] - bales[start] <= radius) {
            radius++;
            start = current;
            current = start + 1;

            if(current >= bales.size()) {
                return bales.size() - target - 1;
            }
        } else {
            return current - target - 1;
        }
    }
}

int explodeLeft(const vector<int> &bales, const int &target) {
    int start = target;
    int current = start - 1;
    int radius = 1;
    
    while(true) {
        while(current - 1 >= 0 && bales[start] - bales[current - 1] <= radius) {
            current--;
        }

        if(bales[start] - bales[current] <= radius) {
            radius++;
            start = current;
            current = start - 1;

            if(current < 0) {
                return target;
            }
        } else {
            return target - current - 1;
        }
    }
}

int explode(const vector<int> &bales, const int target) {
    return explodeLeft(bales, target) + explodeRight(bales, target) + 1;
}

int main() {
    ifstream read("angry.in");
    ofstream write("angry.out");

    int n;
    read >> n;

    vector<int> bales(n);

    for(int &b : bales) {
        read >> b;
    }

    sort(bales.begin(), bales.end());

    int maxExplosions = 0;

    for(int t = 0; t < n; t++) {
        vector<int> currentBales = bales;

        int currentExplosions = explode(currentBales, t);

        maxExplosions = max(maxExplosions, currentExplosions);
    }

    write << maxExplosions << "\n";
}