// Aiden K Morris
// Problem: https://usaco.org/index.php?page=viewproblem2&cpid=963
// Tags: Complete Search
#include <fstream>
#include <vector>
using namespace std;

int getIndex(const vector<int> v, const int e) {
    for(int i = 0; i < v.size(); i++) {
        if(v[i] == e) {
            return i;
        }
    }
    
    return -1;
}

int main() {
    int k, n;
    ifstream read("gymnastics.in");
    read >> k >> n;
    
    vector<vector<int>> rankings(k, vector<int>(n));

    for(int i = 0; i < k; i++) {
        for(int j = 0; j < n; j++) {
            read >> rankings[i][j];
        }
    }

    int consistentPairs = 0;

    for(int a = 1; a <= n; a++) {
        for(int b = 1; b <= n; b++) {
            if(a == b) continue;

            bool consistent = true;

            for(auto r : rankings) {
                if(getIndex(r, a) < getIndex(r, b)) {
                    consistent = false;
                    break;
                }
            }

            if(consistent) consistentPairs++;
        }
    }

    ofstream write("gymnastics.out");
    write << consistentPairs << "\n";
    return 0;
}