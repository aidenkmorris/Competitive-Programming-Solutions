// Aiden K Morris
// Problem: https://codeforces.com/contest/863/problem/B
// Tags: Sorting, Complete Search, Greedy Algorithms
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    vector<int> weights(2 * n);

    for(int &w : weights) {
        cin >> w;
    }

    sort(weights.begin(), weights.end());
    
    int minimumTotalInstability = INF;
    
    for(int first = 0; first < weights.size(); first++) {
        for(int second = first + 1; second < weights.size(); second++) {
            vector<int> weightsTandem = weights;
            weightsTandem.erase(weightsTandem.begin() + second);
            weightsTandem.erase(weightsTandem.begin() + first);

            int totalInstability = 0;

            for(int i = 0; i < weightsTandem.size(); i += 2) {
                int instability = abs(weightsTandem[i] - weightsTandem[i + 1]);
                totalInstability += instability;
            }

            minimumTotalInstability = min(minimumTotalInstability, totalInstability);
        }
    }

    cout << minimumTotalInstability << "\n";
    return 0;
}