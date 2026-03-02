// Aiden K Morris, translated from USACO Guide
// Problem: https://usaco.org/index.php?page=viewproblem2&cpid=965
// Tags: Graphs
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

int main() {
    // Sort cows alphabetically using lamdba function for style points
    const std::vector<std::string> cows = []() {
        std::vector<std::string> temp = {"Bessie", "Buttercup", "Belinda",
            "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
        
        std::sort(std::begin(temp), std::end(temp));
        return temp;
    }();

    // Assign each cow's name to its index as nodes for the graph
    std::map<std::string, int> indexOfCows;
    for(int i = 0; i < cows.size(); i++) indexOfCows[cows[i]] = i;

    std::ifstream read("lineup.in");
    
    // Number of connections between nodes
    int edges;
    read >> edges;

    // List of connected nodes (cows)
    std::vector<std::vector<int>> neighbors(cows.size());

    for(int e = 0; e < edges; e++) {
        // Read the adjacent cows discarding flavor text
        std::string cow1, cow2, discard;
        read >> cow1 >> discard >> discard >> discard >> discard >> cow2;

        // Push the node indices to the list of connected nodes
        int c1 = indexOfCows[cow1];
        int c2 = indexOfCows[cow2];
        neighbors[c1].push_back(c2);
        neighbors[c2].push_back(c1);
    }

    // Lists of correct lineup and whether any given cow has been added
    std::vector<int> lineup;
    std::vector<bool> cowAdded(cows.size());

    // With the inside conditional statement, this
    // effecively means "for each component of the graph"
    for(int c = 0; c < cows.size(); c++) {
        // If the cow has not already been added
        // and has 1 or 0 neighbors (isolated or end)
        if(!cowAdded[c] && neighbors[c].size() <= 1) {
            cowAdded[c] = true;
            lineup.push_back(c);

            // If the cow has a neighbor, traverse the entire component
            if(neighbors[c].size() == 1) {
                // Start by traversing to the neighbor
                int prev = c;
                int cur = neighbors[c][0];

                // If the cow is in the middle of the path
                while(neighbors[cur].size() == 2) {
                    cowAdded[cur] = true;
                    lineup.push_back(cur);

                    // Traverse to the unvisited neighbor
                    int neighbor1 = neighbors[cur][0];
                    int neighbor2 = neighbors[cur][1];
                    int temp_cur = (neighbor1 == prev ? neighbor2 : neighbor1);
                    prev = cur;
                    cur = temp_cur;
                }

                // Add the final cow to the lineup
                cowAdded[cur] = true;
                lineup.push_back(cur);
            }
        }
    }

    std::ofstream out("lineup.out");
    for(int c : lineup) out << cows[c] <<  "\n";
}