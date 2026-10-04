// Aiden K Morris
// Problem: https://naq26.kattis.com/contests/naq26/problems/airtime
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int secondsOfAirtime = 0;

    tuple<int, int, int> altitudes;
    cin >> get<1>(altitudes);
    cin >> get<2>(altitudes);

    for(int i = 2; i < n; i++) {
        get<0>(altitudes) = get<1>(altitudes);
        get<1>(altitudes) = get<2>(altitudes);
        cin >> get<2>(altitudes);
        
        int slope1 = (get<1>(altitudes) - get<0>(altitudes));
        int slope2 = (get<2>(altitudes) - get<1>(altitudes));

        if(slope1 > slope2) {
            secondsOfAirtime++;
        }
    }

    cout << secondsOfAirtime << "\n";
    return 0;
}