#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <utility>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> movies(n);

    for(std::pair<int, int> &m : movies) {
        std::cin >> m.second >> m.first;
    }

    std::sort(std::begin(movies), std::end(movies));

    int currentEnd = -1;
    int num = 0;

    for(int c = 0; c < n; c++) {
        if(movies[c].second >= currentEnd) {
            currentEnd = movies[c].first;
            num++;
        }
    }

    std::cout << num << "\n";
    return 0;
}