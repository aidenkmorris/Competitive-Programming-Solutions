// Aiden K Morris
// Problem: https://usaco.org/index.php?page=viewproblem2&cpid=739
// Tags: Complete Search
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>
#include <tuple>
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

    // For each tuple combination
    for(int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            for(int k = j + 1; k < m; k++) {
                set<tuple<char, char, char>> spottyTuples;
                set<tuple<char, char, char>> plainTuples;

                // For each cow
                for(int c = 0; c < n; c++) {
                    spottyTuples.insert(make_tuple(spotty[c][i], spotty[c][j], spotty[c][k]));
                    plainTuples.insert(make_tuple(plain[c][i], plain[c][j], plain[c][k]));
                }

                // Find intersection
                set<tuple<char, char, char>> intersection;

                set_intersection(
                    spottyTuples.begin(), spottyTuples.end(),
                    plainTuples.begin(), plainTuples.end(),
                    inserter(intersection, intersection.begin())
                );

                if(intersection.size() == 0) {
                    locations++;
                }

            }
        }
    }

    ofstream write("cownomics.out");
    write << locations << "\n";
    return 0;
}