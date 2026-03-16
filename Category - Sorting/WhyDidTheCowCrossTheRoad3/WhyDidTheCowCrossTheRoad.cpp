// Aiden K Morris
// Problem: https://usaco.org/index.php?page=viewproblem2&cpid=713
// Tags: Sorting
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream read("cowqueue.in");
    ofstream write("cowqueue.out");

    int n;
    read >> n;

    vector<pair<int, int>> cows(n);

    for(pair<int, int> &p : cows) {
        read >> p.first >> p.second;
    }

    sort(cows.begin(), cows.end());

    int time = 0;

    for(const pair<int, int> &p : cows) {
        if(time > p.first) {
            time += p.second;
        } else {
            time = p.first + p.second;
        }
    }

    write << time << "\n";
    return 0;
}