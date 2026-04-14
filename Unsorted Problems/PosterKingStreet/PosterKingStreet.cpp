// Aiden K Morris
// Problem: https://www.hackerrank.com/contests/pacise-2026/challenges/pacise-poster-on-king-street
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> buildings(n);

    for(int &b : buildings) {
        cin >> b;
    }

    int maxArea = 0;

    for(int i = 0; i < n; i++) {
        int minHeight = buildings[i];

        if(minHeight == 0) continue;

        for(int j = i + 1; j < n; j++) {
            minHeight = min(minHeight, buildings[j]);

            if(minHeight == 0) break;

            maxArea = max(maxArea, minHeight * (j - i + 1));
        }
    }

    cout << maxArea << endl;

    return 0;
}