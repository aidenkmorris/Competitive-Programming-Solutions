// Aiden K Morris
// Problem: https://judge.yosupo.jp/problem/static_range_sum
// Tags: Prefix sums
#include <iostream>
#include <vector>

using ll = long long;

std::vector<ll> prefixSum(std::vector<ll> sequence) {
    std::vector<ll> prefix(sequence.size() + 1);

    for(int i = 0; i < sequence.size(); i++) {
        prefix[i + 1] = prefix[i] + sequence[i];
    }

    return prefix;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, Q;
    std::cin >> N >> Q;

    std::vector<ll> sequence(N);
    for(ll &a : sequence) std::cin >> a;

    auto pSequence = prefixSum(sequence);

    for(int i = 0; i < Q; i++) {
        int l, r;
        std::cin >> l >> r;
        std::cout << pSequence[r] - pSequence[l] << "\n";
    }
}