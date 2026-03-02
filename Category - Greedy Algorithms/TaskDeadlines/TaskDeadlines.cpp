// Aiden K Morris
// Problem: https://cses.fi/problemset/result/16052618/

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <utility>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> tasks(n);

    for(std::pair<int, int> &t : tasks) {
        // t.second is the duration
        // t.first is the deadline
        // so sorts by deadline
        std::cin >> t.first >> t.second;
    }

    std::sort(std::begin(tasks), std::end(tasks));

    long long currentTime = 0;
    long long reward = 0;

    for(int c = 0; c < n; c++) {
        currentTime += tasks[c].first;
        reward += (tasks[c].second - currentTime);
    }

    std::cout << reward << "\n";
    return 0;
}