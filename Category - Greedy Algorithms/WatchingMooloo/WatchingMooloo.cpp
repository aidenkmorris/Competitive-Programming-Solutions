// Aiden K Morris
// in collaboration with the Messiah University Competitive Programming Team
// Problem: https://usaco.org/index.php?page=viewproblem2&cpid=1301
// Tags: Greedy Algorithms
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;

    cin >> n >> k;

    ll previousDay;
    cin >> previousDay;

    ll currentDay;

    // Start with the price for the first day
    ll price = 1 + k;

    for(int i = 0; i < n - 1; i++) {
        cin >> currentDay;

        price += min((ll) 1 + k, currentDay - previousDay);

        previousDay = currentDay;
    }

    cout << price << "\n";
    
    return 0;
}