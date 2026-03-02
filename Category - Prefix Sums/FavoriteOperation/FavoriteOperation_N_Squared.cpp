// Aiden K Morris
// Problem: https://usaco.org/index.php?page=viewproblem2&cpid=1471
// Tags: Prefix Sums
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using ll = long long;
const ll INF = 1e18;

void solve() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> a(N);

    for(int &e : a) {
        std::cin >> e;
        e %= M;
    }

    std::sort(a.begin(), a.end());

    ll answer = INF;

    for(int i = 0; i < N; i++) {
        int lower = N / 2;
        int upper = N - N / 2;

        ll sumLower = 0;

        for(int j = 0; j < lower; j++) {
            sumLower += a[j];
        }

        ll sumUpper = 0;

        for(int j = upper; j < N; j++) {
            sumUpper += a[j];
        }

        answer = std::min(answer, sumUpper - sumLower);

        int first = a[0];
        a.erase(a.begin());
        a.push_back(first + M);
    }

    std::cout << answer << "\n";
}

int main() {
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;

    for(int i = 0; i < T; i++) solve();
    return 0;
}