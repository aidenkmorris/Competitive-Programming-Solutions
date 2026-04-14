// Aiden K Morris
// Problem: https://www.hackerrank.com/contests/pacise-2026/challenges/exam-proctors
// Tags: Greedy Algorithms
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> exams(n);

    for(auto &e : exams) {
        string start, end;
        cin >> start >> end;

        e.first = 60 * stoi(start.substr(0, 2)) + stoi(start.substr(3, 2));
        e.second = 60 * stoi(end.substr(0, 2)) + stoi(end.substr(3, 2));
    }

    sort(exams.begin(), exams.end());

    int currentTime = 0;
    int proctors = 0;
    int available = 0;
    vector<int> endTimes;

    for(const auto e : exams) {
        for(int i = 0; i < endTimes.size(); i++) {
            if(endTimes[i] < e.first) {
                available++;
                endTimes.erase(endTimes.begin() + i);
                i--;
                continue;
            }
        }

        if(available > 0) {
            available--;
        } else {
            proctors++;
        }

        endTimes.push_back(e.second);
    }

    cout << proctors << endl;
    
    return 0;
}