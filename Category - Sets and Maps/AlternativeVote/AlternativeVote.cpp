// Aiden K Morris
// Problem: https://www.hackerrank.com/contests/pacise-2026/challenges/alternative-vote
// Tags: Sets, Maps
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cin.ignore();

    vector<vector<string>> ballots(n);
    unordered_set<string> names;

    // Input
    for(int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        
        stringstream ss(line);
        string name;

        names.insert(name);

        while(ss >> name) {
            ballots[i].push_back(name);
        }
    }

    unordered_set<string> remaining;

    while(true) {
        unordered_map<string, int> firstPlaces;

        // Count first places
        for(int i = 0; i < n; i++) {
            if(!ballots[i].empty()) {
                firstPlaces[ballots[i][0]]++;
            }
        }

        pair<string, int> minimum = {"", INT_MAX};

        for(auto name : firstPlaces) {
            // Check vote count
            if(name.second < minimum.second) {
                minimum = name;
            } 
            // Keep lexicographically in case of tie
            else if(name.second == minimum.second && name.first < minimum.first) {
                minimum = name;
            }
        }

        for(int i = 0; i < n; i++) {
            int it = -1;

            for(int j = 0; j < ballots[i].size(); j++) {
                if(ballots[i][j] == minimum.first) {
                    it = j;
                    break;
                }
            }

            if(it == -1) {
                continue;
            } else {   
                ballots[i].erase(ballots[i].begin() + it);
            }
        }

        remaining = {};

        for(int i = 0; i < ballots.size(); i++) {
            for(int j = 0; j < ballots[i].size(); j++) {
                remaining.insert(ballots[i][j]);
            }
        }

        if(remaining.size() == 1) {
            break;
        }
    }

    // Remaining is a set
    for(auto r : remaining) {
        cout << r << endl;
    }
}