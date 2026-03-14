// Aiden K Morris
// Problem: https://usaco.org/index.php?page=viewproblem2&cpid=567
// Tags: Casework
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream read("paint.in");
    ofstream write("paint.out");
    
    pair<int, int> farmer, cow;
    read >> farmer.first >> farmer.second;
    read >> cow.first >> cow.second;

    int length;
    
    // Farmer within cow
    if(farmer.first >= cow.first && farmer.second <= cow.second) {
        length = cow.second - cow.first;
    }
    // Cow within farmer
    else if(cow.first >= farmer.first && cow.second <= farmer.second) {
        length = farmer.second - farmer.first;
    }
    // Cow then farmer
    else if(cow.first <= farmer.first && cow.second >= farmer.first) {
        length = farmer.second - cow.first;
    }
    // Farmer then cow
    else if(farmer.first <= cow.first && farmer.second >= cow.first) {
        length = cow.second - farmer.first;
    }
    // No overlap
    else {
        length = (farmer.second - farmer.first) + (cow.second - cow.first);
    }

    write << length << "\n";
    return 0;
}