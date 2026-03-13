// Aiden K Morris
// Problem: https://usaco.org/index.php?page=viewproblem2&cpid=687
// Tags: Maps  
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
unordered_map<string, int> milk;

void initializeMilk() {
    const string cows[] = {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};

    for(const string &c : cows) {
        milk[c] = 0;
    }
}

int main() {
    ifstream read("notlast.in");
    ofstream write("notlast.out");
    initializeMilk();

    int n;
    read >> n;

    for(int i = 0; i < n; i++) {
        string c;
        read >> c;

        int value;
        read >> value;

        milk[c] += value;
    }

    int minimum = INF;

    for(const auto &m : milk) {
        minimum = min(minimum, m.second);
    }

    pair<string, int> secondMinimum = {"", INF};
    int cowsWithSecondMinimum = 0;

    for(const auto &m: milk) {
        if(m.second == minimum) {
            continue;
        } else if(m.second < secondMinimum.second) {
            secondMinimum = m;
            cowsWithSecondMinimum = 1;
        } else if(m.second == secondMinimum.second) {
            cowsWithSecondMinimum++;
        }
    }

    if(cowsWithSecondMinimum == 1) {
        write << secondMinimum.first << "\n";
    } else {
        write << "Tie\n";
    }

    return 0;
}