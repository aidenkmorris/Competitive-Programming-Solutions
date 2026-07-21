// Aiden K Morris
// Problem: https://open.kattis.com/problems/fractionalsequence
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n;
    cin >> n;

    ll x = 1;

    // Find x: whole part
    while(x * (x + 1) / 2 < n) x++;
    
    cout << x;

    // Find unsimplified numerator of fractional part
    ll un = n - x * (x - 1) / 2 - 1;

    // If there is a fractional component...
    if(un != 0) {
        // Simplify fractional part
        ll gcf = gcd(un, x);
        cout << " " << un / gcf << "/" << x / gcf ;
    }

    cout << "\n";
    return 0;
}