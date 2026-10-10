// Aiden K Morris
// Problem: https://open.kattis.com/problems/espressomacchiato
#include <bits/stdc++.h>
using namespace std;

void solveCase() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i + j + 1 == n) {
                cout << 'C';
            }
            else {
                cout << '.';
            }
        }

        cout << "\n";
    }
}

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) solveCase();
    
    return 0;
}