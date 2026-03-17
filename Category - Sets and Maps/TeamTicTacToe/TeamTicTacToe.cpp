// Aiden K Morris
// Problem: https://usaco.org/index.php?page=viewproblem2&cpid=831
// Tags: Sets
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream read("tttt.in");
    ofstream write("tttt.out");

    vector<vector<char>> board(3, vector<char>(3));

    for(vector<char> &row : board) {
        for(char &cell : row) {
            read >> cell;
        }
    }

    set<set<char>> winConditions;

    // Horizontal wins
    for(int i = 0; i < 3; i++) {
        winConditions.insert({board[i][0], board[i][1], board[i][2]});
    }

    // Vertical wins
    for(int i = 0; i < 3; i++) {
        winConditions.insert({board[0][i], board[1][i], board[2][i]});
    }

    // Diagonal wins
    winConditions.insert({board[0][0], board[1][1], board[2][2]});
    winConditions.insert({board[0][2], board[1][1], board[2][0]});

    int countOne = 0;
    int countTwo = 0;

    for(set<char> s : winConditions) {
        if(s.size() == 1) {
            countOne++;
        } else if(s.size() == 2) {
            countTwo++;
        }
    }

    write << countOne << "\n" << countTwo << "\n";
}