// Aiden K Morris
// Problem: https://usaco.org/index.php?page=viewproblem2&cpid=736
// Tags: Complete Search
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;

int main() {
    ifstream read("cownomics.in");
    int n, m;
    read >> n >> m;

    vector<string> spotty(n);
    vector<string> plain(n);

    for(string &s : spotty) {
        read >> s;
    }
    
    for(string &p : plain) {
        read >> p;
    }

    int locations = 0;

    for(int i = 0; i < m; i++) {
        set<char> spottyLetters;
        set<char> plainLetters;

        // Each letter at current index in all strings
        for(int s = 0; s < n; s++) {
            spottyLetters.insert(spotty[s][i]);
        }

        for(int p = 0; p < n; p++) {
            plainLetters.insert(plain[p][i]);
        }

        // Find intersection
        set<char> intersection;

        set_intersection(
            spottyLetters.begin(), spottyLetters.end(),
            plainLetters.begin(), plainLetters.end(),
            inserter(intersection, intersection.begin())
        );

        if(intersection.size() == 0) {
            locations++;
        }
    }

    ofstream write("cownomics.out");
    write << locations << "\n";
    return 0;
}