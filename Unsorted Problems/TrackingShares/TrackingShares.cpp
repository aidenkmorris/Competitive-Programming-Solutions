// Aiden K Morris
// in collaboration with the Messiah University Competitive Programming Team
// Problem: https://open.kattis.com/problems/trackingshares
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c;
    cin >> c;
    
    // Create vector of records
    vector<vector<int>> records(c, vector<int>(365));
    
    // Get input
    for(int i = 0; i < c; i++) {
        int k;
        cin >> k;
        
        for(int j = 0; j < k; j++) {
            int n, d;
            cin >> n >> d;
            records[i][d - 1] = n;
        }
    }
    
    // Create vector of current share amounts for each company
    vector<int> shares(c);
    
    for(int day = 0; day < 365; day++) {
        bool update = false;
        
        for(int company = 0; company < c; company++) {
            if(records[company][day] != 0) {
                shares[company] = records[company][day];
                update = true;
            }
        }
        
        if(update) {
            int total = 0;
            
            for(int i = 0; i < c; i++) {
                total += shares[i];
            }
            
            cout << total << " ";
        }
    }
    
    return 0;
}