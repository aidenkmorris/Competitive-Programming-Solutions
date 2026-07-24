// Aiden K Morris
// Problem: https://usaco.org/index.php?page=viewproblem2&cpid=892
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream read("sleepy.in");
    ofstream write("sleepy.out");

    int n;
    read >> n;

    vector<int> cows(n);

    for(auto &c : cows) {
        read >> c;
    }

    int numPreFinalDecrease = 0;

    for(int i = 0; i < n - 1; i++) {
        if(cows[i] > cows[i + 1]) {
            numPreFinalDecrease = i + 1;
        }
    }
    
    write << numPreFinalDecrease << "\n";
    return 0;
}