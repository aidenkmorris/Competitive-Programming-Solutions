// Aiden K Morris
// Problem: https://open.kattis.com/problems/jollyjumpers
// Tags: Sorting
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;

    while(cin >> n) {
        int solved = false;

        vector<int> elements(n);
        vector<int> sorted(n - 1);

        for(int &e : elements) {
            cin >> e;
        }

        for(int i = 0; i < n - 1; i++) {
            int ans = abs(elements[i] - elements[i + 1]);

            sorted[i] = ans;
        }

        sort(sorted.begin(), sorted.end());

        for(int i = 0; i < n - 1; i++) {
            if(sorted[i] != i + 1) {
                cout << "Not jolly" << endl;
                solved = true;
                break;
            }
        }

        if(!solved) {
            cout << "Jolly" << endl;
        }
    }
    
    return 0;
}