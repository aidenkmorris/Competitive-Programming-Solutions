#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream read("breedflip.in");
    ofstream write("breedflip.out");

    int n;
    string a, b;
    read >> n >> a >> b;

    int flips = 0;
    int start = 0;

    while(start < n - 1) {
        if(a[start] == b[start]) {
            start++;
            continue;
        }

        int end = start + 1;

        while(a[end] != b[end]) {
            end++;
        }

        for(int i = start; i < end; i++) {
            if(b[i] == 'H') {
                b[i] = 'G';
            } else {
                b[i] = 'H';
            }
        }

        flips++;
    }

    write << flips << "\n";
    return 0;
}