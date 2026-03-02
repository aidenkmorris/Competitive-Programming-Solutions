// Aiden K Morris
// Problem: https://usaco.org/index.php?page=viewproblem2&cpid=940
// Tags: Graphs, Trees, DFS
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

// Recursive depth-first-search
void dfs(int start, const std::vector<std::vector<int>> &graph, std::vector<bool> &visited) {
    visited[start] = true;

    for(int i : graph[start]) {
        if(!visited[i]) dfs(i, graph, visited);
    }
}

int main() {
    std::ifstream read("factory.in");
    std::ofstream out("factory.out");
    int n;
    read >> n;

    // Unused first but prevents adjusting indices
    std::vector<std::vector<int>> graph(n + 1);

    // Reversed graph to track paths
    for(int i = 0; i < n - 1; i++) {
        int from, to;
        read >> from >> to;
        graph[to].push_back(from);
    }

    // For each vertex...
    for(int i = 1; i <= n; i++) {
        // Keep track of visited vertices
        // Unused first but prevents adjusting indices
        std::vector<bool> visited(n + 1);

        // Peform depth-first-search on graph
        dfs(i, graph, visited);

        // Assume all vertices have been visited,
        // and if not, then continue iterating through vertices
        bool reachable = true;

        for(int j = 1; j <= n; j++) {
            if(!visited[j]) {
                reachable = false;
                break;
            }
        }

        // If all vertices have been visited,
        // then the current vertex is the answer
        if(reachable) {
            out << i;
            return 0;
        }
    }

    // No vertex found
    out << -1;
    return 0;
}