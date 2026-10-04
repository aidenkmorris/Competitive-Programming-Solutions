// Aiden K Morris
// Problem: https://naq26.kattis.com/contests/naq26/problems/sixseven3
#include <bits/stdc++.h>
using namespace std;

int components[] = {1, 11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111};

void solveCase() {
    int n;
    cin >> n;

    int current = 0;
    int index = 0;

    while(current < n) {
        if(index == 9) {
            cout << "-1\n";
            return;
        }
        
        current += components[index++];
    }

    int second = current - components[--index];
    index--;

    int componentsUsed = 1;

    while(second < current && second < n && componentsUsed < 9 - index) {
        second += components[index];
        componentsUsed++;
    }

    int answer = min(current, second);

    if(second < n) {
        answer = current;
    }

    cout << answer << "\n";
}

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) solveCase();
    
    return 0;
}