#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream read("breedflip.in");
    ofstream write("breedflip.out");

    int n;
    string a, b;
    read >> n >> a >> b;

    // Catches edge case in loop
    a += 'X';
    b += 'X';

    int flips = 0;
    
    for(int i = 0; i < n - 1; i++) {
        if(a[i] != b[i] && a[i + 1] == b[i + 1]) {
            flips++;
        }
    }

    write << flips << "\n";
    return 0;
}