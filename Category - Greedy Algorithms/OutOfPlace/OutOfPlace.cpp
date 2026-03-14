// Aiden K Morris
// Problem: https://usaco.org/index.php?page=viewproblem2&cpid=785
// Tags: Greedy Algorithms
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream read("outofplace.in");
    ofstream write("outofplace.out");
    
    int n;
    read >> n;

    vector<int> cows(n);

    for(int &c : cows) {
        read >> c;
    }

    vector<int> sortedCows = cows;
    sort(sortedCows.begin(), sortedCows.end());

    int swaps = 0;

    for(int i = 0; i < n; i++) {
        if(cows[i] != sortedCows[i]) {
            swaps++;
        }
    }

    write << swaps - 1 << "\n";
    return 0;
}