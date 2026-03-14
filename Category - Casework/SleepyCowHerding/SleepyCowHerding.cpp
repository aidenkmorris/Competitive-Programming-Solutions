// Aiden K Morris
// Problem: https://usaco.org/index.php?page=viewproblem2&cpid=915
// Tags: Casework
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream read("herding.in");
    ofstream write("herding.out");

    tuple<int, int, int> locations;
    read >> get<0>(locations) >> get<1>(locations) >> get<2>(locations);

    // Minimum
    int minimum;

    if(get<1>(locations) - get<0>(locations) == 1 && get<2>(locations) - get<1>(locations) == 1) {
        minimum = 0;
    } else if(get<1>(locations) - get<0>(locations) == 2 || get<2>(locations) - get<1>(locations) == 2) {
        minimum = 1;
    } else {
        minimum = 2;
    }

    // Maximum
    int maximum = max(get<1>(locations) - get<0>(locations), get<2>(locations) - get<1>(locations)) - 1;
    
    write << minimum << "\n" << maximum << "\n";
    return 0;
}