// Aiden K Morris
// Problem: https://usaco.org/index.php?page=viewproblem2&cpid=1227
// Tags: Greedy Algorithms
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    string cows;
    cin >> cows;

    int reversals = 0;

    for(int i = n - 2; i >= 0; i -= 2) {
        string currentPair = cows.substr(i, 2);
        
        if((currentPair == "GH" && reversals % 2 == 0) || 
           (currentPair == "HG" && reversals % 2 == 1)) {
            reversals++;
        } else {
            continue;
        }
    }

    cout << reversals << "\n";
    return 0;
}