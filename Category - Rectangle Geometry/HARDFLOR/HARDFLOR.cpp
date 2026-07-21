// Aiden K Morris
// Problem: https://open.kattis.com/problems/hardflor
// Tags: Rectangle Geometry
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    vector<pair<char, int>> directions(n);

    for(auto &d : directions) {
        string side;
        cin >> side;

        d.first = side[0];
        d.second = stoi(side.substr(1));
    }

    int area = 0;
    int height = 0;

    for(const auto d : directions) {
        if(d.first == 'N') {
            height += d.second;
        }
        else if(d.first == 'S') {
            height -= d.second;
        }
        else if(d.first == 'E') {
            area += height * d.second;
        }
        else { // d.first == 'W'
            area -= height * d.second;
        }
    }

    cout << "THE AREA IS " << abs(area) << "\n";
    return 0;
}