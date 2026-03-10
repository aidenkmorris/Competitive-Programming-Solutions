// Aiden K Morris
// Problem: https://cses.fi/problemset/task/1623
// Tags: Complete Search
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> weights;

ll minimumDifference(ll group1 = 0, ll group2 = 0, ll index = 0) {
    if(index == weights.size()) {
        return abs(group1 - group2);
    }

    return min(
        minimumDifference(group1 + weights[index], group2, index + 1),
        minimumDifference(group1, group2 + weights[index], index + 1)
    );
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    weights = vector<ll>(n);

    for(ll &w : weights) {
        cin >> w;
    }

    cout << minimumDifference() << "\n";
    
    return 0;
}