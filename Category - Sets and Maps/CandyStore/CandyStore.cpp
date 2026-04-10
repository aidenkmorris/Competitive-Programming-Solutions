// Aiden K Morris
// Problem: https://open.kattis.com/problems/candystore
// Tags: Maps
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    
    cin >> n >> q;
    
    unordered_map<string, string> initials;
    
    string first, last, initial;
    
    for(int i = 0; i < n; i++) {
        cin >> first >> last;
        initial = first[0];
        initial += last[0];
        
        if(initials.count(initial) == 0) {
            initials[initial] = first + " " + last;
        } else {
            initials[initial] = "ambiguous";
        }
    }
    
    string query;
    
    for(int i = 0; i < q; i++) {
        cin >> query;
        
        if(initials.count(query) == 0) {
            cout << "nobody" << endl;
        } else {
            cout << initials[query] << endl;
        }
    }
    
    return 0;
}
