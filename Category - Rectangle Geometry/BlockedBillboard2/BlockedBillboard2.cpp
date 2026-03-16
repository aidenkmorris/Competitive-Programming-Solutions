// Aiden K Morris
// Problem: https://usaco.org/index.php?page=viewproblem2&cpid=783
// Tags: Rectangle Geometry
#include <bits/stdc++.h>
using namespace std;

struct Rectangle {
    int x1, y1, x2, y2;

    int length() {
        return x2 - x1;
    }

    int width() {
        return y2 - y1;
    }

    int area() {
        return length() * width();
    }
};

int main() {
    ifstream read("billboard.in");
    ofstream write("billboard.out");

    Rectangle cowFeed, lawnMower;

    read >> lawnMower.x1 >> lawnMower.y1 >> lawnMower.x2 >> lawnMower.y2;
    read >> cowFeed.x1 >> cowFeed.y1 >> cowFeed.x2 >> cowFeed.y2;

    int overlapX = max(min(lawnMower.x2, cowFeed.x2) - max(lawnMower.x1, cowFeed.x1), 0);
    int overlapY = max(min(lawnMower.y2, cowFeed.y2) - max(lawnMower.y1, cowFeed.y1), 0);

    int coverX = lawnMower.length();
    int coverY = lawnMower.width(); 

    // If the entire length overlaps and the edge of the lawn 
    // mower billboard is within the cow feed billboard...
    if(overlapX == lawnMower.length() && (lawnMower.y1 >= cowFeed.y1 || lawnMower.y2 <= cowFeed.y2)) { 
        coverY = lawnMower.width() - overlapY;
    } 
    
    // If the entire width overlaps and the edge of the lawn 
    // mower billboard is within the cow feed billboard...
    if(overlapY == lawnMower.width() && (lawnMower.x1 >= cowFeed.x1 || lawnMower.x2 <= cowFeed.x2)) {
        coverX = lawnMower.length() - overlapX;
    }

    write << coverX * coverY << "\n";
    return 0;
}