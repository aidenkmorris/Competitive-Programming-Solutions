// Aiden K Morris
// Problem: https://cses.fi/problemset/task/1624/
// Tags: Complete Search
#include <bits/stdc++.h>
using namespace std;

const int boardSize = 8;
vector<vector<bool>> tileReserved(boardSize, vector<bool>(boardSize));
vector<bool> rankReserved(boardSize);
vector<bool> diagonal1Reserved(2 * boardSize - 1);
vector<bool> diagonal2Reserved(2 * boardSize - 1);
int positions = 0;

void solve(int file = 0) {
    if(file == boardSize) {
        positions++;
        return;
    }

    for(int rank = 0; rank < boardSize; rank++) {
        if(rankReserved[rank] || tileReserved[rank][file]
            || diagonal1Reserved[rank + file] || diagonal2Reserved[rank - file + boardSize - 1] ) {

            continue;
        }
        
        rankReserved[rank] = true;
        diagonal1Reserved[rank + file] = true;
        diagonal2Reserved[rank - file + boardSize - 1] = true;

        solve(file + 1);

        rankReserved[rank] = false;
        diagonal1Reserved[rank + file] = false;
        diagonal2Reserved[rank - file + boardSize - 1] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i = 0; i < boardSize; i++) {
        for(int j = 0; j < boardSize; j++) {
            char c;
            cin >> c;

            if(c == '*') tileReserved[i][j] = true;
        }
    }

    solve(0);
    cout << positions << "\n";
    return 0;
}