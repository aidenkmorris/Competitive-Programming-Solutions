// Aiden K Morris
// Problem: https://open.kattis.com/problems/cookiemonsterconcussion
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string n;
    cin >> n;

    while(n.length() > 1) {
        ll sum = 0;

        for(char c : n) {
            sum += c - '0';
        }

        n = to_string(sum);
    }

    cout << n << endl;
    return 0;
}