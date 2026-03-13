// Aiden K Morris
// Problem: https://judge.yosupo.jp/problem/associative_array
// Tags: Maps
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    map<ll, ll> arr;

    int n;
    cin >> n;

    for(int q = 0; q < n; q++) {
        int queryType;
        cin >> queryType;

        if(queryType == 0) {
            ll k, v;
            cin >> k >> v;
            arr[k] = v;
        } else {
            ll k;
            cin >> k;
            cout << arr[k] << "\n";
        }
    }

    return 0;
}