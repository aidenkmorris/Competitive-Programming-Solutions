// Aiden K Morris
// Problem: https://usaco.org/index.php?page=viewproblem2&cpid=1251
// Tags: Sorting
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> cows(n);

    for(ll &c : cows) {
        cin >> c;
    }

    sort(cows.rbegin(), cows.rend());

    ll maxMoney = 0;
    ll tuition = LLONG_MAX;

    for(int i = 0; i < n; i++) {
        ll currentTuition = min(tuition, cows[i]);
        ll currentMoney = (i + 1) * currentTuition;
        
        if(currentMoney < maxMoney) {
            continue;
        } else {
            maxMoney = currentMoney;
            tuition = currentTuition;
        }
    }

    cout << maxMoney << " " << tuition << "\n";
    return 0;
}