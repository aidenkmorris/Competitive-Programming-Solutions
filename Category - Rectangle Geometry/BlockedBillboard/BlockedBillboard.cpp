// Aiden K Morris
// Problem: https://usaco.org/index.php?page=viewproblem2&cpid=759
// Tags: Rectangle Geometry
#include <bits/stdc++.h>
using namespace std;

struct Rectangle {
    int x1, y1, x2, y2;

    int area() {
        return abs(x2 - x1) * abs(y2 - y1);
    }
};

int intersectionArea(Rectangle r1, Rectangle r2) {
    // Intersection of two ranges is the minimum end - maximum start    
    // Clamp to 0 in case there is no overlap (which is negative)
    int intersectionX = max(min(r1.x2, r2.x2) - max(r1.x1, r2.x1), 0);
    int intersectionY = max(min(r1.y2, r2.y2) - max(r1.y1, r2.y1), 0);

    return intersectionX * intersectionY;
}

int main() {
    ifstream read("billboard.in");
    ofstream write("billboard.out");

    Rectangle billboard1, billboard2, truck;

    read >> billboard1.x1 >> billboard1.y1 >> billboard1.x2 >> billboard1.y2;
    read >> billboard2.x1 >> billboard2.y1 >> billboard2.x2 >> billboard2.y2;
    read >> truck.x1 >> truck.y1 >> truck.x2 >> truck.y2;
    
    int visibleArea = billboard1.area() + billboard2.area() 
        - intersectionArea(billboard1, truck) - intersectionArea(billboard2, truck);

    write << visibleArea << "\n";
    return 0;
}