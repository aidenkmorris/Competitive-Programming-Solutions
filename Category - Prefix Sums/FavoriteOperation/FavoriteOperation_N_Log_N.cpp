// Aiden K Morris
// Problem: https://usaco.org/index.php?page=viewproblem2&cpid=1471
// Tags: Prefix Sums
#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
const int INF = 1e9;

void solve() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> a(2 * N);

    for(int i = 0; i < N; i++) {
        std::cin >> a[i];
        a[i + N] = a[i] + M;
    }

    std::vector<ll> prefix(2 * N + 1);

    for(int i = 0; i < 2 * N; i++) {
        prefix[i + 1] = prefix[i] + a[i];
    }

    ll answer = INF;

    for(int i = 0; i < N; i++) {
        int lower = N / 2;
        int upper = N - N / 2;

        ll sumLower = prefix[i + lower] - prefix[i];
        ll sumUpper = prefix[i + N] - prefix[upper];

        answer = std::min(answer, sumUpper - sumLower);
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