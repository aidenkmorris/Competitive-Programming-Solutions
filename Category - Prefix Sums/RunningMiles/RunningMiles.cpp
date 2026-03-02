// Aiden K Morris
// Problem: https://codeforces.com/contest/1826/problem/D
// Tags: Prefix sums
#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
const ll INF = 1e18;

void solveCase() {
    int N;
    std::cin >> N;

    std::vector<ll> array(N);
    for(ll &a : array) std::cin >> a;

    std::vector<ll> prefixMax(N + 1);
    prefixMax[0] = 0;

    for(int i = 0; i < N; i++) {
        prefixMax[i + 1] = std::max(prefixMax[i], array[i] + i);
    }

    std::vector<ll> suffixMax(N + 1, -INF);

    for(int i = N - 1; i >= 0; i--) {
        suffixMax[i] = std::max(suffixMax[i + 1], array[i] - i);
    }

    ll bestBeautyScore = 0;

    for(int i = 0; i < N; i++) {
        bestBeautyScore = std::max(bestBeautyScore, prefixMax[i] + array[i] + suffixMax[i + 1]);
    }

    std::cout << bestBeautyScore << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int cases;
    std::cin >> cases;

    for(int i = 0; i < cases; i++) solveCase();
    return 0;
}