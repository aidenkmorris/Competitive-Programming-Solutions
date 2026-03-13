// Aiden K Morris
// Problem: https://cses.fi/problemset/task/1621
// Tags: Sorting
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> values(n);

    for(int &v : values) {
        cin >> v;
    }

    sort(values.begin(), values.end());
    values.resize(unique(values.begin(), values.end()) - values.begin());

    cout << values.size() << "\n";
    return 0;
}