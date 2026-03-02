// Aiden K Morris
// Problem: https://codeforces.com/gym/102951/problem/B

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, x;
    std::cin >> n >> x;

    std::vector<int> minutesPer(n);

    for(int &m : minutesPer) {
        std::cin >> m;
    }

    std::sort(std::begin(minutesPer), std::end(minutesPer));

    int num = 0, totalMinutes = 0;

    for(int minutes : minutesPer) {
        if(totalMinutes + minutes >= x) break;

        totalMinutes += minutes;
        num++;
    }

    std::cout << num << "\n";
    return 0;
}