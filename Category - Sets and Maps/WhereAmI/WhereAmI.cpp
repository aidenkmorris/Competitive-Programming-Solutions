// Aiden K Morris
// Problem: https://usaco.org/index.php?page=viewproblem2&cpid=964
// Tags: Sets
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream read("whereami.in");
    ofstream write("whereami.out");

    int n;
    read >> n;

    string mailboxes;
    read >> mailboxes;

    for(int len = 1; len < mailboxes.length(); len++) {
        int target = mailboxes.length() + 1 - len;
        set<string> subsequences;

        for(int start = 0; start + len - 1 < mailboxes.length(); start++) {
            string subsequence = mailboxes.substr(start, len);
            subsequences.insert(subsequence);
        }

        if(subsequences.size() == target) {
            write << len << "\n";
            return 0;
        }
    }

    write << -1 << "\n";
    return 0;
}