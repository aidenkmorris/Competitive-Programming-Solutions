// Aiden K Morris
// Problem: https://cses.fi/problemset/task/1622
// Tags: Complete Search
#include <bits/stdc++.h>
using namespace std;

string input;
vector<string> permutations;
int chars[26];

void createStrings(string &builder) {
    if(builder.length() == input.length()) {
        permutations.push_back(builder);
    } else {
        for(int i = 0; i < 26; i++) {
            if(chars[i] != 0) {
                builder += 'a' + i;
                chars[i]--;
                createStrings(builder);
                chars[i]++;
                builder.pop_back();
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> input;
    
    for(char c : input) {
        chars[c - 'a']++;
    }

    string builder = "";
    createStrings(builder);

    cout << permutations.size() << "\n";

    for(string s : permutations) {
        cout << s << "\n";
    }
    
    return 0;
}