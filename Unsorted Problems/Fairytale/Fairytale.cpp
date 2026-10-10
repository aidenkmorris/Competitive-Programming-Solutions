// Aiden K Morris
// Problem: https://open.kattis.com/problems/fairytale
#include <bits/stdc++.h>
using namespace std;

void solveCase() {
    int n;
    cin >> n;

    int stringsUsedBits = 0;

    for(int i = 0; i < n; i++) {
        int pitch;
        cin >> pitch;

        if(pitch <= 10) stringsUsedBits = stringsUsedBits | 1;
        else if(pitch <= 20) stringsUsedBits = stringsUsedBits | 2;
        else if(pitch <= 30) stringsUsedBits = stringsUsedBits | 4;
        else stringsUsedBits = stringsUsedBits | 8;
    }

    int stringsUsed = 0;

    while(stringsUsedBits) {
        stringsUsed += stringsUsedBits & 1;
        stringsUsedBits >>= 1;
    }

    cout << stringsUsed << "\n";
}

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) solveCase();
    
    return 0;
}